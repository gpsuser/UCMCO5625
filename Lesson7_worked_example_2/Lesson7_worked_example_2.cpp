// Lesson7_worked_example_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// template rectangle class


#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

#include <iostream>

template <typename T>
class Rectangle {
private:
    T length;
    T width;

public:
    Rectangle(T l, T w) : length(l), width(w) {}

    T getArea() const {
        return length * width;
    }
};

int main() {
    Rectangle<int> rectInt(10, 20);
    std::cout << "Area of rectangle with integer dimensions: " << rectInt.getArea() << std::endl;

    Rectangle<double> rectDouble(10.5, 20.5);
    std::cout << "Area of rectangle with double dimensions: " << rectDouble.getArea() << std::endl;

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
