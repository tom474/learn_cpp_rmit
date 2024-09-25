#include <iostream>
#include <vector>

using std::cout;
using std::string;
using std::vector;

class Book {
    private:
        string title;
        int availableCopies;
        vector<string> namesOfBorrowers;
    public:
        // Constructor
        Book(string titleVal = "", int availableCopiesVal = 0, vector<string> namesOfBorrowersVal = {})
        :title(titleVal), availableCopies(availableCopiesVal), namesOfBorrowers(namesOfBorrowersVal) {}

        // Extra function to show information
        void showInfo() {
            cout << "Title: " << title << ", Available Copies: " << availableCopies << ", Names of borrowers: ";
            for (string &name : namesOfBorrowers) {
                cout << name << " ";
            }
            cout << "\n";
        }

        friend class User;  // Grant access
};

class User {
    private:
        string name;
        vector<Book*> borrowedBooks;   // Vector of Book object pointers (like a list of links)
    public:
        // Constructor
        User(string nameVal = "", vector<Book*> borrowedBooksVal = {})
        :name(nameVal), borrowedBooks(borrowedBooksVal) {}

        // Function to borrow book
        bool doBorrow(Book &abook) {
            if (abook.availableCopies == 0) {
                std::cerr << "There is no available book!\n";
                return false;
            }

            // Record the book (like a link) in borrowedBooks list of the user
            borrowedBooks.push_back(&abook);

            // Record the borrower's name in namesOfBorrowers list of the book
            abook.namesOfBorrowers.push_back(name);

            // Reduce its availableCopies
            abook.availableCopies -= 1;

            cout << "Borrow book successfully!\n";
            return true;
        }

        // Function to return book
        void doReturn(Book &abook) {
            // Remove the book link in borrowedBooks list of the user
            for (int i = 0; i < borrowedBooks.size(); i++) {
                if (borrowedBooks[i] == &abook) {
                    borrowedBooks.erase(borrowedBooks.begin() + i);
                }
            }

            // Remove the borrowed's name in namesOfBorrowers
            for (int i = 0; i < abook.namesOfBorrowers.size(); i++) {
                if (abook.namesOfBorrowers[i] == name) {
                    abook.namesOfBorrowers.erase(abook.namesOfBorrowers.begin() + i);
                }
            }

            // Increase its availableCopies
            abook.availableCopies += 1;

            cout << "Return book successfully!\n";
        }

        void showInfo() {
            cout << "Name: " << name << ", Title of borrowed books: ";
            for (Book* book : borrowedBooks) {
                cout << book->title << " ";
            }
            cout << "\n";
        }
};

class SuperUser : public User {
    public:
        // Constructor
        SuperUser(string nameVal = "", vector<Book*> borrowedBooksVal = {})
        :User(nameVal, borrowedBooksVal) {}

        bool doBorrow(Book &book1, Book &book2) {
            return (User::doBorrow(book1) && User::doBorrow(book2));
        }
};

int main() {
    // Review: this is the way to request memory allocation and initialize values for an array of objects
    // Book *bookArr = new Book[3]{
    //     Book("Book1", 3, {} ), 
    //     Book("Book2", 3, {} ),
    //     Book("Book3", 3, {} )
    // }
   
    // Create a vector of three Book objects using dynamic memory allocation
    vector<Book*> books = {
        new (std::nothrow) Book("Book0", 4, {}), 
        new (std::nothrow) Book("Book1", 4, {}),
        new (std::nothrow) Book("Book2", 4, {})
    };
    
    // Check memory allocation is successful or not
    for (Book *book: books){
        if (book == NULL){
            cout << "Fail to request memory allocation \n";
            return -1;
        }
    }

    // Test methods
    User user1("User1", {});
    User user2("User2", {});

    user1.doBorrow(*books[0]);  
    user1.doBorrow(*books[1]);
    user2.doBorrow(*books[1]);

    books[0]->showInfo();
    books[1]->showInfo();

    user1.showInfo();
    user2.showInfo();

    SuperUser su1("Super User", {});
    su1.doBorrow(*books[0],*books[2]);  // Borrow two books
    su1.showInfo();

    // Free up memory at the end
    for (Book *aBook: books){
        delete aBook;
    }
	
    return 0;
}