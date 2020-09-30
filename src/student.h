#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "degree.h"

class Student 
{
private:
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    int age;
    int daysToComplete[3] = {0, 0, 0};
    DegreeProgram degree;
    
public:
    static const size_t ARR_SIZE = 3;

    Student(std::string studentID, std::string firstName, std::string lastName,
        std::string emailAddress, int age, int * daysToCompletion, DegreeProgram degreeProgram);
    
    std::string getStudentID();
    void setStudentID(std::string studentID);

    std::string getFirstName();
    void setFirstName(std::string firstName);

    std::string getLastName();
    void setLastName(std::string lastName);

    std::string getEmailAddress();
    void setEmailAddress(std::string emailAddress);

    unsigned int getAge();
    void setAge(int age);

    const int * getDaysToComplete() const;
    void setDaysToComplete(int * daysToCompletion);

    DegreeProgram getDegreeProgram();
    void setDegreeProgram(DegreeProgram degreeProgram);

    void print();
};

#endif
