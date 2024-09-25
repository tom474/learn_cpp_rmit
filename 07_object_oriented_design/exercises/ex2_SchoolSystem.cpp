#include <iostream>
#include <vector>

using std::cout;
using std::string;
using std::vector;

// Class prototype (declare Department class to use this data type in Staff class)
class Department;

class Staff {
    private:
        string name;
        string deptName;
    public:
        // Constructor
        Staff (string nameVal = "", string deptNameVal = "")
        : name(nameVal), deptName(deptNameVal) {}

        // Method: declare first, define later (since the class Department is not fully defined above)
        void joinDept(Department &dept);
        void leaveDept(Department &dept);

        friend class Department;    // Grant access
};

// Define Department class here
class Department {
    private:
        string name;
        string location;
        vector<Staff*> staffs;
    public:
        Department(string nameVal = "", string locationVal = "", vector<Staff*> staffsVal = {})
        : name(nameVal), location(locationVal), staffs(staffsVal) {}

        void showInfo() {
            cout << "\nDept name: " << name << ", Location: " << location << ", Current staffs: ";
            for (auto eachStaff : staffs) {
                cout << eachStaff->name << " ";
            }
            cout << "\n";
        }

        friend class Staff;
};

// Define join and leave methods of Staff class (after the class Department has been fully defined)
void Staff::joinDept(Department &dept) {
    // Insert current staff into the list
    dept.staffs.push_back(this);

    // Update the department name of the staff
    deptName = dept.name;
}

void Staff::leaveDept(Department &dept) {
    // Find and remove current staff from the list
    for (int i = 0; i < dept.staffs.size(); i++) {
        if (dept.staffs[i] == this) {
            dept.staffs.erase(dept.staffs.begin() + i);
        }
    }

    // Remove the department name of the staff
    deptName = "";  // Assign it by an empty string
}

// Academic Department (subtype of Department)
class AcademicDepartment : public Department {
    private:
        int numOfCourses;
    public:
        // Constructor
        AcademicDepartment(string nameVal = "", string locationVal = "", vector<Staff*> staffsVal = {}, int numOfCoursesVal = 0)
        : Department(nameVal, locationVal, staffsVal), numOfCourses(numOfCoursesVal) {};

        void showInfo() {
            Department::showInfo();   // Reuse the function of parent class
            cout << "> Num of courses: " << numOfCourses << "\n"; 
        }
};

// Non-academic Department (subtype of Department)
class NonAcademicDepartment : public Department {
    private:
        int numOfServices;
    public:
        NonAcademicDepartment(string nameVal = "", string locationVal = "", vector<Staff*> staffsVal = {}, int numOfServicesVal = 0)
        : Department(nameVal, locationVal, staffsVal), numOfServices(numOfServicesVal) {}

    void showInfo() {
        Department::showInfo();     // Reuse the function of parent class
        cout << "> Num of services: " << numOfServices << "\n";
    }
};

int main() {
    Staff staff1("staff 1", "");
    Staff staff2("staff 2", "");
    Staff staff3("staff 3", "");
    
    AcademicDepartment dept1("SSET", "Building 2", {}, 10);
    NonAcademicDepartment dept2("ITS",  "Building 1", {}, 5);

    staff1.joinDept(dept1);
    staff2.joinDept(dept2);
    staff3.joinDept(dept1);

    dept1.showInfo();
    dept2.showInfo();

    return 0;
}