#include <iostream>
#include "student.h"
#include "degree.h"

Student::Student(std::string studentID, std::string firstName, std::string lastName,
    std::string emailAddress, int age, int * daysToComplete, DegreeProgram degreeProgram)
{
	// Summary: Student constructor that takes all Student instance variables

    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    setDaysToComplete(daysToComplete);
    this->degree = degreeProgram;
}
    
std::string Student::getStudentID()
{
	// Summary: Returns string instance variable studentID

    return this->studentID;
}
void Student::setStudentID(std::string studentID)
{
	// Summary: Sets string instance variable studentID

    this->studentID = studentID;
}

std::string Student::getFirstName() 
{
	// Summary: Returns string instance variable firstName

    return this->firstName;
}
void Student::setFirstName(std::string firstName) 
{
	// Summary: Returns string instance variable firstName

    this->firstName = firstName;
}

std::string Student::getLastName() 
{
	// Summary: Returns string instance variable lastName

    return this->lastName;
}
void Student::setLastName(std::string lastName) 
{
	// Summary: Sets string instance variable lastName

    this->lastName = lastName;
}

std::string Student::getEmailAddress() 
{
	// Summary: Returns string instance variable emailAddress

    return this->emailAddress;
}
void Student::setEmailAddress(std::string emailAddress) 
{
	// Summary: Sets string instance variable emailAddress

    this->emailAddress = emailAddress;
}

unsigned int Student::getAge()
{
	// Summary: Returns unsigned integer instance variable age

    return this->age;
}
void Student::setAge(int age)
{
	// Summary: Sets unsigned integer instance variable age

    this->age = age;
}

const int * Student::getDaysToComplete() const
{
	// Summary: Returns a pointer to the instance variable array daysToComplete

    return this->daysToComplete;
}
void Student::setDaysToComplete(int * daysToComplete)
{
	// Summary: Sets the instance variable array daysToComplete

	// Iterate through the instance variable daysToComplete and replace each value with the value
	// contained in the argument array
    for(size_t i = 0; i < Student::ARR_SIZE; i++)
    {
        this->daysToComplete[i] = daysToComplete[i];
    }
}

DegreeProgram Student::getDegreeProgram()
{
	// Summary: Returns the enum type DegreeProgram instance variable degreeProgram

    return this->degree;
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) 
{
	// Summary: Sets the enum type DegreeProgram instance variable degreeProgram

    this->degree = degreeProgram;
}

void Student::print() 
{
	// Summary: Prints a labeled, tab-separated line of the information contained in each instance variable of the Student object

	std::cout << this->studentID << "\t" << "First Name: " << this->firstName << "\t" << "Last Name: " << this->lastName << "\t"
			<< "Age: " << this->age << " \t" << "daysInCourse: {" << this->daysToComplete[0] << ", " << this->daysToComplete[1] << ", "
			<< this->daysToComplete[2] << "} \t" << "Degree Program: " << degreeProgramStrings[(int)this->degree] << "." << std::endl;
}
