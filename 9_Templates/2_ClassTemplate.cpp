// CLASS TEMPLATE
#if 0

#include <iostream>

using std::cout;

// Class template
template <typename type>
class Number {
    private:
        type num;
    public:
        // Constructors
        Number() {}
        Number(type numVal)
        : num(numVal) {}

        type getNum() {
            return num;
        }
};

int main() {
    // Create object with int type
    Number<int> intNum(7);
    cout << "int Number: " << intNum.getNum() << "\n";

    // Create object with double type
    Number<double> doubleNum(7.7);
    cout << "double Number: " << doubleNum.getNum() << "\n";

    return 0;
}

#endif


// DEFINE A MEMBER FUNCTION OUTSIDE OF ITS CLASS TEMPLATE
#if 0

#include <iostream>

using std::cout;

// Class template
template <typename type>
class Number {
    private:
        type num;
    public:
        // Constructors
        Number() {}
        Number(type numVal)
        : num(numVal) {}

        type getNum();
};

template <typename type>
type Number<type>::getNum() {
    return num;
}

int main() {
    // Create object with int type
    Number<int> intNum(7);
    cout << "int Number: " << intNum.getNum() << "\n";

    // Create object with double type
    Number<double> doubleNum(7.7);
    cout << "double Number: " << doubleNum.getNum() << "\n";

    return 0;
}

#endif


// NON-TYPE ARGUMENT OF CLASS TEMPLATE
#if 0

#include <iostream>

using std::cout;

// Class template
template <typename type, int MYCONST>
class Number {
    private:
        type num = MYCONST;
    public:
        // Constructor
        Number() {}
        Number(type numVal)
        : num(numVal) {}

        type getNum();
};

template <typename type, int MYCONST>
type Number<type, MYCONST>::getNum() {
    return num;
}

int main() {
    // Create object with int type
    Number<int, 10> intNum;
    cout << "int Number: " << intNum.getNum() << "\n";

    // Create object with double type
    Number<double, 100> doubleNum;
    cout << "double Number: " << doubleNum.getNum() << "\n";

    return 0;
}

#endif