/**********************************************************************************************
* Name            : ArcadeApp.cpp
* Author          : Alexander Alves
* Date            : 08/23/2023
* Version         : 0.0.1
* Copyright       :
* Update          : 08/23/2023
* Description     : Operators in C++
*
**********************************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
	string mFirstName;
	string mLastName;

public:
	Student():Student("", "") {}
	Student(const string& firstName, const string& lastName): mFirstName(firstName), mLastName(lastName){}

	
	bool operator==(const Student &otherStudent)
	{
		return mFirstName == otherStudent.mFirstName && mLastName == otherStudent.mLastName;
	}	
};


int main(int argc, const char* argv[])
{
	Student studentA("John", "Smith");
	Student studentB("John", "Smith");

	if (studentA == studentB)
		cout << "Student A and Student B are the same" << endl;
	else
		cout << "Student A and Student B are not the same" << endl;

	cout << endl;
	system("Pause");
	return 0;
}