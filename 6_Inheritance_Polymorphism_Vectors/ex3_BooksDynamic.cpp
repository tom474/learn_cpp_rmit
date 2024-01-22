#include <iostream>

using std::cin;
using std::cout;
using std::string;

class Book {
    private:
        string *name;
        int price;
    public:
        void memRequestForName() {  // NEW
            name = new (std::nothrow) string;
            if (!name) {
                std::cerr << "Fail to request memory allocation\n";
            }
        }

        // Default Constructor
        Book(string nameVal = "", int priceVal = 0) {
            memRequestForName();    // NEW
            *name = nameVal;       // NEW
            price = priceVal;
        }

        // Copy constructor     // NEW
        Book(const Book &oldObj) {
            memRequestForName();        // Request memory allocation
            *name = *(oldObj.name);    // Copy name
            price = oldObj.price;      // Copy price
        }

        // Copy assignment operator     // NEW
        // Note: no need to request mem allocation for name
        Book &operator = (const Book &oldObj) {
            *name = *(oldObj.name);
            price = oldObj.price;
            return *this;   // Return current object
        }

        // Function to return info as string
        string toString() {
            return "Name: " + ((name == nullptr) ? "N/A" : *name) + ", Price: " + std::to_string(price);    // UPDATE
        }

        // Extra get and set functions to access private attributes
        void setName(string nameVal) {
            *name = nameVal;    // UPDATE
        }

        void setPrice(int priceVal) {
            price = priceVal;
        }

        int getPrice() {
            return price;
        }

        // Destructor   // UPDATE
        ~Book() {
            delete name;
        }
};

int main() {
    // Request dynamic memory allocation
    Book *book1 = new (std::nothrow) Book("Harry Potter", 100);
    Book *book2 = new (std::nothrow) Book("Doremon", 200);
    Book *book3 = new (std::nothrow) Book("Dragon Ball", 300);

    if (book1 == nullptr || book2 == nullptr || book3 == nullptr) {
        cout << "Fail to request memory allocation for book objects\n";
        return -1;
    }

    // Print out info using range based for loop
    for (Book *book : {book1, book2, book3}) {  // book will be book1, book2, book3 
        cout << book->toString() << "\n";
        delete book;    // Free up allocated memory of book1, book2, book3
    }

    int n;
    cout << "\nEnter number of books: ";
    cin >> n;
    Book *books = new (std::nothrow) Book[n];

    cout << "Enter the information for each book: \n";
    for (int i = 0; i < n; i++) {
        // Read a line from console and set name
        string name;
        cout << "> Book " << i + 1 << "'s name: ";
        std::getline(cin >> std::ws, name);
        books[i].setName(name);

        // Read an integer from console and set price
        int price;
        cout << "price: ";
        cin >> price;
        books[i].setPrice(price);
    }

    // NEW: It is now safe to assign an object to another object (copy constructor / copy assignment operator will be called)
    Book mostExp = books[0];  // Assume the first book is the most expensive
    for (int i = 1; i < n; i++) {   // Check with other books
        if (mostExp.getPrice() < books[i].getPrice()) {
            mostExp = books[i];
        }
    }
    cout << "> Most expensive book: " << mostExp.toString() << "\n";

    delete[] books;

    return 0;
}