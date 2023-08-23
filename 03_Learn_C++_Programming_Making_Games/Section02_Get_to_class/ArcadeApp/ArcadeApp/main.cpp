/**********************************************************************************************
* Name            : ArcadeApp.cpp
* Author          : Alexander Alves
* Version         : 0.0.1
* Copyright       : 
* Description     : Hello World in C++, Ansi-style
* 
**********************************************************************************************/

#include <iostream>
using namespace std;

class Point2D
{
private:
	int mX;
	int mY;
	void MyPrivateMethod();

public:
	void SetX(int x);
	void SetY(int y);
	int GetX();
	int GetY();
	void Display();
};

void Point2D::SetX(int x) { mX = x; }
void Point2D::SetY(int y) { mY = y; }
int Point2D::GetX() { return mX; }
int Point2D::GetY() { return mY; }

void Point2D::Display()
{
	cout << "X: " << mX << ", Y: " << mY << endl;
}

int main(int argc, const char argv[])
{
	Point2D myPoint;
	myPoint.SetX(0);
	cout << "Size of myPoint is: " << sizeof(myPoint) << endl;

	cout << endl;
	system("Pause");
	return 0;
}