#ifndef ENTRY_POINT_H
#define ENTRY_POINT_H

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

namespace ly
{
	class Application;
}

extern ly::Application* GetApplication();

#endif