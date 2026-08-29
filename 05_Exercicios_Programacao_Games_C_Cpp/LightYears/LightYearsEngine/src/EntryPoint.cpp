#include "EntryPoint.h"
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "framework/Application.h"
using namespace std;

int main(int argc, char* argv[])
{
	ly::Application* app = GetApplication();
	app->Run();
	delete app;
}