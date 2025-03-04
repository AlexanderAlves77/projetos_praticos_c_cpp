/**********************************************************************************
* Filename    : Main (Header File)
* Author      : Alexander Alves
* Created     : Jan 01 2022
* Update      : Jan 01 2022
* Compiler    : Visual C++ 2022
* Description : 
*
**********************************************************************************/

#include <iostream>
#include <windows.h>
#include <windowsx.h>


LRESULT CALLBACK WinProc(HWND, UINT, WPARAM, LPARAM);

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
        WS_OVERLAPPEDWINDOW|WS_VISIBLE,        
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
        OutputDebugStringA("WM_SIZE\n");
    } break;
    case WM_DESTROY:
    {
        OutputDebugStringA("WM_DESTROY\n");
    } break;
    case WM_CLOSE:
    {
        OutputDebugStringA("WM_CLOSE\n");
    } break;
    case WM_ACTIVATEAPP:
    {
        OutputDebugStringA("WM_ACTIVATEAPP\n");
    } break;
    case WM_PAINT:
    {
        PAINTSTRUCT Paint;
        HDC DeviceContext = BeginPaint( Window, & Paint );
        int X = Paint.rcPaint.left;
        int Y = Paint.rcPaint.top;
        int Width = Paint.rcPaint.right - Paint.rcPaint.left;
        int Height = Paint.rcPaint.bottom - Paint.rcPaint.top;
        static DWORD Operation = WHITENESS;
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