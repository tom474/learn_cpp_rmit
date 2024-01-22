#include <iostream>

using std::cout;
using std::cin;

#define ARRSIZE 5

int main() {
    int arr[ARRSIZE];

    // Input 5 integers into an array
    cout << "Enter 5 integer: " << "\n";
    for (int i = 0; i < ARRSIZE; i++) {
        cin >> arr[i];
    }

    // Calculate max and average
    int max = arr[0];
    int sum = arr[0];
    for (int i = 1; i < ARRSIZE; i++) {
        // Update max if found larger value
        if (max < arr[i]) {
            max = arr[i];
        }
        // Calculate sum
        sum += arr[i];
    }
    double average = (double) sum / ARRSIZE;

    cout << "Max = " << max << "\n";
    cout << "Average = " << average << "\n";

    return 0;
}