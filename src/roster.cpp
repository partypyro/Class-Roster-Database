#include <iostream>
#include "roster.h"
#include "degree.h"
#include "student.h"

Student * Roster::getStudent(size_t index)
{
	// Summary:
	//		Returns a pointer to the student at the specified index in the class roster array
	// Arguments:
	//		index: An unsigned integer representing the index in the class roster array
	// Returns:
	//		Returns the pointer to a Student object stored in the class roster array at the specified index
	// Raises:
	//		If the index points to a null pointer outside of part of the class roster array occupied
	//		by valid Student object pointers, than an invalid index error is returned

	// Check if index is out of bounds
	try
	{
		if(index >= this->rosterSize)
		{
			throw 1;
		}
	}
	// If out of bounds, print an error message.
	catch (int e)
	{
		std::cout << "Error: Invalid index." << std::endl;
	}

	// Otherwise, return the pointer stored in the class roster array
	return this->classRosterArray[index];
}

size_t Roster::getRosterSize()
{
	// Summary: Returns the occupied size of the class roster array
	// Arguments:
	//		No arguments
	// Returns:
	//		Returns a unsigned integer represented the occupied size of the class roster array
	// Raises:
	//		No error handling associated with this function

	return this->rosterSize;
}

void Roster::add(std::string studentID, std::string firstName, std::string lastName,
	std::string emailAddress, int age, int daysInCourse1, int daysInCourse2,
	int daysInCourse3, DegreeProgram degreeprogram)
{
	// Summary:
	//		Adds a new student object pointer to the class roster array with the provided instance variables
	// Arguments:
	//		All instance variables needed to create new Student object. Three "daysInCourse" variables are used
	//		to construct the instance variable array daysToComplete for the new Student object.
	// Returns:
	//		None
	// Raises:
	//		If the class roster array is full, print an error message and don't add the new student

	//
	if(this->rosterSize == this->ARR_SIZE)
	{
		std::cout << "Error: The class roster is full." << std::endl;
	}
	else
	{
		int daysToComplete[Student::ARR_SIZE] = {daysInCourse1, daysInCourse2, daysInCourse3};
		// Allocate memory for and store a point to a new Student object and fill the construct with the provided arguments
		Student * newStudent = new Student(studentID, firstName, lastName, emailAddress, age, daysToComplete, degreeprogram);
		// Replace the null pointer stored in the array with the newly created pointer
		this->classRosterArray[this->rosterSize] = newStudent;
		// Increase the roster size to represent the max index to which the class roster array is filled
		this->rosterSize += 1;
	}
}

void Roster::remove(std::string studentID)
{
	// Summary: Function determines if an email address is valid
	// Arguments:
	//		studentID: A string representing the ID of student to be removed from the class roster
	// Returns:
	//		None
	// Raises:
	//		If the class roster has no students in it (all pointers in the class roster array point to
	//		null), print a respective error message

	if(this->rosterSize == 0)
	{
		std::cout << "Error: There are no students in the class roster." << std::endl;
	}
	else
	{
		// We need to look through the class roster for the student with the matching ID
		for(size_t i = 0; i < this->rosterSize; i++)
		{
			// If the student ID of the student we are looking at matches the student ID we were
			// given, delete that student from the roster
			if(this->classRosterArray[i]->getStudentID() == studentID)
			{
				// Free the memory allocated to the student object the pointer in our class roster array is pointing to
				delete this->classRosterArray[i];

				// Shift all students ahead of the student we just removed back one index in the array. This will fill the
				// 'empty spot' or defunct pointer we just created in the array
				for(size_t j = i; j < this->ARR_SIZE - 1; j++)
				{
					this->classRosterArray[j] = this->classRosterArray[j + 1];
				}

				// After shifting all student pointers back one index, a duplicate student remains at the end of the array.
				// Set this pointer at the end of the array to NULL to remove the duplicate.
				this->classRosterArray[this->ARR_SIZE - 1] = NULL;

				// Decrease the size of the roster to repesent the removed student and exit the function
				this->rosterSize -= 1;
				return;
			}
		}
	}
	// If we searched through the entire array without finding the student ID, print a respective error message
	std::cout << "Error: The student ID " << studentID << " was not found." << std::endl;
}

void Roster::printAll()
{
	// Summary: Prints out all the student data stored in the class roster
	// Arguments:
	//		None
	// Returns:
	//		None
	// Raises:
	//		No error handling associated with this function

	// Iterate through the portion of the class roster array filled with students
	for(size_t i = 0; i < this->rosterSize; i++)
	{
		// Call the print function of each student
		this->classRosterArray[i]->print();
	}
	std::cout << std::endl;
}

void Roster::printAverageDaysInCourse(std::string studentID)
{
	// Summary: Look for a student with the matching student ID and print the average number of days they spend in a course
	// Arguments:
	//		studentID: string representing the studentID to look for in the class roster
	// Returns:
	//		None
	// Raises:
	//		If the student ID specified was not found in the class roster, then print a respective error message

	// Iterate through the portion of the class roster array filled with students
	for(size_t i = 0; i < this->rosterSize; i++)
	{
		// If the student ID of the current student in the class roster array matches the specified student ID,
		// calculate the student's average number of days spent in a course
		if(this->classRosterArray[i]->getStudentID() == studentID)
		{
			// Create variable to represent average number of days
			float averageDaysInCourse = 0;

			// Sum the number of days spent in each course
			for(size_t j = 0; j < Student::ARR_SIZE; j++)
			{
				averageDaysInCourse += classRosterArray[i]->getDaysToComplete()[j];
			}

			// Divide by the total number of courses
			averageDaysInCourse /= Student::ARR_SIZE;

			// Print the average value to the console and exit the function
			std::cout << classRosterArray[i]->getStudentID()
					<< " Average days in course: " << averageDaysInCourse << std::endl;
			return;
		}
	}
	// If the entire class roster array was searched and the student ID was not found, print a respective error message
	std::cout << "Error: The student ID " << studentID << " was not found." << std::endl;
}

bool Roster::checkIfValidEmail(std::string emailAddress)
{
	// Summary: Function determines if an email address is valid
	// Arguments:
	//		emailAddress: A string containing the email address to be checked
	// Returns:
	//		Returns true if the email address is valid, and false if the email address is invalid
	// Raises:
	//		No specific error handling associated with this function

	// Create boolean values to represent flags for the presence of an at sign (@), period (.), and space ( )
	bool containsAtSign, containsPeriod, containsSpace;

	// Look for a space in this email address and set the flag accordingly
	// npos == not found in string
	size_t pos = emailAddress.find(" ", 0);
	if(pos == std::string::npos) containsSpace = false;
	else containsSpace = true;

	// Look for at sign (@)
	pos = emailAddress.find("@", 0);
	if(pos == std::string::npos) containsAtSign = false;
	else containsAtSign = true;

	// Look for period
	pos = emailAddress.find(".", 0);
	if(pos == std::string::npos) containsPeriod = false;
	else containsPeriod = true;

	// If the email address contains a period and an at sign, but not a
	// space, then it must be an email address, so return true. Otherwise,
	// return false.
	if(containsPeriod && containsAtSign && !containsSpace) return true;
	return false;
}

void Roster::printInvalidEmails()
{
	// Summary:
	//		Determines if an email address is valid
	// Arguments:
	//		emailAddress: A string containing the email address to be checked
	// Returns:
	//		Returns true if the email address is valid, and false if the email address is invalid
	// Raises:
	//		No specific error handling associated with this function

	std::cout << "Invalid email addresses:\t";
	// Look through the portion of the class roster array filled with students
	for(size_t i = 0; i < this->rosterSize; i++)
	{
		// Check if the current student's email address is valid. If it is not a valid email address.
		// print it to the console, otherwise, skip the student
		if(!checkIfValidEmail(this->classRosterArray[i]->getEmailAddress()))
		{
			std::cout << classRosterArray[i]->getStudentID() << " - "
					<< classRosterArray[i]->getEmailAddress() << "\t";
		}
	}
	std::cout << std::endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	// Summary:
	//		Prints all students in the class roster with the associated degree program
	// Arguments:
	//		degreeProgram: Specified degree program to look for of enum type DegreeProgram
	// Returns:
	//		None
	// Raises:
	//		No error handling associated with this function

	std::cout << "Students with degree program " << degreeProgramStrings[(int)degreeProgram] << ":" << std::endl;
	// Look through the portion of the class roster array filled with students
	for(size_t i = 0; i < this->rosterSize; i++)
	{
		// If the current student in the class roster matches the specified degree program, call that student's print function
		if(this->classRosterArray[i]->getDegreeProgram() == degreeProgram)
		{
			classRosterArray[i]->print();
		}
	}
	std::cout << std::endl;
}
