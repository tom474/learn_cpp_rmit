#include <iostream>
#include <fstream>
#include <sstream>

using std::cout;
using std::string;

class BankAcc {
    public:
        string name = "";
        float amount = 0;

        // Constructor
        BankAcc(string nameVal = "", float amountVal = 0)
        : name(nameVal), amount(amountVal) {};

        // To get the information as a string
        string toString() {
            std::stringstream info;
            info << "Name: " << name << ", Amount: " << amount;
            return info.str();
        }

        // Withdraw function
        int withdraw(float num) {
            if (amount < num) {
                std::cerr << "Not have enough money in the account. Fail to withdraw!\n";
                return -1;
            }

            amount -= num;
            std::cout << "Withdraw successfully!\n";
            return 0;
        }
};

int main(int argc, char *argv[]) {
    std::fstream myFile;    // File variable should be declared at beginning

    // Init 3 bank accounts
    BankAcc acc1("VCB", 1000);
    BankAcc acc2("VPB", 2000);
    BankAcc acc3("VIB", 3000);

    // Print all info
    cout << "All information of 3 accounts:\n";
    cout << acc1.toString() << "\n";
    cout << acc2.toString() << "\n";
    cout << acc3.toString() << "\n";

    cout << "\nTest withdraw function on acc1:\n";
    cout << "Withdraw 500: ";
    acc1.withdraw(500);
    cout << "Withdraw 700: ";
    acc1.withdraw(700);

    if (argc != 2) {    // Does not have or have incorrect number of cmd args
        return 0;
    }

    // Save to file
    myFile.open(argv[1], std::ios::out);
    if (!myFile) {
        cout << "Fail to create/open file " << argv[1] << "\n";
    }

    // Save data
    myFile << acc1.toString() << "\n";
    myFile << acc2.toString() << "\n";
    myFile << acc3.toString() << "\n";

    cout << "Saved data to file " << argv[1] << "!\n";
    myFile.close();

    return 0;
}