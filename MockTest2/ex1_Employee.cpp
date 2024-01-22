#include <iostream>

using std::cout;
using std::string;

class Employee {
    protected:
        string name;
        double salary;
    public:
        // Constructor
        Employee(string nameVal = "", double salaryVal = 0)
        : name(nameVal), salary(salaryVal) {}

        // Print out the employee information
        void showInfo() {
            cout << "Name: " << name << ", Salary: " << salary << "\n";
        }
};

class Manager : public Employee {
    private:
        double allowance;
    public:
        // Constructor
        Manager(string nameVal = "", double salaryVal = 0, double allowanceVal = 0)
        : Employee(nameVal, salaryVal), allowance(allowanceVal) {}

        // Print out the manager information
        void showInfo() {
            cout << "Name: " << name << ", Salary: " << salary << ", Allowance: " << allowance << "\n";
        }

        // Get the total income of the manager
        double getTotalIncome() {
            return salary + allowance;
        }
};

int main() {
    // Question 1a
    Employee employee1("Cuong Tran", 1000);
    employee1.showInfo();

    Manager manager1("Tom Tran", 1000, 500);
    manager1.showInfo();

    // Question 1b
    // Array of 5 managers
    Manager *managers = new (std::nothrow) Manager[5] {
        Manager("Manager 1", 1000, 100),
        Manager("Manager 2", 2000, 200),
        Manager("Manager 3", 3000, 300),
        Manager("Manager 4", 4000, 400),
        Manager("Manager 5", 5000, 500),
    };

    // Check if memory allocation is successful
    if (managers == nullptr) {
        cout << "Fail to request memory allocation\n";
        return -1;
    }

    // Calculate the average income of 5 managers
    double totalIncome = 0;
    for (int i = 0; i < 5; i++) {
        totalIncome += managers[i].getTotalIncome();
    }
    double averageIncome = totalIncome / 5;
    cout << "Average income of 5 managers: " << averageIncome << "\n";

    return 0;
}