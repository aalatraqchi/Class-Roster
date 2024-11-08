#pragma once
#include <string>
#include "degree.h"

using namespace std;

class Student {
private:
	// (D1)
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysPerCourse[3];
	DegreeProgram degreeProgram;

public:
	// (D2d)
	// Default constructor
	Student();
	//Constructor with paramaters
	Student(string studentID, string firstName, string lastName, string emailAddress, 
		int age, int daysPC1, int daysPC2, int daysPC3, DegreeProgram degreeProgram);
	//Destructor
	~Student();
	// (D2a)
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDaysPerCourse();
	DegreeProgram getDegreeProgram();
	// (D2b)
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDaysPerCourse(int* daysPerCourse);
	// (D2e)
	void print();
};