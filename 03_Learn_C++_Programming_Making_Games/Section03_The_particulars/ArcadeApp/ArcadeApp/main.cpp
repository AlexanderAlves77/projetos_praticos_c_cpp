/**********************************************************************************************
* Name            : ArcadeApp.cpp
* Author          : Alexander Alves
* Version         : 0.0.1
* Copyright       : 
* Description     : Review of Class in C++
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
	Point2D();
	Point2D(int x, int y);
	~Point2D();
	void SetX(int x);
	void SetY(int y);
	int GetX();
	int GetY();
	void Display();

	Point2D& RefOurselves();
	Point2D* PointerOurselves();
};

Point2D::Point2D():mX(0), mY(0) { /* more code here */ }

Point2D::Point2D(int x, int y):mX(x), mY(y) 
{  
	Display();
	this->Display();   // does the same thing
	mX = 0; 
	this->mX = 0;      // does the same thing as above
}

Point2D& Point2D::RefOurselves() {	return *this; }
Point2D* Point2D::PointerOurselves() {	return this; }
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
	Point2D myPoint{5, 10};
	cout << "Size of myPoint is: " << sizeof(myPoint) << endl;
	myPoint.Display();

	Point2D& refPoint = myPoint.RefOurselves();
	Point2D* ptrPoint = myPoint.PointerOurselves();

	refPoint.Display();
	ptrPoint->Display();

	cout << "Point's address: " << &myPoint << " refPoint is referencing: " &refPoint << " ptrPoint is pointing to: " << ptrPoint << endl;

	cout << endl;
	system("Pause");
	return 0;
}