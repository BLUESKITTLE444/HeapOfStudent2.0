#include "student.h"

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// Default constructor
Student::Student()
{
    firstName = "";
    lastName = "";

    address = new Address();
    dob = new Date();
    gradDate = new Date();

    credits = 0;
}

// CSV constructor
Student::Student(string csvLine)
{
    vector<string> fields;
    string field;

    stringstream ss(csvLine);

    while (getline(ss, field, ','))
    {
        fields.push_back(field);
    }

    firstName = fields[0];
    lastName = fields[1];

    address = new Address(
        fields[2],
        fields[3],
        fields[4],
        fields[5]
    );

    int dobMonth, dobDay, dobYear;
    int gradMonth, gradDay, gradYear;

    char slash;

    stringstream dobStream(fields[6]);
    dobStream >> dobMonth >> slash >> dobDay >> slash >> dobYear;

    stringstream gradStream(fields[7]);
    gradStream >> gradMonth >> slash >> gradDay >> slash >> gradYear;

    dob = new Date(dobMonth, dobDay, dobYear);

    gradDate = new Date(
        gradMonth,
        gradDay,
        gradYear
    );

    credits = stoi(fields[8]);
}

// Destructor
Student::~Student()
{
    delete address;
    delete dob;
    delete gradDate;
}

// Get first name
string Student::getFirstName()
{
    return firstName;
}

// Get last name
string Student::getLastName()
{
    return lastName;
}

// Get credits
int Student::getCredits()
{
    return credits;
}

// Print last name, first name
void Student::printSummary()
{
    cout << lastName
         << ", "
         << firstName
         << endl;
}

// Print all student data
void Student::printFull()
{
    cout << firstName
         << " "
         << lastName
         << endl;

    cout << address->toString()
         << endl;

    cout << "DOB: "
         << dob->toString()
         << endl;

    cout << "Grad: "
         << gradDate->toString()
         << endl;

    cout << "Credits: "
         << credits
         << endl;

    cout << "____________________________________"
         << endl;
}
