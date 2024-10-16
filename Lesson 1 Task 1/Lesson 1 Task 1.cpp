// Lesson 1 Task 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

bool isVowel(char c) {
    char vowels[] = { 'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u' };
    for (char v : vowels) {
        if (c == v) {
            return true;
        }
    }
    return false;
}

int main() {
    for (char c = 'A'; c <= 'Z'; ++c) {
        std::cout << "ASCII code for " << c << ": " << int(c);
        if (isVowel(c)) {
            std::cout << ", which is a vowel.";
        }
        else {
            std::cout << ", which is a consonant.";
        }
        std::cout << std::endl;
    }

    for (char c = 'a'; c <= 'z'; ++c) {
        std::cout << "ASCII code for " << c << ": " << int(c);
        if (isVowel(c)) {
            std::cout << ", which is a vowel.";
        }
        else {
            std::cout << ", which is a consonant.";
        }
        std::cout << std::endl;
    }

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
