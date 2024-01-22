#include <iostream>

using std::cin;
using std::cout;
using std::string;

class Student {
    private:
        int score;      // Private attribute
    public:
        string name;    // Public attribute

        // Constructor
        Student(string nameVal = "", int scoreVal = 0)
        :name(nameVal), score(scoreVal){}
        
        // Public method
        void showInfo() {
            cout << "Name = " << name << ", Score = " << score << "\n";
        }

        // Provide access to the score (read only)
        int getScore() {
            return score;
        }
};

int main() {
    Student stu1("Cuong Tran", 100), stu2("Tom Tran", 99);
    cout << "Two students:\n";
    stu1.showInfo();
    stu2.showInfo();

    Student stuArr[3] = {
        Student("Cuong Tran", 100),
        Student("Tom Tran", 99),
        Student("emsignouc", 98)
    };

    // Print out info of all students
    cout << "\nAll students in the array:\n";
    for (int i = 0; i < 3; i++) {
        stuArr[i].showInfo();
    }

    // Check highest score
    Student maxStu = stuArr[0];    // Assume stu0 is the one with highest score
    for (int i = 1; i < 3; i++) {   // Compare the score with other student's scores 
        if (maxStu.getScore() < stuArr[i].getScore()) {
            maxStu = stuArr[i];
        }
    }

    cout << "\nStudent with highest score in the array:\n";
    maxStu.showInfo();

    return 0;
}