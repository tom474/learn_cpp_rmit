// SINGLY LINKED LIST
#if 0

#include <iostream>

using std::cout;
using std::string;

class Household {
    public:
        string name;
        Household *purchasedPerson = nullptr;

        // Constructor
        Household(string nameVal = "")
        : name(nameVal) {}
};

int main() {
    // Initialize nodes
    Household hh1("Household 1"), hh2("Household 2"), hh3("Household 3");

    // Save reference of first node in head (original Household)
    Household *originalHousehold = &hh1;

    // Connect codes
    hh1.purchasedPerson = &hh2;         // hh2 bought the house from hh1
    hh2.purchasedPerson = &hh3;         // hh3 bought the house from hh2
    hh3.purchasedPerson = nullptr;      // no person bought the house from hh3 yet

    // Loop through the linked list
    cout << "\nLinked list of the house transactions is: \n";
    Household *temp = originalHousehold;    // Start with first node (head)
    
    while (temp != nullptr) {
        cout << temp->name << " --> ";
        temp = temp->purchasedPerson;   // Access next node
    }

    return 0;
}

#endif


// CIRCULAR SINGLY LINKED LIST
#if 0

#include <iostream>

using std::cout;
using std::string;

class Household {
    public:
        string name;
        Household *purchasedPerson = nullptr;

        // Constructor
        Household(string nameVal = "")
        : name(nameVal) {}
};

int main() {
    // Initialize nodes
    Household hh1("Household 1"), hh2("Household 2"), hh3("Household 3");

    // Save reference of first node in head (original Household)
    Household *originalHousehold = &hh1;

    // Connect codes
    hh1.purchasedPerson = &hh2;         // hh2 bought the house from hh1
    hh2.purchasedPerson = &hh3;         // hh3 bought the house from hh2
    hh3.purchasedPerson = &hh1;         // hh1 bought the house from hh3 

    // Loop through the linked list
    cout << "\nLinked list of the house transactions is: \n";
    Household *temp = originalHousehold;    // Start with first node (head)
    
    while (temp != nullptr) {
        cout << temp->name << " --> ";
        temp = temp->purchasedPerson;   // Access next node

        // Stop if go back to head
        if (temp == originalHousehold) {
            cout << temp->name << "\n";
            break;
        }
    }
    // Note: it is assumed that the hh1 did not sell the house twice to hh2

    return 0;
}

#endif


// DOUBLY LINKED LIST
#if 0

#include <iostream>

using std::cout;
using std::string;

class Household {
    public:
        string name;
        Household *purchasedPerson = nullptr;   // Pointer to next node
        Household *soldPerson = nullptr;        // Pointer to previous node

        // Constructor
        Household(string nameVal = "")
        : name(nameVal) {}
};

int main() {
    // Initialize nodes
    Household hh1("Household 1"), hh2("Household 2"), hh3("Household 3");

    // Connect nodes (record transaction)
    Household *originalHousehold = &hh1;    // Head (first Household)

    // hh1 sell house to hh2:   hh1 --> hh2
    hh1.purchasedPerson = &hh2;
    hh2.soldPerson = &hh1;

    // hh2 sell house to hh3:   hh2 --> hh3
    hh2.purchasedPerson = &hh3;
    hh3.soldPerson = &hh2;

    Household *lastHousehold = &hh3;    // Tail (last Household)


    // Quick questions:
    // Print out name of the person sell house to hh3?
    // Print out name of the person bought house from hh2?


    // Loop through the linked list
    // Go forward from head to tail
    cout << "\nLinked Households (next buyers) are: \n";
    Household *temp = originalHousehold;
    while (temp != nullptr) {
        cout << temp->name << " --> ";
        temp = temp->purchasedPerson;   // Access next node
    }

    // Go backward from tail to head
    cout << "\nLinked Households (previous owners) are: \n";
    temp = lastHousehold;
    while (temp != nullptr) {
        cout << temp->name << " --> ";
        temp = temp->soldPerson;   // Access next node
    }

    return 0;
}

#endif


// LINKED LIST HIDDEN ELEMENTS (ONLY NEED HEAD AND TAIL)
#if 0

#include <iostream>

using std::cout;
using std::string;

class Household {
    public:
        string name;
        Household *purchasedPerson = nullptr;

        // Constructor
        Household(string nameVal = "")
        : name(nameVal) {}
};

int main() {
    // Linked list with hidden elements
    Household *head = new Household("Household 1"); // First node
    Household *temp = head;
    for (int i = 2; i < 6; i++) {
        temp->purchasedPerson = new Household("Household " + std::to_string(i));    // Create and link with another node
        temp = temp->purchasedPerson;
    }

    // Loop through the linked list
    cout << "\nLinked list of the house transaction is: \n";
    temp = head;    // Start with first node (head)

    while (temp != nullptr) {
        cout << temp->name << " --> ";
        temp = temp->purchasedPerson;   // Access next node
    }

    return 0;
}

#endif


// RANDOM GENERATOR
#if 0

#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;

int main() {
    char ch;

    // Initialize the random generator (based on current time)
    srand(time(nullptr));

    // Generate a random integer from 0 to N
    int const N = 10;
    int num = rand() % (N + 1);
    cout << "num: " << num << "\n";

    ch = rand() % ('Z' - 'A') + 'A';
    cout << "char: " << ch << "\n";
}

#endif