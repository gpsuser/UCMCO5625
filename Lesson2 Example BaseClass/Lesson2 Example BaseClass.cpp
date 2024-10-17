// Lesson2 Example BaseClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath> // For mathematical functions

class Circle {
protected:
    double radius;

private:
    double mypi = 3.141592;

public:
    // Constructor to initialize the radius
    Circle(double r) : radius(r) {}

    // Method to calculate the area of the circle
    double calculateArea() const {
        return mypi * radius * radius;
    }

    double my_pi() const {
		return mypi;
	}

    // Method to get the radius of the circle
    double getRadius() const {
        return radius;
    }

    // Method to output the area of the circle
    void outputArea() const {
        std::cout << "The area of the circle is: " << calculateArea() << std::endl;
    }
};

class Sphere : public Circle {
public:
    // Constructor to initialize the radius using the Circle constructor
    Sphere(double r) : Circle(r) {}

    // Method to calculate the surface area of the sphere
    double calculateSurfaceArea() const {
        return 4 * my_pi() * radius * radius;
    }

    // Method to output the surface area of the sphere
    void outputSurfaceArea() const {
        std::cout << "The surface area of the sphere is: " << calculateSurfaceArea() << std::endl;
    }
};

int main() {
    double r;
    std::cout << "Enter the radius of the sphere: ";
    std::cin >> r;

    Sphere sphere(r);
    sphere.outputSurfaceArea();
    std::cout << "The radius of the sphere is: " << sphere.getRadius() << std::endl;

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
