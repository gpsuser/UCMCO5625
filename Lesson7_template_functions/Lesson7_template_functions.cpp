// Lesson7_template_functions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include <iostream>
//
//int main()
//{
//    std::cout << "Hello World!\n";
//}

#include <iostream>

// Function to find max of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to find max of two doubles
double max(double a, double b) {
    return (a > b) ? a : b;
}

int main() {
    int intMax = max(3, 7);
    double doubleMax = max(3.5, 2.1);

    std::cout << "Max of 3 and 7: " << intMax << std::endl;
    std::cout << "Max of 3.5 and 2.1: " << doubleMax << std::endl;

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
