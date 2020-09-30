#ifndef ROSTER_H
#define ROSTER_H

#include <string>
#include "degree.h"
#include "student.h"

class Roster
{
private:
	Student *classRosterArray[5] = {NULL};
	size_t rosterSize = 0;
public:
	static const size_t ARR_SIZE = 5;

	Student * getStudent(size_t index);

	size_t getRosterSize();

    void add(std::string studentID, std::string firstName, std::string lastName,
        std::string emailAddress, int age, int daysInCourse1, int daysInCourse2,
        int daysInCourse3, DegreeProgram degreeprogram);

    void remove(std::string studentID);

    void printAll();

    void printAverageDaysInCourse(std::string studentID);

    bool checkIfValidEmail(std::string emailAddress);

    void printInvalidEmails();

    void printByDegreeProgram(DegreeProgram degreeProgram);
};

#endif
