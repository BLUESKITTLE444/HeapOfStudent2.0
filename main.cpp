#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "student.h"

using namespace std;

// Function Prototypes
void loadStudents(vector<Student*>& students);
void printStudents(vector<Student*>& students);
void showStudentNames(vector<Student*>& students);
void findStudent(vector<Student*>& students);
void delStudents(vector<Student*>& students);
string menu();

int main()
{
    vector<Student*> students;

    loadStudents(students);

    string choice;

    do
    {
        choice = menu();

        if (choice == "1")
        {
            showStudentNames(students);
        }
        else if (choice == "2")
        {
            printStudents(students);
        }
        else if (choice == "3")
        {
            findStudent(students);
        }
        else if (choice != "0")
        {
            cout << "Invalid choice." << endl;
        }

    } while (choice != "0");

    delStudents(students);

    return 0;
}

void loadStudents(vector<Student*>& students)
{
    ifstream fin("students.csv");

    if (!fin)
    {
        cout << "Error opening students.csv" << endl;
        return;
    }

    string line;

    while (getline(fin, line))
    {
        Student* student = new Student(line);
        students.push_back(student);
    }

    fin.close();
}

void printStudents(vector<Student*>& students)
{
    for (Student* student : students)
    {
        student->printFull();
    }
}

void showStudentNames(vector<Student*>& students)
{
    for (Student* student : students)
    {
        student->printSummary();
    }
}

void findStudent(vector<Student*>& students)
{
    string search;

    cout << "last name of student: ";
    getline(cin, search);

    bool found = false;

    for (Student* student : students)
    {
        if (student->getLastName().find(search) != string::npos)
        {
            student->printFull();
            found = true;
        }
    }

    if (!found)
    {
        cout << "No matching students found." << endl;
    }
}

void delStudents(vector<Student*>& students)
{
    for (Student* student : students)
    {
        delete student;
    }

    students.clear();
}

string menu()
{
    string choice;

    cout << endl;
    cout << "0) quit" << endl;
    cout << "1) print all student names" << endl;
    cout << "2) print all student data" << endl;
    cout << "3) find a student" << endl;
    cout << endl;

    cout << "please choose 0-3: ";
    getline(cin, choice);

    return choice;
}
