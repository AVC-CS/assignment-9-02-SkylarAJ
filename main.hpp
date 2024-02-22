#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

const int N = 5;
struct Student
{
    int id;
    string name;
    string major;
    Student *next;
};

Student *makeStudent();
void printStudent(Student *head);

Student *makeStudent()
{
    ifstream inputFile("students.txt");
    if (!inputFile)
    {
        cerr << "Error: Unable to open file." << endl;
        exit(1);
    }

    // Initialize head pointer
    Student *head = nullptr;
    Student *tail = nullptr;

    // Read data from file and create student nodes
    int id;
    string name, major;
    while (inputFile >> id >> name >> major)
    {
        // Create new student
        Student *newStudent = new Student;
        newStudent->id = id;
        newStudent->name = name;
        newStudent->major = major;
        newStudent->next = nullptr;

        // Add to the linked list
        if (head == nullptr)
        {
            head = newStudent;
            tail = newStudent;
        }
        else
        {
            tail->next = newStudent;
            tail = newStudent;
        }
    }

    // Close the file
    inputFile.close();

    return head;
}

void printStudent(Student *head)
{
    cout << "Student Information:" << endl;
    cout << "====================" << endl;
    Student *current = head;
    while (current != nullptr)
    {
        cout << "ID: " << current->id << ", Name: " << current->name << ", Major: " << current->major << endl;
        current = current->next;
    }
}