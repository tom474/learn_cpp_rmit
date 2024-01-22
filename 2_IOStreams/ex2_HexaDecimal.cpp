#include <iostream>
#include <cstring>

using std::cout;

int main(int argc, char *argv[]) {
    if (argc != 2) { // Require two arguments, argv[0] by default and argv[1] (hexa num)
        cout << "> Invalid number of user argument\n";
        return -1;
    }

    char *hexNum = argv[1]; // a pointer of char pointed to argv[1] (can be used as a string)
    // To test: cout << "hexNum = " << hexNum;

    if (strlen(hexNum) <= 2) {
        cout << "> Do not have hexa digits\n";
        return -2; // Another error code for another error type
    }

    // Check first two character ("0x" or "0X")
    if (strncmp(hexNum, "0x", 2) != 0 && strncmp(hexNum, "0X", 2) != 0) {
        cout << "> Do not have 0x/0X\n";
        return -3;
    }

    // Check for all hexa digits (must be 0-9, A-Z --> use isxdigit function)
    for (int i = 2; i < strlen(hexNum); i++) {
        if (!isxdigit(hexNum[i])) {
            cout << "> Invalid hexa digit \n";
            return -4;
        }
    }

    // Correct format (passed all checking above)
    cout << "Got valid hex num: " << hexNum;

    return 0;
}