// Lesson5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//int main()
//{
//    std::cout << "Hello World!\n";
//}


#include <iostream>
#include <algorithm> // For std::min

void resizeArray(int** arr, int oldSize, int newSize) {
    // Allocate a new array with the new size
    int* newArr = new int[newSize];

    // Copy elements from the old array to the new array
    int elementsToCopy = std::min(oldSize, newSize);
    for (int i = 0; i < elementsToCopy; ++i) {
        newArr[i] = (*arr)[i];
    }

    // Delete the old array
    delete[] * arr;

    // Update the pointer to the new array
    *arr = newArr;
}

int main() {
    // Example usage
    int oldSize = 5;
    int newSize = 10;
    int* array = new int[oldSize];

    // Initialize the array with some values
    for (int i = 0; i < oldSize; ++i) {
        array[i] = i + 1;
    }

    // Resize the array
    resizeArray(&array, oldSize, newSize);

    // Print the new array
    for (int i = 0; i < newSize; ++i) {
        std::cout << array[i] << " ";
    }

    // Free the allocated memory
    delete[] array;
    ++
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
