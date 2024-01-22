#include <iostream>
#include <vector>

using std::cout;
using std::string;

class Department {
    private:
        string name;
    public:
        Department(string nameVal = "")
        : name(nameVal) {}

        void showInfo() {
            cout << "Name of Department: " << name << "\n";
        }
};

class AcademicDepartment : public Department {
    private:
        int numOfCourses;
    public:
        AcademicDepartment(string name = "", int numOfCoursesVal = 0)
        : Department(name), numOfCourses(numOfCoursesVal) {}    // Call constructor of base class

        void showInfo() {
            Department::showInfo(); // Call method of base class
            cout << "Num of courses: " << numOfCourses << "\n";
        }
};

int main() {
    AcademicDepartment sset("SSET", 25);
    sset.showInfo();

    return 0;
}