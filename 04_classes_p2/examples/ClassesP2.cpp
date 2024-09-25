// FUNCTION OVERLOADING
#if 0

#include <iostream>

using std::cout;
using std::string;

class BankAcc {
    public:
        string name = "";
        int amount = 0;

        // Function overloading: 2 versions for the constructor
        BankAcc(string nameVal = "", int amountVal = 0)  // v1
        : name(nameVal), amount(amountVal) {}
        
        BankAcc(int amountVal = 0) // v2
        : amount(amountVal) {}

        void showInfo() {
            cout << "Name = " << name << "\n";
            cout << "Amount = " << amount << "\n";
        }
};

int main() {
    BankAcc myAcc1("Vietcombank");   // v1
    myAcc1.showInfo();

    BankAcc myAcc2(1000000);    // v2
    myAcc2.showInfo();

    return 0;
}

#endif


// "THIS" KEYWORD
#if 0

#include <iostream>

using std::cout;
using std::string;

class BankAcc {
    public:
        string name = "";
        int amount = 0;

        // Function overloading: 2 versions for the constructor
        BankAcc(string name = "", int amount = 0) { // v1
            this->name = name;
            this->amount = amount;
        }

        BankAcc(int amount = 0) {   // v2
            this->amount = amount;
        }

        void showInfo() {
            cout << "Name = " << name << "\n";
            cout << "Amount = " << amount << "\n";
        }
};

int main() {
    BankAcc myAcc1("Vietcombank");   // v1
    myAcc1.showInfo();

    BankAcc myAcc2(1000000);    // v2
    myAcc2.showInfo();

    return 0;
}

#endif


// OVERLOADING UNARY OPERATOR (it only have one operand: ++ -- !, x++)
#if 0

#include <iostream>

using std::cout;
using std::string;

class BankAcc {
    public:
        string name = "";
        int amount = 0;

        BankAcc(string nameVal = "", int amountVal = 0)
        : name(nameVal), amount(amountVal) {}
        
        // Overload ++ when used as prefix (++object)
        BankAcc operator ++ () {
            amount++;
            return *this;   // Return the current object
        }

        // Overload ++ when used as postfix (object++)
        BankAcc operator ++ (int) {
            BankAcc temp = *this;
            amount++;
            return temp;    // Have amount without increasing
        }

        // Define extra function to print out info
        string toString() {
            return "Name = " + name + ", Amount = " + std::to_string(amount);
        }
};

int main() {
    // Postfix explanation:
    int num = 10;
    int x = num++;  // Result = ?
    cout << x << "\n";

    BankAcc acc1("VCB", 1000), acc2("VPB", 2000);
    BankAcc result;

    // Use the overloading operator ++ as prefix
    result = ++acc1;
    cout << result.toString() << "\n";

    // Use the overloading operator ++ as suffix
    result = acc2++;
    cout << result.toString() << "\n";

    return 0;
}

#endif


// OVERLOADING BINARY OPERATOR
#if 0

#include <iostream>

using std::cout;
using std::string;

class BankAcc {
    public:
        string name = "";
        int amount = 0;

        BankAcc(string nameVal = "", int amountVal = 0)
        : name(nameVal), amount(amountVal) {}

        string toString() {
            return "Name = " + name + ", Amount = " + std::to_string(amount);
        }

        // Overload + operator (object + object)
        BankAcc operator + (BankAcc acc2) {
            BankAcc temp;

            // Same name: add amounts
            if (this->name == acc2.name) {
                temp.name = this->name;
                temp.amount = this->amount + acc2.amount;
                return temp;
            }

            // Name is difference: return an object with empty attributes
            std::cerr << "Cannot add accounts: names are different!\n";
            return temp;
        }

        // Overload + operator (object + int)
        BankAcc operator + (int num) {
            BankAcc temp;
            temp.name = this->name;
            temp.amount = this->amount + num;
            return temp;
        }
};

int main() {
    BankAcc acc1("VCB", 1000), acc2("VPB", 2000), acc3("VIB", 5000);
    BankAcc result;

    // Use the overloading operator + (object + object)
    result = acc1 + acc2;   // Sum acc1 and acc2 --> assign the result to result acc
    cout << result.toString() << "\n\n";

    // Use the overloading operator + (object + int)
    result = acc1 + 10000;
    // result = 10000 + acc1;  // Not supported
    cout << result.toString() << "\n\n";

    return 0;
}

#endif


// FRIEND FUNCTION
#if 0

#include <iostream>

using std::cout;

class Distance {
    private:
        int meter;
    public:
        Distance()
        : meter(0) {}    // A constructor

        friend int addFive(Distance d); // Non-member friend function
};

// Definition of the function
int addFive(Distance d) {
    // Access private members from the friend function
    d.meter += 5;
    return d.meter;
}

int main() {
    Distance dist;
    cout << "> Distance: " << addFive(dist);

    return 0;
}

#endif


// OVERLOADING OPERATOR AS A FRIEND FUNCTION
#if 0

#include <iostream>

using std::cout;
using std::string;

class Point2D {
    private:
        int x, y;   // 2D coordinates
    public:
        Point2D(int xVal = 0, int yVal = 0)   // Constructor
        :x(xVal), y(yVal) {}
        
        // Declare operator overloading functions as Friends
        friend Point2D operator + (Point2D point, int num); // Allows Point2D + int
        friend Point2D operator + (int num, Point2D point); // Allows int + Point2D

        // Member function
        string toString() {
            return "x = " + std::to_string(x) + ", y = " + std::to_string(y);
        }
};

// Define the operator overloading function for Point2D + int
Point2D operator + (Point2D point, int num) {
    Point2D temp;
    temp.x = point.x + num;
    temp.y = point.y + num;
    return temp;
}

Point2D operator + (int num, Point2D point) {
    return point + num;
}

int main() {
    Point2D pointA(100, 200), pointB;

    pointB = 20 + pointA;
    cout << "\nValue of pointB: " << pointB.toString();

    pointB = pointA + 30;
    cout << "\nValue of pointB: " << pointB.toString();

    return 0;
}

#endif


// FRIEND CLASS
#if 0

#include <iostream>

using std::cout;
using std::string;

class ClassA {
    private:
        int numA = 10;
    public:
        // Declare another class is a friend
        friend class ClassB;
};

class ClassB {
    private:
        int numB = 20;
    public:
        // Access private members of classA from the friend class
        int add(ClassA objA) {
            return objA.numA + this->numB;
        }
};

int main() {
    ClassA objA;
    ClassB objB;

    cout << "> Sum: " << objB.add(objA);

    return 0;
}

#endif


// STATIC CLASS MEMBER
#if 0

#include <iostream>

using std::cout;
using std::string;

class Car {
    public:
        string name;
        int price;

        static int objCount;    // Static attribute
        static int getCount() { // Static member function
            return objCount;
        }

        Car(string name, int price) {
            this->name = name;
            this->price = price;
            objCount++;
        }
};

// Initialize static attribute
int Car::objCount = 0;

int main() {
    cout << "Number of Car objects: " << Car::objCount << "\n";
    Car car1("BMW", 10000), car2("Ferrari", 50000);
    cout << "Number of Car objects: " << Car::objCount << "\n";

    return 0;
}

#endif