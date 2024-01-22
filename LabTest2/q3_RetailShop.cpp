/*
    RMIT University Vietnam
    Course: EEET2482/COSC2082
    Semester: 2023-3
    Lab Assessment: 2
    Author: Tran Manh Cuong
    ID: 3974735
    Compiler used: g++ 13.2.0
    Created  date: 13/01/2024
    Acknowledgement: Canvas, GeeksforGeeks
*/
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

class Product {
    private:
        string name;
        double price;
        int quantity;
    public:
        // Constructor
        Product(string nameVal = "", double priceVal = 0, int quantityVal = 0)
        : name(nameVal), price(priceVal), quantity(quantityVal) {}

        // Show information
        void showInfo() {
            cout << "Name: " << name << ", Price: " << price << ", Quantity: " << quantity << "\n"; 
        }

        // Grant access
        friend class Bill;
        friend class Customer;
        friend class Shop;
};

class Bill {
    private:
        vector<Product> boughtProducts;
    public:
        // Constructor
        Bill(vector<Product> boughtProductsVal = {})
        : boughtProducts(boughtProductsVal) {}

        // Function to get the total value of the bill
        double getTotalValue() {
            double totalValue;
            for (auto product : boughtProducts) {
                totalValue += product.price * product.quantity;
            }
            return totalValue;
        }

        // Grant access
        friend class Shop;
};

class Customer {
    private:
        string name;
        Bill *lastBill = nullptr;
        int earningPoints = 0;
    public:
        // Constructor
        Customer(string nameVal = "")
        : name(nameVal) {}

        // Show information
        void showInfo() {
            cout << "----- Customer Information -----\n";
            cout << "> Name: " << name << "\n";
            cout << "> Earning points: " << earningPoints << "\n\n";
        }

        // Grant access
        friend class Shop;
};

class Shop {
    private:
        string name;
        vector<Product*> sellingProduct;
        vector<Bill*> existingBills = {};
    public:
        // Constructor
        Shop(string nameVal = 0, vector<Product*> sellingProductVal = {})
        : name(nameVal), sellingProduct(sellingProductVal) {}

        // Function that creates a new bill
        void createBill(Customer &customer, vector<Product> buyingProducts) {
            Bill *newBill = new (std::nothrow) Bill(buyingProducts);
            existingBills.push_back(newBill);
            customer.lastBill = newBill;
            customer.earningPoints += newBill->getTotalValue();

            cout << "Bill created successfully!\n";
            cout << "----- Bill Information -----\n";
            for (auto product : newBill->boughtProducts) {
                product.showInfo();
            }
            cout << "> Total value: " << newBill->getTotalValue() << "\n\n";
        }

        // Function to get the shop revenue
        double getTotalRevenue() {
            double totalRevenue = 0;
            if (existingBills.size() == 0) {
                totalRevenue = 0;
            } else {
                for (auto bill : existingBills) {
                    totalRevenue += bill->getTotalValue();
                }
            }
            return totalRevenue;
        }

        // Function to get the specific product revenue
        double getProductRevenue(string productName) {
            double revenue = 0;
            for (auto bill : existingBills) {
                for (auto product : bill->boughtProducts) {
                    if (product.name == productName) {
                        revenue += product.price * product.quantity;
                    }
                }
            }
            return revenue;
        }

        // Function to get the best selling product
        string getBestSellingProduct() {
            string highestRevenueProduct = sellingProduct[0]->name;
            double highestRevenue = getProductRevenue(sellingProduct[0]->name);
            for (auto product : sellingProduct) {
                double productRevenue = getProductRevenue(product->name);
                if (productRevenue > highestRevenue) {
                    highestRevenue = productRevenue;
                    highestRevenueProduct = product->name;
                }
            }
            return highestRevenueProduct;
        }

        // Function to show the shop's sale report
        void showSaleReport() {
            cout << "----- Shop's Sale Report -----\n";
            cout << "> Shop's name: " << name << "\n";
            cout << "> Total revenue: " << getTotalRevenue() << "\n";
            cout << "> Best selling product: " << getBestSellingProduct() << "\n";
            cout << "> Revenue of each product" << "\n";
            for (int i = 0; i < sellingProduct.size(); i++) {
                cout << (i+1) << ". " << sellingProduct[i]->name << ": " << getProductRevenue(sellingProduct[i]->name) << "\n";
            }
            cout << "\n";
        }

        // Grant access
        friend class Customer;
};

int main() {
    // Initialize the shop and customer
    Product *product1 = new (std::nothrow) Product("Phone", 100, 50);
    Product *product2 = new (std::nothrow) Product("Tablet", 200, 40);
    Product *product3 = new (std::nothrow) Product("Laptop", 300, 30);

    Shop shop1("CellphoneS", {product1, product2, product3});
    Customer customer1("Cuong Tran");

    // Show shop and customer infomation before the buying process
    shop1.showSaleReport();
    customer1.showInfo();

    // Create the first bill
    Product buyingProduct1("Phone", 100, 2);
    Product buyingProduct2("Tablet", 200, 1);
    Product buyingProduct3("Laptop", 300, 1);
    shop1.createBill(customer1, {buyingProduct1, buyingProduct2, buyingProduct3});

    // Create the second bill
    Product buyingProduct4("Phone", 100, 3);
    Product buyingProduct5("Tablet", 200, 1);
    Product buyingProduct6("Laptop", 300, 2);
    shop1.createBill(customer1, {buyingProduct4, buyingProduct5, buyingProduct6});

    // Show shop and customer infomation after the buying process
    shop1.showSaleReport();
    customer1.showInfo();

    return 0;
}