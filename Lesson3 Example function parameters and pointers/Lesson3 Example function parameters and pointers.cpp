// Lesson3 Example function parameters and pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void halfValue(int n)
{
    n /= 2;   // same as n = n / 2
}
void halfReference(int& n)
{
    n /= 2;  // same as n = n / 2
}
void halfPointer(int* n)
{
	//must dereference pointer to access value
	// this will always return an int - even if the value should have a decimal component 
    *n /= 2;		 // same as *n = *n / 2
	
}


// NOTICE HOW THE ABOVE FUNCTIONS ARE DEFINED AS VOID, 
// BECAUSE THEY DO NOT RETURN A VALUE, 
// THEY ONLY MODIFY THE VALUE OF THE VARIABLE PASSED TO THEM

int main()
{
    //std::cout << "Hello World!\n";

	int number = 10;

	// this passes the value of a variable (i.e. by value)
	halfValue(number);
	std::cout << "Output from passing by value: " << number << "\n";
	
	// this passes the address of a variable (i.e. by reference)
	halfReference(number);
	//std::cout << number << "\n";
	std::cout << "Output from passing by reference: " << number << "\n";
	
	// this passes a pointer to the address of a variable (i.e. by pointer)
	halfPointer(&number);		//must pass the address of number
	std::cout << "Output from passing by pointer: " << number << "\n";





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
