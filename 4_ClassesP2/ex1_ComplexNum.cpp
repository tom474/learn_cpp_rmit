#include <iostream>
#include <cmath>

using std::cout;

// Complex numbers e.g: 3 + 4i  100 + 50i
class ComplNum {
    private:
        double real;
        double imag;
    public:
        ComplNum() {};  // Default constructor with no parameters

        ComplNum(double realVal, double imagVal)
        : real(realVal), imag(imagVal) {} // Normal constructor

        void showInfo() {   // Print out information
            cout << real << ((imag >= 0) ? " + " : " ") << imag << "i\n";
        }

        // Overloading the - operator (object1 - object2) --> return object
        // e.g: (10 + 5i) - (2 + 2i) = (8 + 3i)
        ComplNum operator - (ComplNum num2) {
            ComplNum result;
            result.real = this->real - num2.real;
            result.imag = this->imag - num2.imag;
            return result;
        }

        // Overloading the - operator (object - double) --> return object
        // e.g: (10 + 5i) - (5) = (5 + 5i)
        ComplNum operator - (double num) {
            ComplNum result;
            result.real = this->real - num;
            result.imag = this->imag;
            return result;
        }

        // Overloading the - operator (double - object) --> return object
        friend ComplNum operator - (double num1, ComplNum num2); // External

        // Overloading the -- operator (--object) --> return object (after -1)
        ComplNum operator -- () {
            this->real--;
            return *this;
        }

        // Overloading the -- operator (object--) --> return object (before -1)
        ComplNum operator -- (int) {
            ComplNum temp = *this;  // Get value of current object
            this->real--;
            return temp;    // Return previous values
        }

        // Declare an external function as a friend
        friend double absVal(ComplNum num);
};

// Overloading the - operator (double - object) --> object
// e.g: (5) - (10 - 5i) = (-5 - 5i)
ComplNum operator - (double num1, ComplNum num2) {
    ComplNum result;
    result.real = num1 - num2.real;
    result.imag = -num2.imag;
    return result;
}

// Function to calculate the absolute value
double absVal(ComplNum num) {
    return std::sqrt(num.real * num.real + num.imag * num.imag);
}

int main() {
    ComplNum num1(100, 5);
    ComplNum num2(5.5, 10.5);
    cout << "Num1: ";
    num1.showInfo();
    cout << "Num2: ";
    num2.showInfo();

    ComplNum result;

    result = num1 - num2;
    cout << "\nNum1 - Num2:\t";
    result.showInfo();

    result = num1 - 2;
    cout << "\nNum1 - 2:\t";
    result.showInfo();

    result = 10 - num1;
    cout << "\n10 - Num1:\t";
    result.showInfo();

    result = --num1;
    cout << "\n--Num1 :\t";
    result.showInfo();

    result = num2--; //--> result = ?
    cout << "\nResult = Num2--: \n";
    cout << "Num2 = ";
    num2.showInfo();
    cout << "Result = ";
    result.showInfo();

    cout << "\nAbsolute value of num1: " << absVal(num1);

    return 0;
}