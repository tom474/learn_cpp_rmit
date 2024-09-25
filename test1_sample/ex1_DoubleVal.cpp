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
#include <sstream>
#include <iomanip>

// Define constants for difference formats of input string
#define INT_TYPE 0
#define FLOAT_TYPE 1
#define HEXA_TYPE 2

using std::cout;
using std::string;

// 1st version with int input
int doubleVal(int num) {
    return num * 2; 
}

// 2nd version with floating point input
double doubleVal(double num) { 
    return num * 2; 
}

// 3rd version with input is string (represented hexa number, e.g. "0xAC") 
int doubleVal(char hexaStr[]) {
    int val;

    std::stringstream sstr;
    sstr << std::hex << hexaStr;    // Input the string to the stringstream (with hex format)
    sstr >> val;    // Extract value from the stringstream (with int format)

    return val * 2;
}

// Check the format of number represented in the string
int checkType(string num) {
    // Check hexa
    if (num[0] == '0' && tolower(num[1]) == 'x') {
        return HEXA_TYPE;
    }

    // Check floating type
    for (int i = 0; i < num.length(); i++) {
        if (num[i] == '.') {
            return FLOAT_TYPE;
        }
    }

    return INT_TYPE;    // int by default
}

int main(int argc, char *argv[]) {
    int type = checkType(argv[1]);  // Check format of input string (got from command line argument)

    if (type == HEXA_TYPE) { // hexa
        cout << std::showbase << std::hex << doubleVal(argv[1]);

    } else if (type == FLOAT_TYPE) { // floating point
        cout << std::fixed << std::setprecision(2) << doubleVal(std::stod(argv[1]));

    } else { // integer
        cout << doubleVal(std::stoi(argv[1]));
    }

  return 0;
}