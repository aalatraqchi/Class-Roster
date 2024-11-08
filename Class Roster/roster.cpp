#include "roster.h"
#include <string>

using namespace std;

// Function to extract data to keep Roster constructor clean
string* extractData(int studentIndex) {
	// Create studentData table
	const string studentData[] =

	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Ashraf,Al-Atraqchi,aalatr2@wgu.edu,21,22,30,37,SOFTWARE" // (A)
	};

	// Declare variables to store parsed info in
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	string age;
	string daysInCourse1;
	string daysInCourse2;
	string daysInCourse3;
	string degreeProgram;
	string* info = new string[9]; // Will store all info extracted by parsing a student string

	// Declare variable for start index (first character of data) and end index (comma)
	size_t startIndex = 0;
	size_t endIndex;

	// Store comma index into endIndex and get substring from start index to end index
	endIndex = studentData[studentIndex].find(",");
	studentID = studentData[studentIndex].substr(startIndex, endIndex - startIndex);
	info[0] = studentID;

	// Store index after last comma as the new start index and store next comma as new end index
	startIndex = endIndex + 1;
	endIndex = studentData[studentIndex].find(",", startIndex);
	firstName = studentData[studentIndex].substr(startIndex, endIndex - startIndex);
	info[1] = firstName;

	startIndex = endIndex + 1;
	endIndex = studentData[studentIndex].find(",", startIndex);
	lastName = studentData[studentIndex].substr(startIndex, endIndex - startIndex);
	info[2] = lastName;

	startIndex = endIndex + 1;
	endIndex = studentData[studentIndex].find(",", startIndex);
	emailAddress = studentData[studentIndex].substr(startIndex, endIndex - startIndex);
	info[3] = emailAddress;

	startIndex = endIndex + 1;
	endIndex = studentData[studentIndex].find(",", startIndex);
	age = studentData[studentIndex].substr(startIndex, endIndex - startIndex);
	info[4] = age;

	startIndex = endIndex + 1;
	endIndex = studentData[studentIndex].find(",", startIndex);
	daysInCourse1 = studentData[studentIndex].substr(startIndex, endIndex - startIndex);
	info[5] = daysInCourse1;

	startIndex = endIndex + 1;
	endIndex = studentData[studentIndex].find(",", startIndex);
	daysInCourse2 = studentData[studentIndex].substr(startIndex, endIndex - startIndex);
	info[6] = daysInCourse2;

	startIndex = endIndex + 1;
	endIndex = studentData[studentIndex].find(",", startIndex);
	daysInCourse3 = studentData[studentIndex].substr(startIndex, endIndex - startIndex);
	info[7] = daysInCourse3;

	startIndex = endIndex + 1;
	endIndex = studentData[studentIndex].find(",", startIndex);
	degreeProgram = studentData[studentIndex].substr(startIndex, endIndex - startIndex);
	info[8] = degreeProgram;

	return info;
}

Roster::Roster()
{
	// Pointer array for all 5 student objects
	classRosterArray = new Student[5];

	// (E2) Loop through studentData and extract info to add to roster
	for (int i = 0; i < numStudents; ++i) {
		// Get pointer to current student's (i) info
		string* infoptr;
		infoptr = extractData(i);
		DegreeProgram degreeProgram;
		// Convert degree program string into corresponding enum type
		if (infoptr[8] == "SECURITY") {
			degreeProgram = SECURITY;
		}
		else if (infoptr[8] == "NETWORK") {
			degreeProgram = NETWORK;
		}
		else {
			degreeProgram = SOFTWARE;
		}
		// Call add function passing in corresponding info as arguments (converting int types using stoi)
		add(infoptr[0], infoptr[1], infoptr[2], infoptr[3], stoi(infoptr[4]), stoi(infoptr[5]), stoi(infoptr[6]), stoi(infoptr[7]), degreeProgram);
		delete[] infoptr;
	}
}

Roster::~Roster()
{
	delete[] classRosterArray;
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age,
	int daysInCourse1, int daysInCourse2, int daysinCourse3, DegreeProgram degreeProgram)
{
	// (E3a)
	// Create student pointer to new student object with given parameters
	Student* student = new Student(studentID, firstName, lastName, emailAddress, age,
		daysInCourse1, daysInCourse2, daysinCourse3, degreeProgram);

	// Store student object in classRosterArray at the current index and update index
	classRosterArray[currentStudentIndex] = *student;
	currentStudentIndex++;
}

void Roster::remove(string studentID)
{
	//(E3b)
	// Loop through roster array and compare student object ID's with the argument student ID
	for (int i = 0; i < numStudents; ++i) {
		if (classRosterArray[i].getStudentID() == studentID) {
			// Instead of removing from array and having to shift elements, student ID is set to 0 of removed student and will be ignored in other functions
			classRosterArray[i].setStudentID("0");
			return;
		}
	}

	// If for loop finishes without returning, the ID was not found - Print error message
	cout << "ERROR - Student with ID: " << studentID << " was not found!" << endl;
}

void Roster::printAll()
{
	// (E3c)
	// Loop through students and call print() for all
	cout << "Student Roster:" << endl;

	for (int i = 0; i < numStudents; ++i) {
		// Ignores students with invalid ID's (set to 0 from remove)
		if (classRosterArray[i].getStudentID() != "0") {
			classRosterArray[i].print();
		}
	}
}

void Roster::printAverageDaysInCourse(string studentID)
{
	// (E3d)
	// Loop through array and find student with student ID argument
	for (int i = 0; i < numStudents; ++i) {
		if (classRosterArray[i].getStudentID() == studentID) {
			int* days = classRosterArray[i].getDaysPerCourse();
			int avg = (days[0] + days[1] + days[2]) / 3;

			cout << classRosterArray[i].getStudentID() << ") Average number of days in 3 courses: " << avg << endl;
			return;
		}
	}

	// If studentID doesn't match any in the class roster array
	cout << "ERROR - Invalid Student ID: " << studentID << endl;
}

void Roster::printInvalidEmails()
{
	// (E3e)
	cout << "Invalid Email Addresses: " << endl;
	// Loop through arrays and verify email addresses that have @, period, and no spaces
	for (int i = 0; i < numStudents; ++i) {

		string email = classRosterArray[i].getEmailAddress();
		size_t atSymbolPos = email.find("@");
		size_t spacePos = email.find(" ");

		// If @ symbol is not found, email is invalid
		if (atSymbolPos == -1) {
			cout << email << endl;
		}
		// If a space is present, email is invalid
		else if (spacePos != -1) {
			cout << email << endl;
		}
		else {
			size_t periodPos = email.find(".", atSymbolPos);

			// If a period is not found after the @ symbol, email is invalid
			if (periodPos == -1) {
				cout << email << endl;
			}
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	// (E3f)
	string DP;
	if (degreeProgram == SECURITY) {
		DP = "Security";
	}
	else if (degreeProgram == NETWORK) {
		DP = "Network";
	}
	else {
		DP = "Software";
	}
	cout << "Students in Degree Program: " << DP << endl;

	for (int i = 0; i < numStudents; ++i) {
		if (classRosterArray[i].getDegreeProgram() == degreeProgram) {
			classRosterArray[i].print();
		}
	}
}

Student Roster::getStudent(int i)
{
	return classRosterArray[i];
}
