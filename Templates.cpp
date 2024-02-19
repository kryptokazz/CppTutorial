#include <iostream>
using namespace std;

// Template function to find maximum of two values
template <typename T>
T maximum(T x, T y) {
    return (x > y) ? x : y;
}

int main() {
    cout << "Maximum of 5 and 10: " << maximum(5, 10) << endl;
    cout << "Maximum of 5.5 and 3.3: " << maximum(5.5, 3.3) << endl;

    return 0;
}

