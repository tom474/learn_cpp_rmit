// REVIEW: FUNCTION OVERLOADING
#if 0

#include <iostream>

using std::cout;

// 1st version with "int" data type
int add(int num1, int num2) {
    return (num1 + num2);
}

// 2nd version with "double" data type
double add(double num1, double num2) {
    return (num1 + num2);
}

int main() {
    // Call function with int data type
    int result1;
    result1 = add(2, 3);
    cout << result1 << "\n";

    // Call function with double data type
    double result2;
    result2 = add(2.2, 3.3);
    cout << result2 << "\n";

    return 0;
}

#endif


// FUNCTION TEMPLATE
#if 0

#include <iostream>

using std::cout;

// Function template (one generic version)
template <typename type>
type add(type num1, type num2) {
    return (num1 + num2);
}

int main() {
    // Call function with int data type
    int result1;
    result1 = add<int>(2, 3);
    cout << result1 << "\n";

    // Call function with double data type
    double result2;
    result2 = add<double>(2.2, 3.3);
    cout << result2 << "\n";

    return 0;
}

#endif


// MULTIPLE GENERIC DATA TYPE & TYPE CHECK
#if 0

#include <iostream>

using std::cout;
using std::is_same;

// Function template (one generic version)
template <typename type1, typename type2>
double add(type1 num1, type2 num2) {
    // Type check
    if (is_same<type1, int>::value) {
        cout << "num1 is of int type\n";
    } else {
        cout << "num1 is of another data type\n";
    }
    return (num1 + num2);
}

int main() {
    // Call function with different data types
    cout << add<int, int>(2, 3) << "\n";
    cout << add<int, double>(2, 3.2) << "\n";
    cout << add<double, int>(2.5, 3) << "\n";

    return 0;
}

#endif


// TEMPLATE NON-TYPE ARGUMENT
#if 0

#include <iostream>

using std::cout;

// In this example, DISC_PERCENT is non-type argument
// Note: non-type arguments for a template must be a constant, usually an integer (floating point values are not allowed)
template <typename type, int DISC_PERCENT>
type discountedValue(type amount) {
    return amount - amount * DISC_PERCENT / 100;
}

int main() {
    cout << discountedValue<int, 10>(1000) << "\n";
    cout << discountedValue<float, 20>(1000.0) << "\n";

    return 0;
}
#endif


// TEMPLATE SPECIFICATION
#if 0

#include <iostream>

using std::cout;

// Function template (one generic version)
template <typename type>
type myFunct(type num1, type num2) {
    return (num1 + num2);
}

// Template specification (for char data type)
template <>
char myFunct(char num1, char num2) {
    return (num1 - num2);
}

int main() {
    // Call function with int data type
    cout << myFunct<int>(60, 2) << "\n";

    // Call function with char data type
    cout << myFunct<char>(60, 2) << "\n";

    return 0;
}

#endif 