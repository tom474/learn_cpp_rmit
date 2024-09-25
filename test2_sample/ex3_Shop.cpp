#include <iostream>
#include <vector>

using std::cout;
using std::string;
using std::vector;

#define DISCOUNT_RATE 0.05

class Product {
    private:
        string name;
        double unitPrice;
    public:
        // Constructor
        Product(string nameVal = "", double unitPriceVal = 0)
        : name(nameVal), unitPrice(unitPriceVal) {}

        // Show product information
        void showInfo() {
            cout << "Product's Name: " << name << ", Price: " << unitPrice << "\n";
        }

        // Friend class
        friend class Account;
};

class Shop {
    private:
        string name;
        vector<Product*> productList;
    public:
        // Constructor
        Shop(string nameVal = "", vector<Product*> productListVal = {})
        : name(nameVal), productList(productListVal) {}

        // Show shop information
        void showInfo() {
            cout << "> Shop's Name: " << name << "\n";
            cout << "Product list: \n";
            for (auto product : productList) {
                product->showInfo();
            }
            cout << "\n";
        }
};

class Order {
    private:
        int orderID;
        vector<Product*> boughtProducts;
        double totalExpense;
    public:
        // Constructor
        Order(int orderIDVal = 0, vector<Product*> boughtProductsVal = {}, double totalExpenseVal = 0)
        : orderID(orderIDVal), boughtProducts(boughtProductsVal), totalExpense(totalExpenseVal) {}

        // Show order information
        void showInfo() {
            cout << "Order's ID: " << orderID << ", Total Expense: " << totalExpense << "\n";
            cout << "Bought product list: \n";
            for (auto product : boughtProducts) {
                product->showInfo();
            }
            cout << "\n";
        }

        friend class Account;
};

class Account {
    private:
        bool isGold = false;    // Normal account by default
        string name;
        vector<Order*> orderList;
    public:
        // Constructor
        Account(bool isGoldVal = false, string nameVal = "", vector<Order*> orderListVal = {})
        : isGold(isGoldVal), name(nameVal), orderList(orderListVal) {}

        // An account can buy a list of products
        void buyProducts(vector<Product*> productList) {
            // Calculate the total expenses
            double totalExpense = 0;
            for (auto product : productList) {
                if (isGold) {
                    // Gold account get 5% discount
                    totalExpense += (product->unitPrice * (1 - DISCOUNT_RATE));
                } else {
                    totalExpense += product->unitPrice;
                }
            }

            // Calculate the order ID based on account's order list size
            int orderID = orderList.size() + 1;

            Order *newOrder = new (std::nothrow) Order(orderID, productList, totalExpense);
            orderList.push_back(newOrder);
        }

        // Show account information
        void showInfo() {
            cout << "> Name: " << name;
            cout << ", Account Type: " << (isGold ? "Gold" : "Normal");
            cout << ", Discount Rate: " << (isGold ? (DISCOUNT_RATE*100) : 0) << "%\n";
            cout << "Order list: \n";
            for (auto order : orderList) {
                order->showInfo();
            } 
        }
};

int main() {
    // Create a shop and add products
    Product *product1 = new (std::nothrow) Product("Shoe", 20);
    Product *product2 = new (std::nothrow) Product("Car", 1000);
    Product *product3 = new (std::nothrow) Product("Book", 10);
    Shop shop1("Shop 1", {product1, product2, product3});
    shop1.showInfo();

    // Test normal account
    Account account1(false, "Normal Account");
    account1.buyProducts({product1});
    account1.buyProducts({product1, product2, product3});
    account1.showInfo();

    // Test gold account
    Account account2(true, "Gold Account");
    account2.buyProducts({product1});
    account2.buyProducts({product1, product2, product3});
    account2.showInfo();

    return 0;
}