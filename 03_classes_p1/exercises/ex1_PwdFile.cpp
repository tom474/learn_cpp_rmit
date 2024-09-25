#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::string;

int main() {
    std::fstream myFile;
    string pwd;
    int choice;

    cout << "Password management program:\n";
    cout << "1. Save your password\n";
    cout << "2. Read your password\n";
    cout << "Your choice: ";
    cin >> choice;

    if (choice == 1) {  // Save your password
        myFile.open("pwd.dat", std::ios::out);

        if (!myFile) {
            cout << "Fail to create/open file\n";
            return -1;
        }

        // Get the password from the console and save to file
        cout << "Enter the password: ";
        cin.ignore(1, '\n');    // Ignore previous '\n' entered by user
        getline(cin, pwd);      // Read a line from console

        myFile << pwd;
        myFile.close();
        cout << "Saved to the file!\n";
    } else { // Read your password
        myFile.open("pwd.dat", std::ios::in);
        if (!myFile) {
            cout << "Fail to create/open file\n";
            return -1;
        }

        getline(myFile, pwd);   // Read a line from file
        myFile.close();
        cout << "Read your password from the file: " << pwd << "\n";
    }

    return 0;
}