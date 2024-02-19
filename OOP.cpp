#include <iostream>
using namespace std;

// Class declaration
class Rectangle {
private:
    int length;
    int width;
public:
    // Constructor
    Rectangle(int l, int w) {
        length = l;
        width = w;
    }
    // Method to calculate area
    int area() {
        return length * width;
    }
};

int main() {
    // Creating objects of the Rectangle class
    Rectangle r1(5, 4);
    Rectangle r2(3, 7);

    // Accessing object methods
    cout << "Area of r1: " << r1.area() << endl;
    cout << "Area of r2: " << r2.area() << endl;

    return 0;
}

