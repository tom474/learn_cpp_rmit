// WORKING WITH FILE

#if 0

#include <iostream>
#include <fstream>

using std::cout;

int main() {
    char word[100], str[100];

    // Create and open a file (use write mode only to create file).
    std::fstream myFile;
    myFile.open("myFile.dat", std::ios::out);

    if (!myFile) {
        std::cerr << "Fail to create/open file \n";
        return -1;
    }

    // Write to file
    int num = 10;
    myFile << num << " Hello. How are you?";
    myFile.close(); // Close the file
    cout << "Wrote to the file!\n" << std::endl;

    // Read from file
    myFile.open("myFile.dat", std::ios::in);
    myFile >> num >> word; // Read an integer and a word

    myFile.ignore(100, ' '); // Ignore some spaces
    myFile.getline(str, sizeof(str)); // Read to the end of line

    cout << "Read from file: " << std::endl;
    cout << num << " " << word << " " << str << "\n";

    myFile.close(); // Close the file

    return 0;
}

#endif


#if 0

#include <iostream>
#include <fstream>

using std::cout;
using std::cin;

int main() {
    int yourAge;
    char yourName[100];

    std::ofstream myFile; // Declare an ofstream object
    myFile.open("myFile.txt", std::ios::out);

    if (!myFile) {
        std::cerr << "Fail to open file\n";
        return -1;
    }

    // Write to file
    myFile << "Saving to file ..." << std::endl; // Flush to write immediately

    // Read from console and write to file
    cout << "Enter your age: ";
    cin >> yourAge;
    myFile << yourAge << std::endl;

    cout << "Enter your name: ";
    cin.ignore(1, '\n'); // Ignore previous "\n" character
    cin.getline(yourName, sizeof(yourName));
    myFile << yourName << "\n";

    cout << "Saved your answers to file!";

    myFile.close(); // Close file

    return 0;
}

#endif