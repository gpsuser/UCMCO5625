# Introduction to Algorithms

Algorithms are at the heart of what we do as programmers. At their core, they are simply a set of step-by-step instructions that we give computers in order to solve specific problems or perform particular tasks. Every time you write a program, whether a simple script or a complex application, you are essentially defining an algorithm for the computer to follow.

In this session, we'll start by looking at what exactly algorithms are and why they are so crucial. Then we'll dive into some basic algorithmic building blocks and techniques that you'll use again and again - things like looping, recursion, searching, and basic data manipulation. Along the way, we'll implement practical examples in C++ to solidify these concepts.

By the end of this lecture, you should have a solid grasp of algorithmic thinking and be well prepared to go deeper into data structures and more complex algorithms. 

## I. What are Algorithms?

A. A set of unambiguous step-by-step instructions to solve a problem 
   - Like a recipe that a computer can follow to perform a task
   - Must be clear and precise enough that a computer can execute it
   
B. The foundation of programming and computer science
   - Every program you write is essentially an algorithm 
   - Algorithms allow us to automate processes and computations
   
C. Used for calculation, data processing, automation, and more
   - Algorithms are versatile tools that power all software  
   - Used in business, science, engineering, finance, and beyond

## II. Basic Algorithmic Building Blocks

To implement algorithms, there are some common techniques and patterns that come up again and again. Let's look at a few of the most essential ones.

### A. Loops

- Repeat a set of instructions a specified number of times
- Allow us to iterate through data structures like arrays 
- Two main types:
  - For loops: Iterate a set number of iterations 
  - While loops: Repeat until a condition is met
- In C++, basic syntax:

```cpp
// For loop
for (int i = 0; i < n; i++) {
    // Instructions to repeat
}

// While loop  
while (condition) {
   // Instructions to repeat
}
```

### B. Recursion  

- A function that calls itself to break a problem down
- Solves a problem by reducing it to a simpler subproblem
- Must have a base case to avoid infinite recursion
- Very powerful for certain problems like tree/graph traversal 
- Example - calculate factorial recursively:

```cpp
int factorial(int n) {
    if (n == 0) // Base case
        return 1;
    else    
        return n * factorial(n-1); // Recursive case
}
```

### C. Modular Design

- Break a larger problem/algorithm into smaller subproblems 
- Each piece (module) solves one part of the problem
- Modules are independent and reusable - good for testing  
- Combine modules together to solve the overall problem
- Key principle of software engineering for managing complexity

Now that we've seen these core concepts, let's apply them to a few practical algorithmic problems and techniques.

## III. Reversing an Array

A. The problem: Reverse the order of elements in an array

   - Input: An array of elements in one order
   - Output: The same elements in reverse order
   - This comes up frequently - worth knowing how to do it!
   
B. Approaching a solution  

   1. Observe: Reversing swaps first & last, second & second last, etc.  
   2. This insight leads us to two approaches:
      - Iterative: Use a loop to swap ends, moving inward 
      - Recursive: Swap ends, then recursively reverse the middle
      
C. Iterative implementation

```cpp
void reverseArrayIterative(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        swap(arr[i], arr[n-i-1]);
    }
}
```

- We loop to the midpoint, swapping pairs of elements
- Time complexity: O(n) - We traverse half the array
- Space complexity: O(1) - We do the reversing in-place

D. Recursive implementation  

```cpp
void reverseArrayRecursive(int arr[], int start, int end) {
    if (start >= end) 
        return;
    swap(arr[start], arr[end]);
    reverseArrayRecursive(arr, start + 1, end - 1);  
}
```

- If we're past the midpoint, we're done - that's our base case 
- Else, we swap start & end, and reverse the subarray in between
- Time complexity: O(n) - We make n/2 recursive calls
- Space complexity: O(n) due to the recursive call stack
   
So both give the correct result, but the iterative is cleaner and more efficient spacewise. Generally with clean iterative solutions, recursion is not needed. But it's a powerful tool to have!

## IV. Finding the Maximum and Minimum

A. The problem: Find the maximum and minimum elements in an array 
   - Input: An unsorted array  
   - Output: The min and max element values
   - Useful for data analysis, normalization, sorting, etc.
   
B. Naive approach
   - Keep track of the current max and min in variables  
   - Loop through array, updating max/min as we find new ones
   
```cpp
int findMin(int arr[], int n) {
    int min = arr[0]; 
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}
```

Finding max would work the same way, replacing `<` with `>`
   - Time complexity: O(n) - We must check every element 
   - Space complexity: O(1) - Just need min and max variables

C. C++ STL `<algorithm>` library
   - Provides `min_element` and `max_element` functions
   - Work on any kind of iterator range, including arrays
   
```cpp
#include <algorithm>
int myArray[] = {3, 1, 4, 1, 5};
int minVal = *min_element(myArray, myArray + 5);
int maxVal = *max_element(myArray, myArray + 5);
```

- More concise and convenient than writing a manual loop
- Still O(n) time complexity under the hood 

## V. Searching Algorithms

A. The problem: Find the position of a target value in a collection
   - Input: A collection (usually an array) and target value
   - Output: The position of the target if found, or an indicator otherwise
   - One of the most common computing tasks - databases, find/replace, etc.
   
B. Linear search  
   - Iterate through the array from the beginning, comparing to target 
   - Return position if found, else indicate not found

```cpp
int linearSearch(int arr[], int n, int target) {
   for (int i = 0; i < n; i++) {
       if (arr[i] == target) 
           return i; // Found at position i
   }
   return -1; // Not found
}
```

- Always works, even on unsorted data  
- Time: O(n) - May need to check all n elements, no early exit
- Space: O(1) - No extra space needed

C. Binary search (recursive)
   - Only works on sorted collections, but much faster
   - Repeatedly divide search space in half by comparing middle to target  

```cpp
int binarySearchRecursive(int arr[], int left, int right, int target) { 
   if (right >= left) { 
       int mid = left + (right - left) / 2; 
       // Check middle
       if (arr[mid] == target)   
           return mid;   
       // Recursively search left or right half
       if (arr[mid] > target)  
           return binarySearchRecursive(arr, left, mid - 1, target); 
       return binarySearchRecursive(arr, mid + 1, right, target); 
   }
   return -1; 
}
```

- Uses divide-and-conquer to rule out half the remaining space each time
- Time: O(log n) - Doubling input only adds one more step
- Space: O(log n) due to recursive stack
   
D. Binary search (iterative)
   - Same idea as recursive version, but using a loop instead
   - Avoids recursive call stack space

```cpp
int binarySearchIterative(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Check middle
        if (arr[mid] == target)
            return mid;
        
        // Adjust search range based on comparison
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    return -1; // Not found
}
```

- Loop continues until search range is empty
- Adjust `left` and `right` based on comparison to middle
- Time: Still O(log n) like recursive version
- Space: O(1) - no extra space like call stack needed

So in summary:
   
| Algorithm                | Data     | Time     | Space    | Strengths                                 | 
|--------------------------|----------|----------|----------|-------------------------------------------|
| Linear search            | Any      |  O(n)    | O(1)     | Always works, simple to write             |  
| Binary search (recursive)| Sorted   | O(log n) | O(log n) | Intuitive divide-and-conquer approach     |
| Binary search (iterative)| Sorted   | O(log n) | O(1)     | Space efficient, no recursion limit issues|

For most cases, the iterative binary search is ideal - clean, efficient, and no recursion to worry about. But it's good to understand both iterative and recursive approaches, as they represent two fundamental ways of thinking about algorithms.

## Conclusion

So in summary, today we looked at what algorithms are and how they form the foundation of programming and computer science. We examined some fundamental building blocks like loops, recursion, and modular design. Then we worked through three common algorithmic problems - reversing arrays, finding maximums and minimums, and searching - seeing multiple approaches and implementations for each.

The key takeaways are:
1. Understand your data - know what you're working with and what assumptions you can make
2. Think before you code - step back and break the problem down before diving in 
3. Consider time and space - be aware of the complexity your solution and tradeoffs you're making  
4. Use libraries when you can - don't reinvent the wheel if a well-tested solution already exists
5. Practice, practice, practice - work through lots of different problems to hone your skills

Algorithms are such an essential tool, but more than that, they're a way of thinking and problem solving. 
