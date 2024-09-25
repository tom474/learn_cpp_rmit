#include <iostream>

using std::cout;
using std::cin;

int main() {
    int num = 0;
    cout << "Enter an integer: ";
    cin >> num; // 123

    int val = 0;
    while (num != 0) {
        int digit = num % 10; // 3 2 1
        val = val * 10 + digit; // 3 32 321
        num /= 10; // 12 1
    }
    cout << "--> Reversed number: " << val << "\n";

    return 0;
}