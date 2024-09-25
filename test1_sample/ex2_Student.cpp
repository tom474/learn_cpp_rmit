/*
    RMIT University Vietnam
    Course: EEET2482/COSC2082
    Semester: 2023-3
    Lab Assessment: 1
    Author: Tran Manh Cuong
    ID: 3974735
    Compiler used: g++ 8.1.0
    Created  date: 01/12/2023
    Acknowledgement: Canvas
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

#define NUM_SCORES 3

using std::cin;
using std::cout;
using std::string;

class Student {
    private:
        string name;
        int scores[NUM_SCORES];

    public:
        // Constructor
        Student(string nameVal = "", int scoresVal[] = nullptr)
        : name(nameVal) {
            if (scoresVal != nullptr) {
                for (int i = 0; i < NUM_SCORES; i++) {
                    scores[i] = scoresVal[i];
                }
            }
        }

        void inputData() {
            cout << "Input name: ";
            getline(cin >> std::ws, name);

            cout << "Input scores: ";
            for (int i = 0; i < NUM_SCORES; i++) {
                cin >> scores[i];
            }
        }

        void showInfo() {
            cout << name << ",";
            for (int i = 0; i < NUM_SCORES; i++) {
                cout << " " << scores[i];
            }
            cout << ", avg = " << std::fixed << std::setprecision(3) << this->avgScore() << "\n";
        }

        friend Student operator + (int n, Student stu);

        double avgScore() {
            int sum = 0;
            for (int i = 0; i < NUM_SCORES; i++) {
                sum += scores[i];
            }

            return (double)sum / NUM_SCORES;
        }

        // object1 > object2
        bool operator > (Student &stu2) {
            return this->avgScore() > stu2.avgScore() ? true : false;
        }

        void setName(string nameVal) {
            name = nameVal;
        }

        void setScores(string scoreVal) {  // Input a string
            std::stringstream sstr;
            sstr << scoreVal;  // Store in stringstream
            for (int i = 0; i < NUM_SCORES; i++) {
                sstr >> scores[i];  // Extract each number from stringstream
            }
        }
};

// cin >> object: first operand is not an object of the class
std::istream &operator >> (std::istream &is, Student &stu) {
    stu.inputData();
    return is;
}
  
// cout << object: first operand is not an object of the class
std::ostream &operator << (std::ostream &os, Student &stu) {
    stu.showInfo();
    return os; 
}     

// int n  + object: return a result object that has same name, but all scores are increased by n.
Student operator + (int n, Student stu) {
    Student result = stu;
    for (int i = 0; i < NUM_SCORES; i++) {
        result.scores[i] += n;
    }
    return result;
}

int main() {
    std::fstream myFile;
    Student stu1, stu2;

    stu1.inputData();
    cout << "> Qa. Student 1's info: ";
    stu1.showInfo();

    cin >> stu2;
    cout << "> Qb. Student 2's info: " << stu2;

    cout << "\n> Student 1 has "
         << ((stu1 > stu2) ? "higher " : "lower or equal ")
         << "average score than Student 2 \n";

    Student stu3 = 10 + stu2;
    cout << "\n> Student 3's info: " << stu3;

    Student stuArr[10];
    myFile.open("data.txt", std::ios::in);
    if (!myFile) {
        cout << "Fail to open/create file \n";
        return -1;
    }

    // Read in information from the text file
    for (int i = 0; i < 10; i++) {
        string tempStr;
        // Read the name (up to the delimeter ',')
        getline(myFile, tempStr, ',');
        stuArr[i].setName(tempStr);

        // read the scores
        getline(myFile, tempStr);
        stuArr[i].setScores(tempStr);
    }
    myFile.close();

    cout << "\n> Qc. All information read from the file: \n";
    for (int i = 0; i < 10; i++) {
        stuArr[i].showInfo();
    }

    // Find student with highest average value
    Student bestStu = stuArr[0];
    for (int i = 0; i < 10; i++) {
        if (bestStu.avgScore() < stuArr[i].avgScore()) {
            bestStu = stuArr[i];
        }
    }
    cout << "\n> Student with highest average score: \n";
    bestStu.showInfo();

    return 0;
}