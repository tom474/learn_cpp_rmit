#include <iostream>

using std::cout;
using std::string;

class Broker {
    private:
        string name;
        int buyPrice;
        Broker *nextBuyer;
    public:
        // Constructor
        Broker(string nameVal = "", int buyPriceVal = 0)
        : name(nameVal), buyPrice(buyPriceVal) {}

        // Set next buyer function
        void setNextBuyer(Broker *nextBuyerVal) {
            nextBuyer = nextBuyerVal;
        }

        // Friend functions
        friend void showForwardLinkedList(Broker *head);
        friend void showLowestProfitBroker(Broker *head);
};

void showForwardLinkedList(Broker *head) {
    // temp is the current node
    Broker *temp = head;

    while (temp != nullptr) {
        // Print out current the broker's name and buy price
        if (temp == head) {
            cout << temp->name << ": bought the house for $" << temp->buyPrice << "\n";
        } else {
            cout << temp->name << " : price = $" << temp->buyPrice << "\n";
        }

        // Print out the current broker's name (for next node)
        if (temp->nextBuyer != nullptr) {
            cout << temp->name << " --> ";
        }

        // Go to the next node
        temp = temp->nextBuyer;
    }
    cout << "\n";
}

void showLowestProfitBroker(Broker *head) {
    // Temp is the current node
    Broker *temp = head;

    // Assume that the first broker has lowest profit
    Broker *minProfitBroker = head;
    int minProfit = head->nextBuyer->buyPrice - head->buyPrice;

    // Check with other broker
    while (temp != nullptr) {
        // Check if the current broker has already sold the house
        if (temp->nextBuyer != nullptr) {
            // Calculate and compare profit
            int profit = temp->nextBuyer->buyPrice - temp->buyPrice;
            if (profit < minProfit) {
                minProfit = profit;
                minProfitBroker = temp;
            }
        }

        temp = temp->nextBuyer;
    }

    if (minProfitBroker != nullptr) {
        cout << "The Broker with min profit: \n";
        cout << "Name: " << minProfitBroker->name << ", Profit: " << minProfit << "\n\n";
    }
}

int main() {
    // Create nodes
    Broker broker1("David", 800);
    Broker broker2("John", 1000);
    Broker broker3("Peter", 1200);
    Broker broker4("Luna", 1800);
    Broker broker5("Sophia", 3500);

    // Link nodes
    Broker *head = &broker1;
    broker1.setNextBuyer(&broker2);
    broker2.setNextBuyer(&broker3);
    broker3.setNextBuyer(&broker4);
    broker4.setNextBuyer(&broker5);
    broker5.setNextBuyer(nullptr);
    Broker *tail = &broker5;

    // Question 2a
    showForwardLinkedList(head);

    // Question 2b
    showLowestProfitBroker(head);

    return 0;
}