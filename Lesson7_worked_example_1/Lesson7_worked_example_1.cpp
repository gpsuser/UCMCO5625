// Lesson7_worked_example_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
/// <summary>
/// area of rectangle
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="a"></param>
/// <param name="b"></param>
/// <returns></returns>
template <typename T> 
T area (T a, T b)
{
	return a * b;
}


int main()
{
	std::cout << "Hello World!\n";
	std::cout << area(7, 6) << std::endl;
	std::cout << area(2.5, 3.5) << std::endl;
	std::cout << area(2.5f, 3.5f) << std::endl;
	
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
