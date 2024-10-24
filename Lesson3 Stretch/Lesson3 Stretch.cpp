// Lesson3 Stretch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

// PASS BY VALUE, REFERENCE, POINTER
void byValue(int num) {
    num = 20;
    cout << "Inside byValue: " << num << endl;
}

void byReference(int& num) {
    num = 30;
    cout << "Inside byReference: " << num << endl;
}

void byPointer(int* num) {
    *num = 40;
    cout << "Inside byPointer: " << *num << endl;
}

/// FUNCTION POINTERS
int sum(int a, int b) {
    return a + b;
}

int main()
{
    //std::cout << "Hello World!\n";


    // POINTER BASICS
 /*   int num = 10;
    int* ptr = &num;

    cout << "Before modification: " << num << endl;
    *ptr = 20;
    cout << "After modification: " << num << endl;*/

    
    // PASS BY VALUE, REFERENCE, POINTER
   /* int num = 10;

    cout << "Before byValue: " << num << endl;
    byValue(num);
    cout << "After byValue: " << num << endl;

    cout << "Before byReference: " << num << endl;
    byReference(num);
    cout << "After byReference: " << num << endl;

    cout << "Before byPointer: " << num << endl;
    byPointer(&num);
    cout << "After byPointer: " << num << endl;*/


    // ARRAY POINTER ARITHMETIC
    //int arr[] = { 1, 2, 3, 4, 5 };
    //int* ptr = arr;

    //for (int i = 0; i < 5; ++i) {
    //    cout << *(ptr + i) << " ";
    //}
    //cout << endl;

    /// DYNAMIC MEMORY ALLOCATION
    //int size = 5;
    //int* arr = new int[size];

    //for (int i = 0; i < size; ++i) {
    //    arr[i] = i + 1;
    //}

    //for (int i = 0; i < size; ++i) {
    //    cout << arr[i] << " ";
    //}
    //cout << endl;

    //delete[] arr;

   

    /// FUNCTION POINTERS
    int (*funcPtr)(int, int) = sum;

    int result = funcPtr(10, 20);
    cout << "Sum: " << result << endl;


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
