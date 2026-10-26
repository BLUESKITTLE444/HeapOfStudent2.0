#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "address.h"
#include "date.h"

class Student
{
private:
    std::string firstName;
    std::string lastName;

    Address* address;
    Date* dob;
    Date* gradDate;

    int credits;

public:
    Student();
    Student(std::string csvLine);
    ~Student();

    std::string getFirstName();
    std::string getLastName();
    int getCredits();

    void printSummary();
    void printFull();
};

#endif
