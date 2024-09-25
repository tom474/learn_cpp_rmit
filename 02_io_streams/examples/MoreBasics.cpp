/*
    GUIDE: 
    #if (condition) ... #endif are preprocessing conditional statement 
    to controls compilation of a source file.

    If the (condition) is true, the inside code block will be enabled for compilation, and vice versa.
    --> Change #if 0 to #if 1 or vice versa to enable/disable code block.
*/


// EXAMPLE 1: DEFINE & USE FUNCTION
#if 0

#include <iostream>

using std::cout;
using std::cin;

// Function definition
int max(int x, int y) {
    return (x > y) ? x : y;
}

int main() {
    int a, b, c, maxVal;
    cout << "Enter three integers: ";
    cin >> a >> b >> c;

    maxVal = max(max(a, b), c);
    cout << "Largest value is " << maxVal << "\n\n";

    return 0;
}

#endif


// EXAMPLE 2: PASS BY VALUE/ POINTER/ REFERENCE
#if 0

#include <iostream>

using std::cout;

int num = 10; // global variable

void func1(int x) { // x is passed by value
    x = 10;
    cout << "x in func1 = " << x << "\n"; // ???
}

void func2(int *x) { // x is passed by pointer
    *x = 20;
    cout << "x in func2 = " << *x << "\n";
}

void func3(int &x) { // x is passed by reference
    x = 30 + num;
    cout << "x in func3 = " << x << "\n"; // ?
}

int main() {
    int val = 0;
    cout << "val in main = " << val << "\n\n";

    func1(val); // pass by value: value of val is copied to x
    cout << "val after func1 call = " << val << "\n\n";

    func2(&val); // pass by pointer: address of val is copied to pointer x
    cout << "val after func2 call = " << val << "\n\n";

    func3(val); // pass by reference: x is reference of val (like an alias)
    cout << "val after func3 call = " << val << "\n\n";

    return 0;
}

#endif


// EXAMPLE 3: ARRAY & POINTER
#if 0

#include <iostream>

using std::cout;

int main() {
    char str[80] = "Hello World"; // Create a character array called str
    char *p = str;                // Declare and initialize a character pointer
    str[4] = 'X';                 // or *(str + 4) = 'X'; - replace the fourth element with 'X' character
    *(p + 5) = 'Y';               // or p[5] = 'Y;        - replace the fifth space with 'Y' character
    cout << str << "\n";

    // Going through array/string elements using pointer 
    char str2[80] = "Hello World";          // Create a character array call str2
    for (char *p = str2; *p != '\0'; p++) { // Pointer arithmetic, iterates through string elements
        cout << *p;                         // Display contents of pointer to screen
    }

    return 0;
}

#endif