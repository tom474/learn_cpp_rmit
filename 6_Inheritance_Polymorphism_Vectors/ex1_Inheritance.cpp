#include <iostream>
#include <sstream>

using std::cin;
using std::cout;
using std::string;

class Student {
    protected:
        string name;
        int studentId;
    public:
        Student(string nameVal = "", int studentIdVal = 0)
        : name(nameVal), studentId(studentIdVal) {
            cout << "Constructor of Student class\n";
        }

        ~Student() {
            cout << "Destructor of Student class\n";
        }

        virtual string toString() { // Virtual function
            std::stringstream sstr;
            sstr << "name = " << name << ", student ID = " << studentId;
            return sstr.str();  // Get the string content from the stringstream
        }
};

class Staff {
    protected:
        string name;
        int staffId;
    public:
        Staff(string nameVal = "", int staffIdVal = 0)
        :name(nameVal), staffId(staffIdVal) {
            cout << "Constructor of Staff class\n";
        }

        ~Staff() {
            cout << "Destructor of Staff class\n";
        }

        virtual string toString() { // Virtual function
            std::stringstream sstr;
            sstr << "name = " << name << ", staff ID = " << staffId;
            return sstr.str();
        }
};

class Tutor : public Student, public Staff {    // Inherits from Student and Staff
// Inherited attributes: Student::name, studentId  ;   Staff::name, staffId
    public:
        Tutor(string nameVal = "", int studentIdVal = 0, int staffIdVal = 0)
        : Student(nameVal, studentIdVal), Staff(nameVal, staffIdVal) {
            cout << "Constructor of Tutor class\n";
        }

        void consultation() {
            cout << "Doing consultation\n";
        }

        void setName(string nameVal) {
            Student::name = nameVal;
            Staff::name = nameVal;
        }

        ~Tutor() {
            cout << "Destructor of Tutor class\n";
        }

        virtual string toString() { // Function overriding
            std::stringstream sstr;
            sstr << "name = " << Student::name << ", staff ID = " << staffId << ", student ID = " << studentId;
            return sstr.str();
        }
};

void showInfoStudent(Student &stu) {
    cout << stu.toString() << "\n";
}

void showInfoStaff(Staff &staff) {
    cout << staff.toString() << "\n";
}

int main() {
    Student stu1("Harry", 111);
    Staff sta1("James", 222);
    Tutor tut1("John", 123, 345);

    showInfoStudent(stu1);
    showInfoStaff(sta1);

    showInfoStudent(tut1);
    showInfoStaff(tut1);

    return 0;
}