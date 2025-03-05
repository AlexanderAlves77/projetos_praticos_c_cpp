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

global_variable bool Running;
global_variable BITMAPINFO BitmapInfo;
global_variable void * BitmapMemory;
global_variable HBITMAP BitmapHandle;
global_variable HDC BitmapDeviceContext;
global_variable int BitmapWidth;
global_variable int BitmapHeight;
global_variable int BytesPerPixel = 4;

LRESULT CALLBACK WinProc(HWND, UINT, WPARAM, LPARAM);

internal void RenderWeirdGradient(int XOffset, int YOffset)
{
    int Width = BitmapWidth;
    int Height = BitmapHeight;

    int Pitch = Width * BytesPerPixel;
    uint8* Row = (uint8*)BitmapMemory;

    for (int Y = 0; Y < BitmapHeight; ++Y)
    {
        uint32* Pixel = (uint32*)Row;
        for (int X = 0; X < BitmapWidth; ++X)
        {
            uint8 Blue = (X + XOffset);
            uint8 Green = (Y + YOffset);
            *Pixel++ = ((Green << 8) | Blue);
        }
        Row += Pitch;
    }
}

internal void Win32ResizeDIBSection(int Width, int Height)
{
    if (BitmapMemory)
    {
        VirtualFree(BitmapMemory, 0, MEM_RELEASE);
    }

    BitmapWidth = Width;
    BitmapHeight = Height;
    
    BitmapInfo.bmiHeader.biSize = sizeof(BitmapInfo.bmiHeader);
    BitmapInfo.bmiHeader.biWidth = BitmapWidth;
    BitmapInfo.bmiHeader.biHeight = BitmapHeight;
    BitmapInfo.bmiHeader.biPlanes = 1;
    BitmapInfo.bmiHeader.biBitCount = 32;
    BitmapInfo.bmiHeader.biCompression = BI_RGB;
    BitmapInfo.bmiHeader.biSizeImage = 0;
    BitmapInfo.bmiHeader.biXPelsPerMeter = 0;
    BitmapInfo.bmiHeader.biClrUsed = 0;
    BitmapInfo.bmiHeader.biClrImportant = 0;

    int BitmapMemorySize = (BitmapWidth * BitmapHeight) * BytesPerPixel;
    BitmapMemory = VirtualAlloc(0, BitmapMemorySize, MEM_COMMIT, PAGE_READWRITE);
}

internal void Win32UpdateWindow(HDC DeviceContext, RECT * ClientRect, int X, int Y, int Width, int Height)
{
    int WindowWidth = ClientRect->right - ClientRect->left;
    int WindowHeight = ClientRect->bottom - ClientRect->top;

    StretchDIBits(DeviceContext, 
        /*X, Y, Width, Height, X, Y, Width, Height,*/
        0, 0, BitmapWidth, BitmapHeight,
        0, 0, WindowWidth, WindowHeight,
        BitmapMemory,
        &BitmapInfo,
        DIB_RGB_COLORS, SRCCOPY);
}

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hInstPrev, _In_ LPSTR cmdline, _In_ int cmdShow)
{
    HWND WindowHandle;         // window identifier
    MSG msg;                   // message
    WNDCLASS WindowClass = {}; // window class

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
            int XOffset = 0;
            int YOffset = 0;
            Running = true;

            while (Running)
            {                
                while(PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
                {
                    if (msg.message == WM_QUIT)
                    {
                        Running = false;
                    }

                    TranslateMessage(&msg);
                    DispatchMessage(&msg);
                }

                RenderWeirdGradient(XOffset, YOffset);
                HDC DeviceContext = GetDC(Window);
                RECT ClientRect;
                GetClientRect(Window, &ClientRect);
                int WindowWidth = ClientRect.right - ClientRect.left;
                int WindowHeight = ClientRect.bottom - ClientRect.top;
                Win32UpdateWindow(DeviceContext, &ClientRect, 0, 0, WindowWidth, WindowHeight);
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
        RECT ClientRect;        
        GetClientRect(Window, &ClientRect);
        int Width = ClientRect.right - ClientRect.left;
        int Height = ClientRect.bottom - ClientRect.top;
        Win32ResizeDIBSection(Width, Height);
    } break;    
    case WM_CLOSE:
    {
        Running = false;
        PostQuitMessage(0);
        OutputDebugStringA("WM_CLOSE\n");
    } break;
    case WM_ACTIVATEAPP:
    {
        OutputDebugStringA("WM_ACTIVATEAPP\n");
    } break;
    case WM_DESTROY:
    {
        Running = false;
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

        RECT ClientRect;
        GetClientRect(Window, &ClientRect);

        Win32UpdateWindow(DeviceContext, &ClientRect, X, Y, Width, Height);
        EndPaint(Window, &Paint);
    } break;
    default:
    {
        OutputDebugStringA("default\n");
    } break;
    }
    return DefWindowProc(Window, Message, WParam, LParam);
}
