// FIRST EXAMPLE FOR CLASSES AND OBJECTS
#if 0

#include <iostream>

using std::cout;

class Dog {             // The class
    public:                 // Access specifier
        int age;            // AttributeS (int variable)
        bool hungry = true; // Can assign default value
        bool happy;

        void eat() {    // Method (function)
            hungry = false;
            happy = true;
        }

        void info() {   // Method (function)
            cout << "age = " << age << "\n";
            cout << "hungry = " << hungry << "\n";
            cout << "happy = " << happy << "\n";
        }
};

int main() {
    Dog dog1, dog2; // Create objects of Dog

    // Access their variables and functions
    dog1.age = 5;
    dog1.eat();
    cout << "Dog 1's info: " << "\n";
    dog1.info();

    dog2.age = 10;
    cout << "Dog 2's info: " << "\n";
    dog2.info();

    return 0;
}

#endif


// CLASS METHOD DEFINED OUTSIDE
#if 0

#include <iostream>

using std::cout;

class Car {
    public:
        int speed = 100;    // Default value is 100
        int addSpeed(int num); // Declare method
};

int Car::addSpeed(int num) {   // Define method with scope
    speed += num;
    return speed;
}

int main() {
    Car myCar; // Create an object of car
    cout << "myCar's default speed: " << myCar.speed << "\n";
    cout << "myCar's new speed: " << myCar.addSpeed(200) << "\n";
    return 0;
}

#endif


// CONSTRUCTOR METHODS
#if 0

#include <iostream>

using std::cout;

class Car {     // The class
    public:         // Access specifier
        int speed = 100;    // Attribute
        int price = 1000;

        Car() {    // Default constructor with no parameter
            cout << "Default constructor is called \n";
        }

        Car(int speedVal, int priceVal) {    // Parameterized constructor
            cout << "Parameterized constructor is called \n";
            speed = speedVal;
            price = priceVal;
        }
};

int main() {
    // Create Car objects (will call the constructors)
    Car car1;
    Car car2(500, 5000);

    // Print values
    cout << "Car1: speed & price: " << car1.speed << " " << car1.price << "\n";
    cout << "Car2: speed & price: " << car2.speed << " " << car2.price << "\n";

    return 0;
}

#endif


// DEFAULT CONSTRUCTOR WITH DEFAULT ARGUMENTS
#if 0

#include <iostream>

using std::cout;

class Car {     // The class
    public:         // Access specifier
        int speed;  // Attribute
        int price;

        // Default constructor with default arguments
        // Note: we can also use default arguments for some or all parameters of a parameterized constructor or any C++ function
        Car(int speedVal = 100, int priceVal = 1000) {
            cout << "Default constructor is called \n";
            speed = speedVal;
            price = priceVal;
        }

        void showInfo() {
            cout << "speed & price: " << speed << " " << price << "\n";
        }
};

int main() {
    // Create Car objects (will call the constructors)
    Car car1;
    Car car2(500);
    Car car3(500, 5000);

    // Print values
    cout << "Car1: ";
    car1.showInfo();
    cout << "Car2: ";
    car2.showInfo();
    cout << "Car3: ";
    car3.showInfo();

    return 0;
}

#endif


// CONSTRUCTORS WITH MEMBER INITIALIZER LIST
#if 0

#include <iostream>

using std::cout;

class Car {     // The class
    public:         // Access specifier
        int speed;  // Attribute
        int price;

        // Constructor with member initializer list (works for any constructor)
        Car(int speedVal = 100, int priceVal = 1000)
            : speed(speedVal), price(priceVal) {
            cout << "Default constructor is called \n";
        }

        void showInfo() {
            cout << "speed & price: " << speed << " " << price << "\n";
        }
};

int main() {
    // Create Car objects (will call the constructors)
    Car car1;
    Car car2(500);
    Car car3(500, 5000);

    // Print values
    cout << "Car1: ";
    car1.showInfo();
    cout << "Car2: ";
    car2.showInfo();
    cout << "Car3: ";
    car3.showInfo();

    return 0;
}

#endif


// DATA ENCAPSULATION
#if 0

#include <iostream>

using std::cin;
using std::cout;

#define DEFAULT_VAL 100
#define PASSWORD_KEY 12345

class myclass {
    private:    // Private attribute (cannot be accessed directly)
        int num = DEFAULT_VAL;
    public:     // Public functions (to manage access)
        int getNum() {
            return num;
        }

        void setNum(int newVal) {
            int pwd;
            cout << "Enter password: ";
            cin >> pwd;
            if (pwd == PASSWORD_KEY) {
                num = newVal;
                cout << "Set new value successfully!\n";
            } else {
                std::cerr << "Incorrect password!\n";
            }
        }
};

int main() {
    myclass object1;
    cout << "Current num value: " << object1.getNum() << "\n";
    object1.setNum(200);
    cout << "New num value: " << object1.getNum() << "\n";

    return 0;
}

#endif


// C++ STRING CLASS
#if 0

// Comparing size length, capacity, and max_size
#include <iostream>
#include <string>

using std::cout;
using std::cin;

int main() {
    std::string str ("Hello World");    // Create a string object
    cout << str << "\n";

    // Assign and append string
    str = "ABC";
    str = str + " DE";
    cout << str << "\n";

    // Get length and access each character
    cout << "length: " << str.length() << "\n";
    cout << "1st char: " << str[0] << "\n";

    // NULL ('\0') is not the terminator character in string objects
    str[2] = '\0';
    cout << str << "\n";

    // Compare string
    cout << ((str == "ABC DE" ? "YES\n" : "NO\n"));

    // Get substring substr(position, length)
    cout << "sub str: " << str.substr(1, 4) << "\n";

    // Input a line
    cout << "Input a string: ";
    getline(cin, str);
    // std::cin >> str;     // Only get a word
    cout << str << "\n";

    return 0;
}

#endif


// STRINGSTREAM
#if 0

#include <iostream>
#include <sstream>

int main() {
    std::string str = "51.40 1234 Hello World"; // Create string
    std::stringstream ss;                       // Create a stringstream object

    // std::cout << str;    // Output the content of str string to console
    ss << str;              // Output the content of str string to the ss string

    // Extract data from the stringstream
    float myFloat;
    int myInt;
    char myCharArray[20];

    // std::cin >> myFloat >> myInt >> myCharArray;     // Read from console
    ss >> myFloat >> myInt >> myCharArray;              // Extract from stringstream

    std::cout << "myFloat = " << myFloat << "\n";
    std::cout << "myInt = " << myInt << "\n";
    std::cout << "myCharArray = " << myCharArray << "\n"; 

    return 0;
}

#endif


// ARRAY OF OBJECTS
#if 0

#include <iostream>

using std::cin;
using std::cout;
using std::string;

class Car {
    public:
        string brand;
        int speed, price;

        Car(string brandVal, int speedVal, int priceVal) {
            brand = brandVal;
            speed = speedVal;
            price = priceVal;
        }
};

int main() {
    Car MyCars[3] = {
        Car("Audi", 500, 10000),
        Car("BMW", 400, 8000),
        Car("Ferrari", 800, 20000)
    };

    for (int i = 0; i < 3; i++) {
        cout << "Car" << i << "'s brand, speed & price: "
             << MyCars[i].brand << " " 
             << MyCars[i].speed << " "
             << MyCars[i].price << "\n";
    }
}

#endif


// C++ STRUCT
#if 0

#include <iostream>
using std::cout;

struct product {
    int weight;
    double price;
};

int main() {
    product pd1, pd2;
    pd1.weight = 100;
    pd1.price = 10.25;
    pd2.weight = 200;
    pd2.price = 20.7;

    cout << "Product 1's weight and price: " << pd1.weight << " " << pd1.price << "\n";
    cout << "Product 2's weight and price: " << pd2.weight << " " << pd2.price << "\n";

    return 0;
}

#endif