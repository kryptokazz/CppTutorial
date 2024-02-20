#include<iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of Fibonacci terms to generate: ";
    cin >> n;

    int a = 0, b = 1, c;

    if (n >= 1) {
        cout << "Fibonacci sequence up to " << n << " terms: ";
        cout << a << " " << b << " "; // Print first two terms

        for (int i = 3; i <= n; i++) { // Start from 3rd term
            c = a + b;
            cout << c << " ";
            a = b;
            b = c;
        }
    }
    else {
        cout << "Invalid input. Number of terms should be greater than 0.";
    }

    return 0;
}

