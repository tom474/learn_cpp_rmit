#include <iostream>

using std::cout;

class Juice {
    public:
        int *price;

        void memRequestForPrice() {
            price = new (std::nothrow) int;
            if (!price) {
                cout << "Fail to request memory allocation\n";
            }
        }

        // Constructor
        Juice(int priceVal = 0) {
            cout << "Default Constructor\n";
            memRequestForPrice();
            *price = priceVal;
        }

        // Copy constructor (for new obj)
        Juice(const Juice &oldJuice) {
            cout << "Copy Constructor\n";
            memRequestForPrice();
            *price = *(oldJuice.price);
        }

        // Assignment operator (for existing obj)
        // Return by reference to avoid creating another object
        Juice &operator = (const Juice &oldJuice) {
            cout << "Assignment Operator\n";
            *price = *(oldJuice.price);
            return *this;   // To allow multiple "=" operators used together
        }

        // Destructor
        ~Juice() {
            cout << "Destructor\n";
            delete price;
        }
};

int main() {
    // Note: whenever you have initialization of value: it wil call constructor
    Juice juice1;       // Default constructor
    Juice juice2(100);  // Default constructor

    Juice juice3 = juice2;  // Copy constructor
    Juice juice4(juice2);   // Copy constructor

    juice1 = juice2;    // Assignment operator

    return 0;
}