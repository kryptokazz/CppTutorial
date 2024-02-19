#include <iostream>
using namespace std;

// Base class
class Shape {
public:
    void display() {
        cout << "This is a shape." << endl;
    }
};

// Derived class
class Circle : public Shape {
public:
    void displayCircle() {
        cout << "This is a circle." << endl;
    }
};

int main() {
    Circle c;
    c.display(); // Accessing base class method
    c.displayCircle(); // Accessing derived class method

    return 0;
}

