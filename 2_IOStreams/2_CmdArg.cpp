/*
    Save with name cmd_arg.cpp
    Compile: g++ cmd_arg.cpp -o hello.exe
    Run: ./hello.exe name1 name2 123456789
*/

// Get and print out all command-line arguments
#include <iostream>

using std::cout;

int main(int argc, const char *argv[]) {
    for (int i = 1; i < argc; i++) {
        cout << "Hello " << argv[i] << "\n";
    }
    
    return 0;
}