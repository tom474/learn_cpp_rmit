/*
    RMIT University Vietnam
    Course: EEET2482/COSC2082
    Semester: 2023-3
    Lab Assessment: 2
    Author: Tran Manh Cuong
    ID: 3974735
    Compiler used: g++ 13.2.0
    Created  date: 13/01/2024
    Acknowledgement: Canvas, GeeksforGeeks
*/
#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::string;

int main() {
    std::fstream myfile;

    // Ask the user to input studentName
    string studentName;
    cout << "Input your student name: ";
    getline(cin >> std::ws, studentName);

    // Ask the user to input studentID
    string studentID;
    cout << "Input your student id: ";
    getline(cin >> std::ws, studentID);

    // Save student data to studentName.dat
    myfile.open("studentName.dat", std::ios::out);
    myfile << "Student Name: " << studentName << "\n";
    myfile << "Student ID: " << studentID;
    myfile.close();
    cout << "Your data is saved !\n";

    return 0;
}
