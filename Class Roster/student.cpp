#include "student.h"
#include <string>
#include <iostream>

using namespace std;

// (D1)
// Explicitly defined default constructor
Student::Student() {
	studentID = "";
	firstName = "";
	lastName = "";
	emailAddress = "";
	age = 0;
	daysPerCourse[0] = 0;
	daysPerCourse[1] = 0;
	daysPerCourse[2] = 0;
}

// Constructor with all paramaters
Student::Student(string studentID, string firstName, string lastName, string emailAddress,
	int age, int daysPC1, int daysPC2, int daysPC3, DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	daysPerCourse[0] = daysPC1;
	daysPerCourse[1] = daysPC2;
	daysPerCourse[2] = daysPC3;
	this->degreeProgram = degreeProgram;
}

// Blank destructor
Student::~Student() {}

// Define accessors
string Student::getStudentID() {
	return studentID;
}

string Student::getFirstName() {
	return firstName;
}

string Student::getLastName() {
	return lastName;
}

string Student::getEmailAddress() {
	return emailAddress;
}

int Student::getAge() {
	return age;
}

int* Student::getDaysPerCourse() {
	return daysPerCourse;
}

DegreeProgram Student::getDegreeProgram() {
	return degreeProgram;
}

// Define mutators
void Student::setStudentID(string studentID) {
	this->studentID = studentID;
}

void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
}

void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}

void Student::setAge(int age) {
	this->age = age;
}

void Student::setDaysPerCourse(int* daysPerCourse) {
	daysPerCourse[0] = daysPerCourse[0];
	daysPerCourse[1] = daysPerCourse[1];
	daysPerCourse[2] = daysPerCourse[2];
}

void Student::print() {
	// (D2e) - Print tab separated data
	// Store days in course and degree program in variables because they aren't strings
	int* days = getDaysPerCourse();
	string degree;

	// Set degree string equivalent to enum type
	if (getDegreeProgram() == SECURITY) {
		degree = "Security";
	}
	else if (getDegreeProgram() == NETWORK) {
		degree = "Network";
	}
	else {
		degree = "Software";
	}

	cout << getStudentID();
	cout << "\tFirst Name: " << getFirstName();
	cout << "\tLast Name: " << getLastName();
	cout << "\t Age: " << getAge();
	cout << "\t Days in Course: {" << days[0] << ", " << days[1] << ", " << days[2] << "}";
	cout << "\tDegree Program: " << degree << endl;
}
