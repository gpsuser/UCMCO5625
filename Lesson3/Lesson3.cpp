// Lesson3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include <iostream>
//
//int main()
//{
//    std::cout << "Hello World!\n";
//}


#include <iostream>
using std::cout;
using std::cin;

int main()
{
    // ADDRESSES
    int b = 27;
   
    cout << "The address of b is: " << &b;
    cout << "\nThe value of b is: " << b;

    cout << "\n\n";

    // POINTERS - store the memory address of another variable

    int* ptr; //a pointer to an int 	
    ptr = &b; //store b's address using ptr 
    
    cout << "Using a pointer - the address of b is: " << ptr;
    cout << "\nThe value of b is: " << b;

    cout << "\n\n";

    // DE-REFERENCING POINTERS - access the value at the address stored in the pointer
    int* ptr1 = &b;

    cout << "Address of b is : " << ptr1;
    cout << "\nValue of b,  by de-referencing the pointer, is: " << *ptr1;

    cout << "\n\n";

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
