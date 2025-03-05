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
#include <windowsx.h>

#define local_persist static
#define global_variable static

global_variable bool Running;
global_variable BITMAPINFO BitmapInfo;
global_variable void * BitmapMemory;
global_variable HBITMAP BitmapHandle;
global_variable HDC BitmapDeviceContext;
global_variable int BitmapWidth;
global_variable int BitmapHeight;

LRESULT CALLBACK WinProc(HWND, UINT, WPARAM, LPARAM);

void Win32ResizeDIBSection(int Width, int Height)
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

    int BytesPerPixel = 4;
    int BitmapMemorySize = (BitmapWidth * BitmapHeight) * BytesPerPixel;
    BitmapMemory = VirtualAlloc(0, BitmapMemorySize, MEM_COMMIT, PAGE_READWRITE);

    /*
    BitmapHandle = CreateDIBSection(
        BitmapDeviceContext,
        &BitmapInfo,
        DIB_RGB_COLORS,
        &BitmapMemory,
        0, 0);  */
}

void Win32UpdateWindow(HDC DeviceContext, RECT * WindowRect, int X, int Y, int Width, int Height)
{
    int WindowWidth = WindowRect->right - WindowRect->left;
    int WindowHeight = WindowRect->bottom - WindowRect->top;

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
    if (!RegisterClass(&WindowClass))
    {
        MessageBox(NULL, "Error creating window!", "Aplication", MB_ICONERROR);
        return 0;
    }

    // Creating a window based on the class "HandemadeHeroWindowClass"
    WindowHandle = CreateWindowEx(
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

    // Show and update the window
    ShowWindow(WindowHandle, cmdShow);
    UpdateWindow(WindowHandle);

    // Handling messages destined for the application window
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return int(msg.wParam);
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
        Win32UpdateWindow(DeviceContext, X, Y, Width, Height);
        local_persist DWORD Operation = WHITENESS;
        PatBlt(DeviceContext, X, Y, Width, Height, Operation);
        if (Operation == WHITENESS)
        {
            Operation = BLACKNESS;
        }
        else
        {
            Operation = WHITENESS;
        }
        EndPaint(Window, &Paint);
    } break;
    default:
    {
        OutputDebugStringA("default\n");
    } break;
    }
    return DefWindowProc(Window, Message, WParam, LParam);
}
