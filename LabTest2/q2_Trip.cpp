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

using std::cin;
using std::cout;
using std::string;

class City {
    private:
        string name;
        int stayingDays;
        City *nextCity;
    public:
        // City Constructor
        City(string nameVal = "", int stayingDaysVal = 0, City *nextCityVal = nullptr)
        : name(nameVal), stayingDays(stayingDaysVal), nextCity(nextCityVal) {}

        // Set the next city after this city in the trip
        void setNextCity(City *nextCityVal) {
            nextCity = nextCityVal;
        }

        // Function that print out the trip plan
        friend void showTripPlan(City *head);

        // Function that update the trip plan
        friend void updateTripPlan(City *head);
};

void showTripPlan(City *head) {
    // Assume head as the temporary node
    City *temp = head;

    cout << "Trip Plan: \n";
    while (temp != nullptr) {
        // Print the information of this node
        cout << "- " << temp->name << ": " << temp->stayingDays << " days\n";

        // Go to the next node
        temp = temp->nextCity;
    }
    cout << "\n";
}

void updateTripPlan(City *head) {
    // Ask user to enter the city's name
    string cityName;
    cout << "Enter the City's name: ";
    getline(cin >> std::ws, cityName);

    // Find that city in the linked list
    City *updatingCity = nullptr;
    City *temp = head;
    while (temp != nullptr) {
        if (temp->name == cityName) {
            updatingCity = temp;
            break;
        }

        // Go to the next node
        temp = temp->nextCity;
    }

    // Check if the updating city is nullptr
    if (updatingCity == nullptr) {
        cout << "The city that you entered is not found!\n";
        return;
    }

    // Find the city before the updating city
    City *prevCity = nullptr;
    temp = head;
    while (temp != nullptr) {
        if (temp->nextCity == updatingCity) {
            prevCity = temp;
            break;
        }

        // Go to the next node
        temp = temp->nextCity;
    }

    // Ask user to update the number of staying days
    int stayingDays;
    cout << "Update the number of staying days: ";
    cin >> stayingDays;

    // Update the city's staying days
    // And calculate how many days that the traveller will stay from that City to the end of the trip
    int travelDays = 0;
    if (stayingDays == 0) {
        // If the city's staying days is set to 0, remove that city from the trip plan
        updatingCity->stayingDays = stayingDays;
        prevCity->nextCity = updatingCity->nextCity;

        // Calculate the travelDays
        temp = updatingCity->nextCity;
        while (temp != nullptr) {
            travelDays += temp->stayingDays;

            // Go to the next node
            temp = temp->nextCity;
        }

        // Print out the result
        cout << "> Updated. There will be a total of " << travelDays << " days staying in the next cities in the trip.\n";
    } else {
        updatingCity->stayingDays = stayingDays;

        // Calculate the travelDays
        temp = updatingCity;
        while (temp != nullptr) {
            travelDays += temp->stayingDays;

            // Go to the next node
            temp = temp->nextCity;
        }

        // Print out the result
        cout << "> Updated. There will be a total of " << travelDays << " days staying in this and next cities in the trip.\n";
    }
    cout << "\n";
}

int main() {
    // Initialize nodes
    City city1("Hue", 5);
    City city2("Da Nang", 3);
    City city3("Nha Trang", 4);
    City city4("Da Lat", 2);
    City city5("Can Tho", 3);

    // Connect nodes
    City *head = &city1;
    city1.setNextCity(&city2);
    city2.setNextCity(&city3);
    city3.setNextCity(&city4);
    city4.setNextCity(&city5);

    // Question 2a: Print out the trip plan
    showTripPlan(head);

    // Question 2b: Update the trip plan
    updateTripPlan(head);
    updateTripPlan(head);
    showTripPlan(head);

    return 0;
}