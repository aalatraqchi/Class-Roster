#pragma once
#include <iostream>
#include "student.h"

using namespace std;

class Roster {
private:
	// (E1), array of pointers for student objects
	Student* classRosterArray;
	int currentStudentIndex = 0;
	int numStudents = 5;

public:
	// Constructor and Destructor
	Roster();
	~Roster();
	// (E3)
	void add(string studentID, string firstName, string lastName, string emailAddress, int age,
		int daysInCourse1, int daysInCourse2, int daysinCourse3, DegreeProgram degreeProgram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	Student getStudent(int i);
};
