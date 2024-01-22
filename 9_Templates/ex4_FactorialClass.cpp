#include <iostream>

using std::cout;

template <int N>    
class factorial {
public:
    const static int value = N * factorial<N - 1>::value; // Static attribute
};

// Template specification here (for the case N == 0)
template <>    
class factorial<0> {
public:
    const static int value = 1; // Static attribute
};

int main(){
    // Create an object
    cout << factorial<0>::value << "\n";
    cout << factorial<3>::value << "\n";

    return 1;
}