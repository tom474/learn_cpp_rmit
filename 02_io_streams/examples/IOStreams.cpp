/*
    cout, and clog/cerr are connected to two difference streams (namely 1 and 2).
    By default, they are both mapped to the console output,
    but can be redirected as below:

    - Compile: g++ is_streams.cpp (create a.exe by default)
    - Run:
    ./a.exe
        Both streams are mapped to the console output (default)

    ./a.exe > output.txt   or  ./a.exe 1> output.txt
        Map the standard output stream to file output.txt

    ./a.exe 2> output.txt
        Map the standard error stream to file output.txt
*/

#if 0

#include <iostream>

using std::cout;

int main() {
    cout << "This is cout\n"; // Standard output stream (1)

    std::clog << "This is clog\n"; // Standard error stream (2)
    std::cerr << "This is cerr\n";

    return 0;
}

#endif


#if 0

#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;

int main() {
    // Precision
    cout << 3.14159 << " " << 12.3456 << " (DATA TO DISPLAY)\n";
    cout << "precision = 3: \n";
    cout << std::setprecision(3) << 3.14159 << " " << 12.3456 << "\n\n";

    /* Note: setprecision applies to the entire number, not the fractional part.
    You need to use the fixed-point format to make it apply to the fractional part */
    cout << "precision = 3, fixed: \n";
    double f = 23.14159;
    cout << std::fixed << std::setprecision(3) << 3.14159 << " " << 12.3456 << "\n\n\n";

    // Width
    cout << 10 << " " << 20 << " (DATA TO DISPLAY)\n";
    cout << "width = 10: \n";
    cout << std::setw(10) << 10 << " " << 20 << "\n\n";

    // Fill & Width
    cout << "fill = '*' , width = 10: \n";
    cout << std::setw(10) << std::setfill('*') << 10 << " " << 20 << "\n\n";

    // Set/Unset Format Flags
    cout << "Set flags left justification and showpos, width = 10: \n";
    cout << std::left << std::showpos << std::setw(10) << 10 << " " << 20 << "\n\n";

    cout << "Set flags internal justification and noshowpos, width = 10: \n";
    cout << std::internal << std::noshowpos << std::setw(10) << 10 << " " << 20 << "\n\n";

    return 0;
}

#endif