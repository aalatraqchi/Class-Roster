#include <string>
#include <iostream>
#include "roster.h"

using namespace std;

int main() {
	// (F1)
	cout << "Scripting and Programming - Applications - C867" << endl;
	cout << "Language used: C++" << endl;
	cout << "Student ID: 011364001" << endl;
	cout << "Name: Ashraf Al-Atraqchi" << endl << endl;

	// (F2)
	Roster* classRoster = new Roster(); // (F3) Constructor adds each student to roster

	// (F4)
	classRoster->printAll();
	cout << endl;
	classRoster->printInvalidEmails();
	cout << endl;

	// Loop through each element in classRosterArray and print average days in course
	cout << "Student average days in courses:" << endl;
	for (int i = 0; i < 5; ++i) {
		Student student = classRoster->getStudent(i);
		classRoster->printAverageDaysInCourse(student.getStudentID());
	}
	cout << endl;

	classRoster->printByDegreeProgram(SOFTWARE);
	cout << endl;
	classRoster->remove("A3");
	classRoster->printAll();
	cout << endl;
	classRoster->remove("A3");
}