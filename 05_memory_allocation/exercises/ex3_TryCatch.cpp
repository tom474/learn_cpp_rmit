#include <iostream>

using std::cin;
using std::cout;

int main() {
    int a, b;
    try {
        cin >> a >> b;
        if (b == 0) {
            throw -1;   // Throw custom error (an integer)
        }
    } catch (int errorcode) {
        std::cerr << "b is 0 !!! Error code: " << errorcode << "\n";
        do {
            cout << "Please enter the value for b again: ";
            cin >> b;
        } while (b == 0);
    }
    cout << "Result a/b: " << (float) a/b << "\n";

    int count = 0;
    cout << "\n\nRequest memory allocation ....\n";

    while(1) {
        // Request memory allocation (1MB = 1024KB = 1024*1024 bytes)
        try {
            char *ip = new char[1024*1024]; // 1MB
            count++;

            // Print out address of allocated memory locations
            cout << "Block " << count << ", address = " << (void *) ip << "\n";
        } catch (std::bad_alloc errorcode) {
            std::cerr << "\nbad_alloc exception caught!\n";
            std::cerr << "Total memory allocated: " << count << "MB\n";
            break;  // Break the while loop
        }
    }

    cout << "\nEnd of program";
 
    return 0;
}