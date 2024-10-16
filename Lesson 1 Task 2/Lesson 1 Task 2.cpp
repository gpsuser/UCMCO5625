// Lesson 1 Task 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <algorithm> // For std::count_if

int main() {
    std::srand(static_cast<unsigned int>(time(0))); // Seed random number generator

    double array[20];
    int countLessThanHalf = 0;

    // Fill array with random doubles between 0 and 1
    for (int i = 0; i < 20; ++i) {
        array[i] = static_cast<double>(rand()) / RAND_MAX;
        if (array[i] < 0.5) {
            ++countLessThanHalf;
        }
    }

    std::cout << "Count of numbers less than 0.5: " << countLessThanHalf << std::endl;

    //// Determine how many items are greater than or equal to 0.5 in one line
    //int countGreaterThanOrEqualHalf = std::count_if(std::begin(array), std::end(array), { return x >= 0.5; });

    //std::cout << "Count of numbers greater than or equal to 0.5: " << countGreaterThanOrEqualHalf << std::endl;

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
