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

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, LPSTR cmdline, int cmdshow)
{
    MessageBox(0, "This is Handmade Hero.", "Handmade Hero", MB_OK|MB_ICONINFORMATION);
    return 0;
}