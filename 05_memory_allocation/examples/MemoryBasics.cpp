// DYNAMIC MEMORY ALLOCATION
#if 0

#include <iostream>

using std::cout;
using std::cin;

class Student {
    public:
        int score;
};

int main() {
    int size;
    cout << "Enter total number of students: ";
    cin >> size;

    // Memory allocation for an array
    Student* ptr = new Student[size];

    // Store and read values
    cout << "Enter scores of students: " << "\n";
    for (int i = 0; i < size; ++i) {
        cout << "Student " << i + 1 << ": ";
        cin >> ptr[i].score;    // Store values
        cout << "> Stored: " << ptr[i].score << "\n";   // Read values
    }

    // Free up memory location (allocated for ptr before)
    delete[] ptr;

    return 0;
}

#endif


// DESTRUCTOR & DYNAMIC MEMORY ALLOCATION
#if 0

#include <iostream>

using std::cout;
using std::string;

class Data {
    private:
        string name;
        int* arr;
    public:
        Data(string nameVal)
        :name(nameVal) { // Constructor
            cout << "Constructor of " << name << " is called\n";
            arr = new int[1000];    // Dynamic memory allocation
        };

        ~Data() {   // Destructor
            cout << "Destructor of " << name << "is called\n\n";
            delete[] arr;   // Remove this one will cause Memory Leak (computer hang)
        };
};

// A function with local object to test
void myFunc(int i) {
    string name = "data" + std::to_string(i);
    Data myData(name); 
}

int main() {
    // Call the function many times
    for (int i = 0; i < 100000000; i++) {
        myFunc(i);
    }

    return 0;
}

#endif


// TRY CATCH TO HANDLE EXCEPTION
#if 0

#include <iostream>

using std::cin;
using std::cout;

int main() {
    try {   // All code you want to handle possible exceptions
        // Request memory allocation (very large size will throw bad_alloc exception)
        int *ip = new int[1000000000000000];

        int age;
        cout << "Enter age: ";
        cin >> age;
        if (age <= 16) {
            throw 101;  // Throw a custom error code (here is an integer value)
        }
    } catch (std::bad_alloc& ba) {  // Handles std::bad_alloc exception
        std::cerr << "bad_alloc exception caught: " << ba.what() << '\n';
    } catch (int errorCode) {   // Handle custom exception
        std::cerr << "Access denied (16+). Error Code: " << errorCode;
    } catch (...) { // Handle all other generic exceptions
        std::cerr << "Generic Exceptions!\n";
    }
    
    return 0;
}

#endif


// RANGE-BASED FOR LOOP
#if 0

#include <iostream>

using std::cout;
using std::string;

int main() {
    // Iterate through a braced list (by value)
    for (int i : {0, 1, 2, 3, 4, 5}) {
        cout << i << " ";
    }
    cout << "\n";

    // Iterate through the array (by value)
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i : arr) {
        cout << i << " ";
    }
    cout << "\n";

    // Iterate through a string (by value)
    // "auto" keyword: type is automatically inferred from the range
    string str1 = "Hello!";
    for (auto ch : str1) {
        cout << ch << " ";
    }
    cout << "\n";

    // Iterate through a string (by reference);
    string str2 = "Hello!";
    for (auto &ch : str2) {
        if (ch == 'l') {
            ch = 'L';
        }
    }
    cout << str2 << "\n";

    return 0;
}

#endif


// UNIONS
#if 0

#include <iostream>

using std::cout;

union u_type {
    int intNum;
    char charArr[4];
};

int main() {
    u_type myUnion;
    std::cout << "Size = " << sizeof(u_type) << "\n";

    // Access intNum elements
    myUnion.intNum = 0x00434241;    // 0x41-43 is ASCII value of 'A' - 'D'

    // Access charArr elements
    cout << myUnion.charArr << "\n";
    cout << myUnion.charArr[0] << "\n";
    cout << myUnion.charArr[1] << "\n";
    cout << myUnion.charArr[2] << "\n";
    cout << myUnion.charArr[3] << "\n"; // Last one is 0 (NULL character)

    return 0;
}

#endif


/*
    PASS & RETURN BY REFERENCE
    Example: overload >> operator so that:
        (n >> object)       : increase value in obj by n (n is an integer)
        m >> (n >> object)  : increase value in obj by n + m
*/
#if 0

#include <iostream>

using std::cout;
using std::string;

class Acc {
    public:
        int amount;

        Acc(int amountVal = 0)
        : amount(amountVal) {};  // Constructor
        
        void showInfo() {
            cout << "Amount = " << amount << "\n";
        }
        // Note: should declare friend for external funct if attribute is private
};

// Operator overloading: int n >> obj
// PASS & RETURN BY VALUE: DOES NOT WORK
#if 0
Acc operator >> (int n, Acc obj) {
    cout << "Pass by value. memory address of obj param = " << &obj << "\n";

    obj.amount = obj.amount + n;
    return obj; 
}
#else
// PASS & RETURN BY REFERENCE: CORRECT!
Acc &operator >> (int n, Acc &obj) {
    cout << "Pass by reference. memory address of obj param = " << &obj << "\n";

    obj.amount = obj.amount + n;
    return obj;
}
#endif

int main() {
    Acc acc1(1000);
    cout << "memory address of acc1 arg = " << &acc1 << "\n";

    // Require pass by reference
    500 >> acc1;    // Should have 1500 in acc1
    acc1.showInfo();

    // Require pass and return by reference
    200 >> (500 >> acc1);   // Should have 2200 in acc1
    acc1.showInfo();

    return 0;
}

#endif


/*
    WHAT IS REFERENCES?
    A reference is an alias (another name) for an already existing variable
    (won't require new memory location when creating a reference)
*/
#if 0

#include <iostream>

using std::cout;

int main() {
    int x = 5;
    int &xRef = x;

    x = 10;
    cout << "x = " << x << ", xRef = " << xRef << "\n";

    xRef = 20;
    cout << "x = " << x << ", xRef = " << xRef << "\n";

    return 0;
}

#endif