#include <iostream>

using std::cin;
using std::cout;
using std::string;

class Book {
    private:
        string name;
        int price;
    public:
        // Constructor
        Book(string nameVal = "", int priceVal = 0)
        : name(nameVal), price(priceVal) {}

        // Function to return info as string
        string toString() {
            return "Name: " + name + ", Price: " + std::to_string(price);
        }

        // Extra get and set functions to access private attributes
        void setName(string nameVal) {
            name = nameVal;
        }

        void setPrice(int priceVal) {
            price = priceVal;
        }

        int getPrice() {
            return price;
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

    // delete book1;   // Free up allocated memory
    // delete book2;   // Free up allocated memory
    // delete book3;   // Free up allocated memory
    // Book *book4 = new (std::nothrow) Book("X Men", 300);    // Will get same address freed from book1

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

    Book *mostExp = &books[0];  // Assume the first book is the most expensive
    for (int i = 1; i < n; i++) {   // Check with other books
        if (mostExp->getPrice() < books[i].getPrice()) {
            mostExp = &books[i];
        }
    }
    cout << "> Most expensive book: " << mostExp->toString() << "\n";

    delete[] books;

    return 0;
}