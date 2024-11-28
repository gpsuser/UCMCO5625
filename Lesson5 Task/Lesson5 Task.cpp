// Lesson5 Task.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include <iostream>
//
//int main()
//{
//    std::cout << "Hello World!\n";
//}

#include <iostream>
#include <vector>
#include <sstream>

class dynArray {
private:
    std::vector<std::string> data;

public:
    // Default constructor
    dynArray() {}

    // Constructor that takes a string and a separator character
    dynArray(const std::string& str, char separator) {
        std::istringstream ss(str);
        std::string token;

        // Split the string based on the separator and store in the data vector
        while (std::getline(ss, token, separator)) {
            data.push_back(token);
            data.
        }
    }

    // Function to add a new element to the array
    void add(const std::string& element) {
        data.push_back(element);
    }

    // Function to print all elements in the array
    void print() const {
        for (const auto& elem : data) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    // Function to resize the array
    void resize(size_t newSize) {
        data.resize(newSize);
    }

    // Function to get the size of the array
    size_t size() const {
        return data.size();
    }

    // Overload the [] operator for array-like access
    std::string& operator[](size_t index) {
        return data.at(index);
    }

    const std::string& operator[](size_t index) const {
        return data.at(index);
    }
};

int main() {
    // Example usage
    dynArray d("one two three", ' ');
    d.print(); // Output: one two three 

    dynArray d2("one,two,and three", ',');
    d2.print(); // Output: one two and three 

    // Adding elements
    d.add("four");
    d.print(); // Output: one two three four 

    // Resizing the array
    d.resize(2);
    d.print(); // Output: one two 

    // Accessing elements
    std::cout << "Element at index 1: " << d[1] << std::endl; // Output: two

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
