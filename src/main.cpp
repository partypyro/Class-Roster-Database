#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"
#include "roster.h"

// Initialize the string array defined in degree.h
std::string degreeProgramStrings[] =
{
	"Security",
	"Network",
	"Software",
	"None"
};

int main() 
{
	// Comma-delimited, unparsed student data
	const std::string studentData[] =
	{
			"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
			"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
			"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
			"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
			"A5,Aiden,Neill,aneill1@wgu.edu,19,24,40,3,SOFTWARE"
	};

	// Part F.1 - Print out to the screen, via your application, the course title, the programming language
	// used, you WGU student ID, and your name.
	std::cout << "Course Title: C867 -- Scripting and Programming - Applications" << std::endl;
	std::cout << "Programming Language: C++" << std::endl;
	std::cout << "Student ID: 001362420" << std::endl;
	std::cout << "Name: Aiden Neill\n" << std::endl;

	// Part F.2 - Create an instance of the Roster class called classRoster.
	Roster classRoster;
	for(int i = 0; i < 5; i++)
	{
		// To find each data point delimited by commas, remember the index after the previous comma and the
		// index up until the next comma, and take a substring starting at the low index and with a length
		// represented by the difference between both indexes

		// Student ID
		size_t low = 0;
		size_t high = studentData[i].find(",", low);
		std::string studentID = studentData[i].substr(low, high - low);

		// First name
		low = high + 1;
		high = studentData[i].find(",", low);
		std::string firstName = studentData[i].substr(low, high - low);

		// Last name
		low = high + 1;
		high = studentData[i].find(",", low);
		std::string lastName = studentData[i].substr(low, high - low);

		// Email address
		low = high + 1;
		high = studentData[i].find(",", low);
		std::string emailAddress = studentData[i].substr(low, high - low);

		// Age
		low = high + 1;
		high = studentData[i].find(",", low);
		int age = std::stoi(studentData[i].substr(low, high - low));

		// First value in daysToComplete array
		low = high + 1;
		high = studentData[i].find(",", low);
		int daysToComplete1 = std::stoi(studentData[i].substr(low, high - low));

		// Second value in daysToComplete array
		low = high + 1;
		high = studentData[i].find(",", low);
		int daysToComplete2 = std::stoi(studentData[i].substr(low, high - low));

		// Third value in daysToComplete array
		low = high + 1;
		high = studentData[i].find(",", low);
		int daysToComplete3 = std::stoi(studentData[i].substr(low, high - low));

		// Degree program
		low = high + 1;
		std::string str_degreeProgram = studentData[i].substr(low, studentData[i].length() - low);
		DegreeProgram degreeProgram = DegreeProgram::SOFTWARE;

		// Figure out which DegreeProgram value the parsed string data contains
		try
		{
			if(str_degreeProgram == "SECURITY") degreeProgram = DegreeProgram::SECURITY;
			else if(str_degreeProgram == "NETWORK") degreeProgram = DegreeProgram::NETWORK;
			else if(str_degreeProgram == "SOFTWARE") degreeProgram = DegreeProgram::SOFTWARE;
			else throw 1;
		}
		// If the degree program in the parsed string data does not match one of our enum values, throw an error
		catch(int e)
		{
			std::cout << "Error: Degree program not found" << std::endl;
		}

		// Part F.3 - Add each student to classRoster.
		classRoster.add(studentID, firstName, lastName, emailAddress, age,
				daysToComplete1, daysToComplete2, daysToComplete3, degreeProgram);
	}

	// Part F.4 - Psuedocode conversion
	classRoster.printAll();
	classRoster.printInvalidEmails();

	// loop through classRosterArray and print each student's current days in each course
	for(size_t i = 0; i < classRoster.getRosterSize(); i++)
	{
		classRoster.printAverageDaysInCourse(classRoster.getStudent(i)->getStudentID());
	}
	std::cout << std::endl;

	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
	classRoster.remove("A3");
	classRoster.printAll();
	classRoster.remove("A3");

	// Part F.5 - Implement the destructor to release the memory that was allocated dynamically in Roster
	classRoster.~Roster();
}
