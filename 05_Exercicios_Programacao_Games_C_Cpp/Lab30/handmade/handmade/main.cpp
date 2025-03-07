/**********************************************************************************
* Filename    : Main (Header File)
* Author      : Alexander Alves
* Created     : Jan 01 2022
* Update      : Jan 01 2022
* Compiler    : Visual C++ 2022
* Description : Introduction to games 
*
**********************************************************************************/

#include <iostream>
#include <windows.h>
#include <stdint.h>
#include <windowsx.h>
#include <xinput.h>

#define internal static;
#define local_persist static
#define global_variable static

typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;

typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

global_variable bool GlobalRunning;


struct win32_offscreen_buffer
{
    BITMAPINFO Info;
    void * Memory;
    int Width;
    int Height;
    int Pitch;
    int BytesPerPixel;
};

global_variable HBITMAP BitmapHandle;
global_variable HDC BitmapDeviceContext;
global_variable win32_offscreen_buffer GlobalBackBuffer;

struct win32_window_dimension
{
    int Width;
    int Height;
};

#define X_INPUT_GET_STATE(name) DWORD WINAPI name(DWORD dwUserIndex, XINPUT_STATE * pState);
typedef X_INPUT_GET_STATE(x_input_get_state);
X_INPUT_GET_STATE(XInputGetStateStub)
{
    return 0;
}

#define X_INPUT_SET_STATE(name) DWORD WINAPI name(DWORD dwUserIndex, XINPUT_VIBRATION * pVibration);
typedef X_INPUT_SET_STATE(x_input_set_state);
X_INPUT_SET_STATE(XInputGetStateStub)
{
    return 0;
}

global_variable x_input_get_state * XInputGetState_ = XInputGetStateStub;
global_variable x_input_set_state * XInputSetState_ = XInputGetStateStub;

#define XInputGetState XInputGetState_;
#define XInputSetState XInputSetState_;

win32_window_dimension GetWindowDimension(HWND Window)
{
    win32_window_dimension Result;

    RECT ClientRect;
    GetClientRect(Window, &ClientRect);
    Result.Width = ClientRect.right - ClientRect.left;
    Result.Height = ClientRect.bottom - ClientRect.top;

    return Result;
}


LRESULT CALLBACK WinProc(HWND, UINT, WPARAM, LPARAM);

internal void RenderWeirdGradient(win32_offscreen_buffer * Buffer, int BlueOffset, int GreenOffset)
{
    uint8* Row = (uint8*)Buffer->Memory;

    for (int Y = 0; Y < Buffer->Height; ++Y)
    {
        uint32* Pixel = (uint32*)Row;
        for (int X = 0; X < Buffer->Width; ++X)
        {
            uint8 Blue = (X + BlueOffset);
            uint8 Green = (Y + GreenOffset);
            *Pixel++ = ((Green << 8) | Blue);
        }
        Row += Buffer->Pitch;
    }
}

internal void  Win32ResizeDIBSection(win32_offscreen_buffer * Buffer, int Width, int Height)
{
    if (Buffer->Memory)
    {
        VirtualFree(Buffer->Memory, 0, MEM_RELEASE);
    }

    Buffer->Width = Width;
    Buffer->Height = Height;
    Buffer->BytesPerPixel = 4;
    
    Buffer->Info.bmiHeader.biSize = sizeof(Buffer->Info.bmiHeader);
    Buffer->Info.bmiHeader.biWidth = Buffer->Width;
    Buffer->Info.bmiHeader.biHeight = -Buffer->Height;
    Buffer->Info.bmiHeader.biPlanes = 1;
    Buffer->Info.bmiHeader.biBitCount = 32;
    Buffer->Info.bmiHeader.biCompression = BI_RGB;
    Buffer->Info.bmiHeader.biSizeImage = 0;
    Buffer->Info.bmiHeader.biXPelsPerMeter = 0;
    Buffer->Info.bmiHeader.biClrUsed = 0;
    Buffer->Info.bmiHeader.biClrImportant = 0;

    int BitmapMemorySize = (Buffer->Width * Buffer->Height) * Buffer->BytesPerPixel;
    Buffer->Memory = VirtualAlloc(0, BitmapMemorySize, MEM_COMMIT, PAGE_READWRITE);
    Buffer->Pitch = Width * Buffer->BytesPerPixel;
}

internal void Win32DisplayBufferInWindow(HDC DeviceContext, int WindowWidth, int WindowHeight, 
        win32_offscreen_buffer * Buffer, int X, int Y, int Width, int Height)
{
    StretchDIBits(DeviceContext, 
        /*X, Y, Width, Height, X, Y, Width, Height,*/
        0, 0, WindowWidth, WindowHeight,
        0, 0, Buffer->Width, Buffer->Height,
        Buffer->Memory,
        &Buffer->Info,
        DIB_RGB_COLORS, SRCCOPY);
}

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hInstPrev, _In_ LPSTR cmdline, _In_ int cmdShow)
{
    HWND WindowHandle;         // window identifier
    MSG msg;                   // message
    WNDCLASS WindowClass = {}; // window class

    Win32ResizeDIBSection(&GlobalBackBuffer, 1280, 720);

    // Defining a window class called "BasicWindow"
    WindowClass.style = CS_HREDRAW | CS_VREDRAW;
    WindowClass.lpfnWndProc = WinProc;
    WindowClass.cbClsExtra = 0;
    WindowClass.cbWndExtra = 0;
    WindowClass.hInstance = hInstance;
    WindowClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    WindowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    WindowClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    WindowClass.lpszMenuName = NULL;
    WindowClass.lpszClassName = "HandemadeHeroWindowClass";

    // Registering the "HandemadeHeroWindowClass" class
    if (RegisterClassA(&WindowClass))
    {
        // Creating a window based on the class "HandemadeHeroWindowClass"
        HWND Window = CreateWindowEx(
            0,
            WindowClass.lpszClassName,
            "Handemade Hero",
            WS_OVERLAPPEDWINDOW | WS_VISIBLE,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            NULL,
            NULL,
            hInstance,
            NULL);

        if (Window)
        {
            HDC DeviceContext = GetDC(Window);
            GlobalRunning = true;
            int XOffset = 0;
            int YOffset = 0;

            while (GlobalRunning)
            {                
                while(PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
                {
                    if (msg.message == WM_QUIT)
                    {
                        GlobalRunning = false;
                    }

                    TranslateMessage(&msg);
                    DispatchMessage(&msg);
                }

                for (DWORD ControllerIndex = 0; ControllerIndex < XUSER_MAX_COUNT; ++ControllerIndex)
                {
                    XINPUT_STATE ControllerState;
                    if (XInputGetState(ControllerIndex, &ControllerState) == ERROR_SUCCESS)
                    {
                        XINPUT_GAMEPAD * Pad = &ControllerState.Gamepad;
                        bool Up = (Pad->wButtons & XINPUT_GAMEPAD_DPAD_UP);
                        bool Down = (Pad->wButtons & XINPUT_GAMEPAD_DPAD_DOWN);
                        bool Left = (Pad->wButtons & XINPUT_GAMEPAD_DPAD_LEFT);
                        bool Right = (Pad->wButtons & XINPUT_GAMEPAD_DPAD_RIGHT);
                        bool Start = (Pad->wButtons & XINPUT_GAMEPAD_START);
                        bool Back = (Pad->wButtons & XINPUT_GAMEPAD_BACK);
                        bool LeftShoulder = (Pad->wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER);
                        bool RightShoulder = (Pad->wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER);
                        bool AButton = (Pad->wButtons & XINPUT_GAMEPAD_A);
                        bool BButton = (Pad->wButtons & XINPUT_GAMEPAD_B);
                        bool xButton = (Pad->wButtons & XINPUT_GAMEPAD_X);
                        bool YButton = (Pad->wButtons & XINPUT_GAMEPAD_Y);

                        int16 StickX = Pad->sThumbLX;
                        int16 StickY = Pad->sThumbLY;
                    }
                    else
                    {

                    }
                }

                RenderWeirdGradient(&GlobalBackBuffer, XOffset, YOffset);                
                win32_window_dimension Dimension = GetWindowDimension(Window);
                Win32DisplayBufferInWindow(DeviceContext, Dimension.Width, Dimension.Height, 
                    &GlobalBackBuffer, 0, 0, Dimension.Width, Dimension.Height);
                ReleaseDC(Window, DeviceContext);

                ++XOffset;
            }
        }
    }  
    return 0;
}


LRESULT CALLBACK WinProc(HWND Window, UINT Message, WPARAM WParam, LPARAM LParam)
{
    switch (Message)
    {
    case WM_SIZE:    
    {
        
    } break;    
    case WM_CLOSE:
    {
        GlobalRunning = false;
        PostQuitMessage(0);
        OutputDebugStringA("WM_CLOSE\n");
    } break;
    case WM_ACTIVATEAPP:
    {
        OutputDebugStringA("WM_ACTIVATEAPP\n");
    } break;
    case WM_DESTROY:
    {
        GlobalRunning = false;
        OutputDebugStringA("WM_DESTROY\n");
    } break;
    case WM_PAINT:
    {
        PAINTSTRUCT Paint;
        HDC DeviceContext = BeginPaint(Window, &Paint);
        int X = Paint.rcPaint.left;
        int Y = Paint.rcPaint.top;
        int Width = Paint.rcPaint.right - Paint.rcPaint.left;
        int Height = Paint.rcPaint.bottom - Paint.rcPaint.top;

        win32_window_dimension Dimension = GetWindowDimension(Window);
        Win32DisplayBufferInWindow(DeviceContext, Dimension.Width, Dimension.Height,
                &GlobalBackBuffer, X, Y, Width, Height);
        EndPaint(Window, &Paint);
    } break;
    default:
    {
        OutputDebugStringA("default\n");
    } break;
    }
    return DefWindowProc(Window, Message, WParam, LParam);
}
