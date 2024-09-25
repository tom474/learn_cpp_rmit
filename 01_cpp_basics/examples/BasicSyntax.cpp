/*
    GUIDE:
    #if (condition) ... #endif are preprocessing conditional statement
    to controls complication of a source file.

    If the (condition) is true, he inside code block will be enable for complication, and vice versa.
    --> Change #if 0 to #if 1 or vice versa to enable/disable code block.
*/


// EXAMPLE 1: BASIC INPUT/OUTPUT
#if 0

#include <iostream>

using std::cout;
using std::cin;

int main() {
    char a;
    int num;

    cout << "Enter a character and an integer: ";
    cin >> a >> num;

    cout << "Character: " << a << "\n";
    cout << "Number: " << num << "\n";
    return 0;
}

#endif


// EXAMPLE 2: WHILE LOOP
#if 0

#include <iostream>

using std::cout;

int main() {
    int i = 1;
    while (i <= 10) {
        cout << i << " ";
        i++;
    }
    return 0;
}

#endif


// EXAMPLE 3: DO-WHILE LOOP
#if 0

#include <iostream>

using std::cout;

int main() {
    int i = 1;
    do {
        cout << i << " ";
        i++;
    } while (i <= 10);
    return 0;
}

#endif


// EXAMPLE 4: FOR LOOP
#if 0

#include <iostream>

using std::cout;

int main() {
    for (int i = 1; i < 10; i++) {
        if (i == 5) {
            continue;
        } else if (i == 9) {
            break;
        }
        cout << i << " ";
    }
    return 0;
}

#endif


// EXAMPLE 5: C-TYPE STRING
#if 0

#include <iostream>
#include <cstring>

using std::cout;

int main() {
    // strcmp() example code:
    char str1[100] = "ABC";
    char str2[100] = "DEF";
    cout << "strlen of str1 = " << strlen(str1) << "\n";

    cout << "strcmp = " << strcmp(str1, str2) << "\n";

    strcat(str1, str2);
    cout << "str1 after strcat = " << str1 << "\n";

    strcpy(str1, str2);
    cout << "str1 after strcpy = " << str1 << "\n";
    return 0;
}

#endif