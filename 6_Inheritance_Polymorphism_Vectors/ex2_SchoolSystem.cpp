#include <iostream>
#include <vector>
#include <fstream>

#define FILENAME "dataFile.dat"

using std::cin;
using std::cout;
using std::string;

class Student {
    protected:
        string name;
        int id;

    public:
        Student(string nameVal = "", int idVal = 0)
        : name(nameVal), id(idVal) {}

    friend class System;
};

class System {
    private:
        std::vector<Student> students{};
    public:
        System() {} // Constructor

        // Extra function to check if a student is in the system or not
        int findStudent(int id) {
            for (int i = 0; i < students.size(); i++) {
                if (students[i].id == id) {
                    return i;   // Return position if matched
                }
            }
            return -1;
        }

        // Function to add student
        bool addStudent() {
            int id;
            cout << "Input student ID: ";
            cin >> id;

            int position = findStudent(id);
            if (position >= 0) {    // Student is already in the system
                cout << "Student is already in the system!\n";
                return false;
            } else {    // Add new student
                string name;
                cout << "Input student name: ";
                getline(cin >> std::ws, name);

                students.push_back(Student(name, id));
                cout << "Added to the system successfully!\n";
                return true;
            }
        }

        // Function to remove student
        bool removeStudent() {
            int id;
            cout << "Input student ID: ";
            cin >> id;

            int position = findStudent(id);
            if (position >= 0) {    // Student is in the system
                students.erase(students.begin() + position);
                cout << "Removed from the system successfully!\n";
                return true;
            } else {    // Student is not found in the system
                cout << "Student is not found in the system!\n";
                return false;
            }
        }

        // Function to show info of all students
        void showAllStudent() {
            cout << "\nAll Students in the school system:\n";
            for (Student &stu: students) {
                cout << stu.name << " : " << stu.id << "\n"; 
            }
        }

        // Function to save info of all students to file
        bool saveAllStudents() {
            std::fstream dataFile;
            dataFile.open(FILENAME, std::ios::out);
            if (!dataFile.is_open()) {
                std::cerr << "Fail to create/open file!\n";
                return false;
            }

            // Store in the file
            for (Student &stu: students) {
                dataFile << stu.name << " : " << stu.id << "\n";
            }
            dataFile.close();
            return true;
        }

        bool reloadData() {
            std::fstream dataFile;
            dataFile.open(FILENAME, std::ios::in);

            if (!dataFile.is_open()) {
                std::cerr << "Fail to create/open file!\n";
                return false;
            }

            // Reload data from the file
            string name, id;
            while (true) {
                // Read data from file
                getline(dataFile, name, ':');   // Read name until seeing ':' character
                getline(dataFile, id);  // Read id
                if (name == "" || id == "") {
                    break;
                }

                // Store into the student list
                students.push_back(Student(name, std::stoi(id)));
            }
            return true;
        }
};

int main() {
    System sys;

    if (!sys.reloadData()) {
        std::cerr << "Fail to load data\n";
    }

    while (true) {
        cout << "\nSchool Management System\n";
        cout << "1. View All Students\n";
        cout << "2. Add Student\n";
        cout << "3. Remove Student\n";
        cout << "4. Exit\n";
        cout << "Enter Your Choice: ";
        int choice;
        cin >> choice;

        if (choice == 1) {  // View all students
            sys.showAllStudent();
        } else if (choice == 2) {   // Add student
            sys.addStudent();
        } else if (choice == 3) {   // Remove student
            sys.removeStudent();
        } else if (choice == 4) {   // Exit
            // Save all data before exit
            if (!sys.saveAllStudents()) {
                std::cerr << "Error: Fail to save data to your app\n";
            }
            cout << "Data saved! Have a good day!";
            break;
        }
    }

    return 0;
}