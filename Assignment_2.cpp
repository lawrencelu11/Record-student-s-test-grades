/*
    Lawrence Lu
    CIS22-B
    04/23/21

    This program prompts the user to enter the number of students he/she wish to record the students' test grades.
    Next, it prompts for each student's name and the number of tests they have taken. Lastly, the user enters each test grade for each student, and
    the console prints all data entered onto the screen.
*/
#include <iostream>
#include <string>

using namespace std;

int inputData(string*& strPtr, double**& doublePtr);
void displayData(string* strPtr, double** doublePtr, int numberOfStudents);
void cleanHeap(string* strPtr, double** doublePtr, int numberOfStudents);

int main()
{
    string *studentNames = nullptr;
    double **testScores = nullptr;

    int numberOfStudents = inputData(studentNames, testScores);
    displayData(studentNames, testScores, numberOfStudents);
    cleanHeap(studentNames, testScores, numberOfStudents);
    return 0;
}
//************************************************************
//This function prompts user to enter the number of students, their names, and their test grades.
//Passes in a string pointer variable and a double pointer of type double both as reference.
//Returns the number of students recorded.
int inputData(string*& strPtr, double**& doublePtr)
{
    int studentCount, testCount;

    do   //Loop will not end until user enters the number of students as a positive value.
    {
        cout << "Enter number of students: ";
        cin >> studentCount;
        cin.ignore();
        cout << "\n";
        if(studentCount < 0)
        {
            cout << "Value must be positive! Try again!\n\n";
        }
    }while(studentCount < 0);

    strPtr = new string[studentCount];  // Allocate memory to create a dynamic array of strings to hold students' names.
    doublePtr = new double*[studentCount]; //Allocate memory to create a dynamic array of pointers of type double.

    for(int i = 0; i < studentCount; i++)
    {
        cout << "Enter student name: ";
        getline(cin, strPtr[i]);
        cout << "\n";
        do
        {

            cout << "Enter number of test " << strPtr[i] << " took: ";
            cin >> testCount;
            cout << "\n";
            if(testCount < 0){cout << "Input must be positive. Try Again!\n\n";}
        }while(testCount < 0);

        // Each pointer in the array of pointers will point to the array that contains the student's test grades.
        doublePtr[i] = new double[testCount + 1];  //testCount + 1 to also store the number of test grades for the student in the array.
        doublePtr[i][0] = testCount; //The number of test grades is stored in the first element of the array.

        for(int j = 1; j <= doublePtr[i][0]; j++)
        {
            do
            {
                cout << "Enter grade#" << j << ": ";
                cin >> doublePtr[i][j];
                cin.ignore();
                cout << "\n";
                if(doublePtr[i][j] < 0 || doublePtr[i][j] > 100)
                {
                    cout << "Input must be ranging from 0-100!Try Again!\n\n";
                }
            }while(doublePtr[i][j] < 0 || doublePtr[i][j] > 100);
        }
    }

    return studentCount;
}
//************************************************************
//This function displays student's name and their test grades
//Passes in a string pointer variable and a double pointer of type double.
void displayData(string* strPtr, double** doublePtr, int numberOfStudents)
{
    cout << "You have " << numberOfStudents << " students in the system.\n";

    for(int i = 0; i < numberOfStudents; i++)
    {
        cout << "Name of student #" << (i + 1) << ": " << strPtr[i] << endl;
        cout << "Grade for student #" << (i + 1) << ": ";
        for(int j = 1 ; j <= doublePtr[i][0]; j++)
        {
            cout << doublePtr[i][j] << " ";
        }
        cout << "\n";
    }
}
//************************************************************
//This function deletes all dynamic arrays
//Passes in a string pointer variable and a double pointer of type double.
void cleanHeap(string* strPtr, double** doublePtr, int numberOfStudents)
{
    for(int i = 0; i < numberOfStudents; i++)
    {
        delete *(doublePtr + i); //Deletes array that stores student test grades
    }

    delete [] strPtr; // Deletes array that stores students' name
    delete [] doublePtr; //Deletes array of pointers
}

/* Execution Results

Enter number of students: 3

Enter student name: Lawrence

Enter number of test Lawrence took: 2

Enter grade#1: 90

Enter grade#2: 80

Enter student name: Lu

Enter number of test Lu took: -3

Input must be positive. Try Again!

Enter number of test Lu took: 2

Enter grade#1: 20

Enter grade#2: 10

Enter student name: Nguyen

Enter number of test Nguyen took: 1

Enter grade#1: 50

You have 3 students in the system.
Name of student #1: Lawrence
Grade for student #1: 90 80
Name of student #2: Lu
Grade for student #2: 20 10
Name of student #3: Nguyen
Grade for student #3: 50

Process returned 0 (0x0)   execution time : 45.412 s
Press any key to continue.

*/
