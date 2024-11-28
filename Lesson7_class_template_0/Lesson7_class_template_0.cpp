// Lesson7_class_template_0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>



// Class for int
class StorageInt {
public:
    StorageInt(int value) : value(value) {}
    int getValue() const { return value; }
private:
    int value;
};

// Class for double
class StorageDouble {
public:
    StorageDouble(double value) : value(value) {}
    double getValue() const { return value; }
private:
    double value;
};

int main()
{
    StorageInt myint(5);
	StorageDouble mydouble(6.7);

	std::cout << "Int value: " << myint.getValue() << std::endl;
	std::cout << "Double value: " << mydouble.getValue() << std::endl;

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
