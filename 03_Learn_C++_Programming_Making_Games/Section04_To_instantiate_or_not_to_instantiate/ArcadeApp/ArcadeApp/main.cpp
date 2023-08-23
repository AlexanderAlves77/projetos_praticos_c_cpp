/**********************************************************************************************
* Name            : ArcadeApp.cpp
* Author          : Alexander Alves
* Date            : 08/23/2023
* Version         : 0.0.1
* Copyright       : 
* Update          : 08/23/2023
* Description     : Instantiate or not to instantiate Class in C++
* 
**********************************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Point2D
{
private:
	int mX;
	int mY;

public:
	Point2D();
	Point2D(int x, int y);
	~Point2D();
	void SetX(int x);
	void SetY(int y);
	int GetX();
	int GetY();
	void Display();
};

Point2D::Point2D():mX(0), mY(0) { /* more code here */ }

Point2D::Point2D(int x, int y):mX(x), mY(y) 
{  
	Display();
	this->Display();   // does the same thing
	mX = 0; 
	this->mX = 0;      // does the same thing as above
}

Point2D::~Point2D() { cout << "Destroyning: Point2D" << endl; }
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
	Point2D Point{10, 20};
	cout << "Size of myPoint is: " << sizeof(Point) << endl;
	Point.Display();

	Point2D* myPoint = new Point2D();
	myPoint->Display();

	(*myPoint).Display();

	cout << endl;
	system("Pause");
	return 0;
}