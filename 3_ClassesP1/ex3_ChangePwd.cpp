#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::string;

class Student {
    private:
        int score;
        string password;
    public:
        string name;

        Student(string nameVal = "", int scoreVal = 0, string pwdVal = "")
        : name(nameVal), score(scoreVal), password(pwdVal){}
        
        void showInfo() {
            cout << "Name = " << name << ", Score = " << score << "\n";
        }

        int getScore() {
            return score;
        }

        // Method the change password
        void changePwd() {
            // Check if there is an existing password
            std::fstream myFile;
            myFile.open(name + ".dat", std::ios::in);

            if (myFile) {
                std::getline(myFile, password); // Read a line from the file
            }
            myFile.close();

            if (password == "") {   // No existing password
                cout << "No existing password. Please set your password now: ";
            } else {    // We have existing password
                cout << "Please enter your current password: ";
                string in_pwd;
                std::getline(cin >> std::ws, in_pwd); // Read a line and store to in_pwd string

                if (in_pwd == password) {   // User enter correct password
                    cout << "Correct. Now set your new password: ";
                } else {    // User enter wrong password
                    std::cerr << "Incorrect Password";
                    return;
                }
            }

            // Allow user to set the new password
            std::getline(cin >> std::ws, password); // Read a line and store to password string

            myFile.open(name + ".dat", std::ios::out);  // Open the file for writing
            myFile << password; // Save into the file
            myFile.close(); 
        }
};

int main() {
    // Test the class method
    Student stu("Cuong Tran", 100);
    stu.changePwd();
    stu.changePwd();

    return 0;
}