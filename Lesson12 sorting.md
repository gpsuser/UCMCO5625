# Lecture 12 - Sorting Algorithms


# 1. Insertion Sort Algorithm

### Introduction

Insertion sort is one of the fundamental sorting algorithms in computer science. While it may not be the most efficient algorithm for large datasets, its simplicity, stability, and performance characteristics make it particularly useful in specific scenarios. In this document, we'll explore the algorithm in detail, understand when to use it, and see how it works through a concrete example.

### What is Insertion Sort?

Insertion sort is a comparison-based sorting algorithm that builds the final sorted array one element at a time. It operates by taking elements from the unsorted portion of the array and inserting them into their correct position in the sorted portion. This process mirrors how many people sort playing cards in their hands – they pick up one card at a time and insert it into its proper position among the cards they're already holding.

### Motivation and Use Cases

Insertion sort shines in several specific scenarios:

1. Small Datasets: For arrays with fewer than 50 elements, insertion sort can outperform more complex algorithms like quicksort due to its lower overhead.

2. Nearly Sorted Data: When dealing with arrays that are already partially sorted, insertion sort performs exceptionally well, approaching O(n) time complexity.

3. Online Sorting: If you need to sort data as it arrives (online sorting), insertion sort is ideal because it maintains a sorted subsection that can be added to at any time.

4. Memory Constraints: The algorithm sorts in-place, requiring only O(1) additional memory, making it suitable for memory-constrained environments.

### Step-by-Step Example

Let's walk through how insertion sort works using the following unsorted list of numbers:
[5, 2, 8, 1, 9]

#### Initial State
```
[5 | 2, 8, 1, 9]   // The vertical bar (|) separates sorted and unsorted portions
```

#### Step 1: Consider element 2
Current element: 2
Compare with 5 and shift:
```
[2, 5 | 8, 1, 9]   // 2 < 5, so 2 moves to position 0
```

#### Step 2: Consider element 8
Current element: 8
Compare with previous elements:
```
[2, 5, 8 | 1, 9]   // 8 > 5, so it stays in position 2
```

#### Step 3: Consider element 1
Current element: 1
Compare and shift larger elements:
```
[2, 5, 8, 8 | 9]   // Shift 8
[2, 5, 5, 8 | 9]   // Shift 5
[2, 2, 5, 8 | 9]   // Shift 2
[1, 2, 5, 8 | 9]   // Place 1 in position 0
```

#### Step 4: Consider element 9
Current element: 9
Compare with previous elements:
```
[1, 2, 5, 8, 9]    // 9 > 8, so it stays in position 4
```

### C++ Implementation

Here's a detailed implementation of the insertion sort algorithm in C++:

```cpp
#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& arr) {
    // Start from the second element (index 1)
    // The first element is considered sorted
    for (int i = 1; i < arr.size(); i++) {
        // Store the current element that we'll insert
        int key = arr[i];
        
        // Start comparing with previous elements
        int j = i - 1;
        
        // Move elements that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  // Shift element forward
            j--;                   // Move to previous position
        }
        
        // Place key in its correct position
        arr[j + 1] = key;
    }
}

// Utility function to print the array
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {5, 2, 8, 1, 9};
    
    std::cout << "Original array: ";
    printArray(arr);
    
    insertionSort(arr);
    
    std::cout << "Sorted array: ";
    printArray(arr);
    
    return 0;
}
```

### Time and Space Complexity Analysis

#### Time Complexity
- Best Case: O(n) - When the array is already sorted
- Average Case: O(n²) - When elements are in random order
- Worst Case: O(n²) - When the array is sorted in reverse order

#### Space Complexity
- O(1) - The algorithm sorts in-place, using only a constant amount of extra space

### Advantages and Disadvantages

#### Advantages
1. Simple implementation
2. Efficient for small data sets
3. Adaptive - Performance improves for partially sorted arrays
4. Stable - Maintains relative order of equal elements
5. In-place - Only requires a constant amount O(1) of additional memory space

#### Disadvantages
1. Quadratic time complexity makes it inefficient for large datasets
2. Requires shifting elements, which can be expensive for arrays
3. Not suitable for large datasets where more efficient algorithms like quicksort or mergesort would be better choices


Insertion sort, while simple, remains a practical choice for specific scenarios in modern programming. Its adaptiveness, stability, and excellent performance on small or nearly-sorted datasets make it a valuable tool in a programmer's algorithmic toolkit. Understanding when to use insertion sort versus other sorting algorithms is key to writing efficient and maintainable code.

When implementing sorting in your own projects, consider insertion sort when:
- Working with small datasets (fewer than 50 elements)
- Dealing with nearly sorted data
- Implementing online sorting (sorting data as it arrives)
- Operating under memory constraints
- Needing a stable sorting algorithm


## 2. Selection Sort

Selection sort is one of the fundamental sorting algorithms in computer science. While it may not be the most efficient algorithm for large datasets, its simplicity and intuitive nature make it an excellent learning tool for understanding sorting concepts. This document will explore the algorithm in detail, its implementation, and provide a step-by-step visualization of how it works.

### What is Selection Sort?

Selection sort is an in-place comparison sorting algorithm that divides the input list into two parts:
1. A sorted portion at the beginning of the list
2. An unsorted portion containing the remaining elements

The algorithm repeatedly selects the smallest element from the unsorted portion and adds it to the end of the sorted portion, gradually building up a sorted list from left to right.

### Motivation for Using Selection Sort

Selection sort offers several advantages that make it useful in specific scenarios:

1. **Simplicity**: The algorithm is straightforward to understand and implement, making it valuable for educational purposes and teaching sorting concepts.

2. **Memory Efficiency**: Selection sort is an in-place sorting algorithm, meaning it requires no additional memory space beyond the original array.

3. **Predictable Performance**: Unlike more complex algorithms, selection sort's performance is consistent across different input patterns, always performing the same number of comparisons for a given input size.

4. **Minimal Data Movement**: While selection sort makes many comparisons, it performs the minimum number of swaps (n-1 swaps for n elements) compared to other algorithms like bubble sort.

### Step-by-Step Example

Let's examine how selection sort works with the following unsorted list: `[64, 25, 12, 22, 11]`

#### Initial State
```
Unsorted array: [64, 25, 12, 22, 11]
Sorted portion: []
```

#### Step 1
- Search for minimum element in positions 0-4: 11
- Swap 11 with first element (64)
```
Current array:  [11, 25, 12, 22, 64]
Sorted portion: [11]
```

#### Step 2
- Search for minimum element in positions 1-4: 12
- Swap 12 with second element (25)
```
Current array:  [11, 12, 25, 22, 64]
Sorted portion: [11, 12]
```

#### Step 3
- Search for minimum element in positions 2-4: 22
- Swap 22 with third element (25)
```
Current array:  [11, 12, 22, 25, 64]
Sorted portion: [11, 12, 22]
```

#### Step 4
- Search for minimum element in positions 3-4: 25
- Element is already in correct position
```
Current array:  [11, 12, 22, 25, 64]
Sorted portion: [11, 12, 22, 25]
```

#### Final State
```
Sorted array: [11, 12, 22, 25, 64]
```

### C++ Implementation

Here's a detailed implementation of the selection sort algorithm in C++:

```cpp
#include <iostream>
#include <vector>

// Function to print the current state of the array
void printArray(const std::vector<int>& arr, int sortedIndex) {
    std::cout << "Array state: ";
    for(int i = 0; i < arr.size(); i++) {
        if(i <= sortedIndex) {
            std::cout << "[" << arr[i] << "] "; // Sorted portion in brackets
        } else {
            std::cout << arr[i] << " ";  // Unsorted portion
        }
    }
    std::cout << "\n";
}

// Selection sort implementation
void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    
    // Iterate through the array elements
    for(int i = 0; i < n-1; i++) {
        // Find the minimum element in the unsorted portion
        int min_idx = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        
        // Swap the found minimum element with the first element of the unsorted portion
        if(min_idx != i) {
            std::swap(arr[i], arr[min_idx]);
        }
        
        // Print the current state of the array
        std::cout << "Step " << i+1 << ":\n";
        std::cout << "Found minimum: " << arr[i] << " at index: " << i << "\n";
        printArray(arr, i);
        std::cout << "\n";
    }
}

int main() {
    std::vector<int> arr = {64, 25, 12, 22, 11};
    
    std::cout << "Original array:\n";
    printArray(arr, -1);
    std::cout << "\nSorting process:\n";
    
    selectionSort(arr);
    
    std::cout << "Final sorted array:\n";
    printArray(arr, arr.size()-1);
    
    return 0;
}
```

### Time Complexity Analysis

Selection sort has the following time complexities:

- **Best Case**: O(n²)
- **Average Case**: O(n²)
- **Worst Case**: O(n²)

Where n is the number of elements in the array.

The quadratic time complexity comes from the nested loops:
- The outer loop runs (n-1) times
- For each outer loop iteration, the inner loop runs (n-i-1) times
- This results in approximately (n²/2) comparisons

### Space Complexity

Selection sort has a space complexity of O(1) as it only requires a single additional memory space for the swap operation. This makes it memory efficient compared to algorithms that require additional space proportional to the input size.

### When to Use Selection Sort

Selection sort is most appropriate in the following scenarios:

1. When working with small datasets where the quadratic time complexity won't significantly impact performance.

2. In educational contexts where understanding sorting concepts is more important than performance.

3. When memory space is extremely limited and an in-place sorting algorithm is required.

4. When the cost of swapping elements is high compared to making comparisons, as selection sort minimizes the number of swaps.


Selection sort represents an important fundamental sorting algorithm that, while not optimal for large-scale applications, provides valuable insights into sorting concepts and algorithm design. Its simplicity and predictable behavior make it an excellent teaching tool and a useful algorithm for specific use cases where minimal memory usage or minimal swapping is required.

Understanding selection sort builds a strong foundation for learning more complex sorting algorithms and helps develop intuition about algorithm efficiency and trade-offs in computer science.


## 3. Bubble Sort Algorithm


Bubble sort is one of the fundamental sorting algorithms in computer science. While it may not be the most efficient algorithm for large datasets, understanding bubble sort is crucial because it introduces important concepts in algorithmic thinking and serves as a stepping stone to more complex sorting algorithms.

### What is Bubble Sort?

Bubble sort is a comparison-based sorting algorithm that repeatedly steps through a list, compares adjacent elements, and swaps them if they are in the wrong order. The algorithm gets its name from the way smaller elements "bubble" to the top of the list with each iteration.

### Motivation for Using Bubble Sort

Despite not being the most efficient sorting algorithm, bubble sort has several characteristics that make it valuable in certain scenarios:

1. **Simplicity**: The algorithm is straightforward to understand and implement, making it excellent for educational purposes.

2. **In-place Sorting**: Bubble sort modifies the array directly without requiring additional memory space (besides a single temporary variable for swapping).

3. **Stability**: It maintains the relative order of equal elements, which can be important in certain applications.

4. **Adaptive**: If the input is already nearly sorted, bubble sort can perform better than more complex algorithms due to its ability to detect when no more swaps are needed.

### Step-by-Step Example

Let's walk through how bubble sort works using a small list of numbers: `[64, 34, 25, 12, 22]`

#### First Pass:
1. Compare 64 and 34:
   - `[64, 34, 25, 12, 22]` → `[34, 64, 25, 12, 22]` (swap)
2. Compare 64 and 25:
   - `[34, 64, 25, 12, 22]` → `[34, 25, 64, 12, 22]` (swap)
3. Compare 64 and 12:
   - `[34, 25, 64, 12, 22]` → `[34, 25, 12, 64, 22]` (swap)
4. Compare 64 and 22:
   - `[34, 25, 12, 64, 22]` → `[34, 25, 12, 22, 64]` (swap)

#### Second Pass:
1. Compare 34 and 25:
   - `[34, 25, 12, 22, 64]` → `[25, 34, 12, 22, 64]` (swap)
2. Compare 34 and 12:
   - `[25, 34, 12, 22, 64]` → `[25, 12, 34, 22, 64]` (swap)
3. Compare 34 and 22:
   - `[25, 12, 34, 22, 64]` → `[25, 12, 22, 34, 64]` (swap)
4. Compare 34 and 64:
   - `[25, 12, 22, 34, 64]` → no swap needed

#### Third Pass:
1. Compare 25 and 12:
   - `[25, 12, 22, 34, 64]` → `[12, 25, 22, 34, 64]` (swap)
2. Compare 25 and 22:
   - `[12, 25, 22, 34, 64]` → `[12, 22, 25, 34, 64]` (swap)
3. Compare 25 and 34:
   - `[12, 22, 25, 34, 64]` → no swap needed
4. Compare 34 and 64:
   - `[12, 22, 25, 34, 64]` → no swap needed

#### Fourth Pass:
1. Compare all adjacent elements:
   - No swaps needed, array is sorted!

### C++ Implementation

Here's a detailed implementation of the bubble sort algorithm in C++:

```cpp
#include <iostream>
#include <vector>

class BubbleSort {
private:
    // Helper function to swap two elements
    static void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

public:
    // Main bubble sort function
    static void sort(std::vector<int>& arr) {
        int n = arr.size();
        bool swapped;
        
        // Outer loop for passes
        for (int i = 0; i < n - 1; i++) {
            swapped = false;
            
            // Inner loop for comparisons in each pass
            // Note: n-i-1 because after each pass, the largest element
            // is already in its correct position
            for (int j = 0; j < n - i - 1; j++) {
                // If current element is greater than next element, swap them
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            
            // If no swapping occurred in this pass, array is already sorted
            if (!swapped) {
                break;
            }
        }
    }
    
    // Utility function to print the array
    static void printArray(const std::vector<int>& arr) {
        for (int element : arr) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
};

// Example usage
int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22};
    
    std::cout << "Original array: ";
    BubbleSort::printArray(arr);
    
    BubbleSort::sort(arr);
    
    std::cout << "Sorted array: ";
    BubbleSort::printArray(arr);
    
    return 0;
}
```

### Key Implementation Details

1. **Optimization with `swapped` Flag**: 
   - The implementation includes a `swapped` boolean flag that tracks whether any swaps occurred in a pass
   - If no swaps occur in a pass, the array is already sorted, and we can exit early

2. **Class-based Structure**:
   - The implementation uses a class structure to encapsulate the sorting functionality
   - This provides a clean interface and separates the core algorithm from utility functions

3. **Use of References**:
   - The `swap` function uses references to avoid unnecessary copying
   - The main sort function takes a vector reference to modify the original array

4. **Time Complexity**:
   - Worst and Average Case: O(n²)
   - Best Case (already sorted): O(n)

5. **Space Complexity**:
   - O(1) as it only uses a constant amount of extra space

### Common Use Cases and Limitations

#### When to Use Bubble Sort:
- Educational purposes and understanding basic sorting concepts
- Small datasets where implementation simplicity is more important than efficiency
- When memory space is very limited
- When detecting whether a list is sorted is part of the requirement

#### Limitations:
- Poor performance on large datasets
- Not suitable for real-world applications with significant data volume
- More efficient algorithms like QuickSort or MergeSort are preferred for most practical applications



Bubble sort, while not the most efficient sorting algorithm, serves as an excellent introduction to sorting algorithms and demonstrates important programming concepts like loops, conditional statements, and in-place operations. Understanding bubble sort provides a solid foundation for learning more complex sorting algorithms and helps develop algorithmic thinking skills.



## 4. Merge Sort Algorithm

### Motivation

Merge sort is a comparison-based sorting algorithm that follows the divide-and-conquer paradigm. It is used for its efficiency and stability, especially when dealing with large datasets. 

The key idea behind merge sort is to break down the problem into smaller subproblems that are easier to solve, and then combine the solutions to these subproblems to solve the original problem.

### Algorithm Overview

1. Divide the unsorted list into n sublists, each containing one element (a list of one element is considered sorted).
2. Repeatedly merge sublists to produce new sorted sublists until there is only one sublist remaining. This will be the sorted list.

### Step-by-Step Example

Let's consider the following unsorted list of numbers: 

```
[38, 27, 43, 3, 9, 82, 10]
```

#### Step 1: Divide

We start by dividing the list into smaller sublists until each sublist contains only one element.
```
[38, 27, 43, 3, 9, 82, 10]
      /             \
[38, 27, 43, 3]    [9, 82, 10]
    /      \         /     \
[38, 27]  [43, 3]  [9, 82]  [10]
  /   \    /   \    /   \    |
[38]  [27][43] [3] [9]  [82] [10]
```

#### Step 2: Conquer (Merge)

Now we start merging the sublists back together in a sorted manner.

##### First Level Merging:

```
[38]  [27]  [43]  [3]  [9]  [82]  [10]
  \    /      \    /     \    /     |
  [27, 38]    [3, 43]   [9, 82]    [10]
```

##### Second Level Merging:

```
     [27, 38]       [3, 43]      [9, 82]       [10]
         \             /            \           /
         [3, 27, 38, 43]            [9, 10, 82]
```

##### Final Merge:

```
           [3, 27, 38, 43]                 [9, 10, 82]
                     \                       /
                     [3, 9, 10, 27, 38, 43, 82]
```

The list is now sorted!


#### Merging Process

The key operation in merge sort is the merging of two sorted lists into a single sorted list. 

Here's how it works:

* Create a result list and get references to the start of the two sublists to merge.
* Compare the first elements of each sublist.
* Put the smaller element into the result list and move the reference for that sublist forward by one.
* Repeat steps 2-3 until one of the sublists is exhausted.
* Copy the remaining elements from the other sublist into the result list.

For example, merging [3, 27, 38, 43] and [9, 10, 82] would go as follows:

Create result list [].

Compare 3 and 9.
3 is smaller.
Add it to result: [3].

Advance first sublist: [27, 38, 43] and [9, 10, 82].

Compare 27 and 9. 9 is smaller. Result: [3, 9]. Sublists: [27, 38, 43] and [10, 82].
Compare 27 and 10. 10 is smaller. Result: [3, 9, 10]. Sublists: [27, 38, 43] and [82].
Compare 27 and 82. 27 is smaller. Result: [3, 9, 10, 27]. Sublists: [38, 43] and [82].
Compare 38 and 82. 38 is smaller. Result: [3, 9, 10, 27, 38]. Sublists: [43] and [82].
Compare 43 and 82. 43 is smaller. Result: [3, 9, 10, 27, 38, 43]. Sublists: [] and [82].

First sublist exhausted. 

Copy remaining element 82 from second sublist. Final result: [3, 9, 10, 27, 38, 43, 82].

### C++ Implementation

```cpp
#include <iostream>
#include <vector>

using namespace std;

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
  
    // Create temp arrays
    vector<int> L(n1), R(n2);
  
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
  
    // Merge the temp arrays back into arr[l..r]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
  
    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
  
    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is right index of the sub-array of arr to be sorted 
void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) {
        return; //returns recursively
    }
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    int arr_size = arr.size();

    cout << "Given array is \n";
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";

    mergeSort(arr, 0, arr_size - 1);

    cout << "\nSorted array is \n";
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    return 0;
}
```

The `mergeSort` function is where the divide-and-conquer happens. It recursively divides the array into two halves until the subarray size becomes 1, and then merges the subarrays in a sorted manner using the `merge` function.

The `merge` function is used for merging two halves. It assumes that `arr[l..m]` and `arr[m+1..r]` are sorted and merges them into one sorted array.

Merge Sort has a time complexity of O(n log n) in all cases (worst, average and best) as merging two sorted arrays is proportional to the total number of elements in the arrays.



## 5. QuickSort Algorithm

QuickSort is one of the most efficient and widely used sorting algorithms in computer science. Developed by Tony Hoare in 1959, it revolutionized the way we think about sorting data. The algorithm follows a divide-and-conquer strategy, which means it breaks down a complex problem into smaller, more manageable subproblems.

### Why Use QuickSort?

QuickSort's popularity stems from several key advantages:

1. **Efficiency**: QuickSort achieves an average time complexity of O(n log n), making it one of the fastest sorting algorithms available.
2. **In-place Sorting**: It requires only a small auxiliary stack space of O(log n), as it sorts the elements within the array itself.
3. **Cache Efficiency**: Due to its in-place nature and good locality of reference, QuickSort performs well with modern computer architectures.
4. **Adaptability**: The algorithm can be modified to handle different types of data and various optimization scenarios.

### How QuickSort Works

QuickSort operates through the following fundamental steps:

1. **Choose a Pivot**: Select an element from the array to serve as a pivot point.
2. **Partitioning**: Rearrange the array so that:
   - All elements less than the pivot come before it
   - All elements greater than the pivot come after it
3. **Recursion**: Recursively apply the same process to the subarrays on either side of the pivot.

### Detailed Example

Let's walk through sorting the following array: `[7, 2, 1, 6, 8, 5, 3, 4]`

#### Step-by-Step Partitioning Process

**Initial Array**: `[7, 2, 1, 6, 8, 5, 3, 4]`
Choosing the last element (4) as pivot.

**Step 1 - First Partition:**
```
Initial:     [7, 2, 1, 6, 8, 5, 3, 4]
                                   ^
                                 pivot
After partition:
Less than 4:    [2, 1, 3]
Equal to 4:     [4]
Greater than 4: [7, 6, 8, 5]
```

**Step 2 - Recursive Partitioning of Left Subarray:**
```
Left subarray: [2, 1, 3]
Choose 3 as pivot
After partition:
Less than 3:    [2, 1]
Equal to 3:     [3]
Greater than 3: []
```

**Step 3 - Recursive Partitioning of [2, 1]:**
```
Subarray: [2, 1]
Choose 1 as pivot
After partition:
Less than 1:    []
Equal to 1:     [1]
Greater than 1: [2]
```

**Step 4 - Recursive Partitioning of Right Subarray:**
```
Right subarray: [7, 6, 8, 5]
Choose 5 as pivot
After partition:
Less than 5:    []
Equal to 5:     [5]
Greater than 5: [7, 6, 8]
```

**Final Step - Combining All Partitions:**
```
Sorted Result: [1, 2, 3, 4, 5, 6, 7, 8]
```

### C++ Implementation

```cpp
#include <iostream>
#include <vector>

// Function to swap two elements in the array
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function that selects the last element as pivot
// and places it in its correct position in the sorted array
int partition(std::vector<int>& arr, int low, int high) {
    // Select the rightmost element as pivot
    int pivot = arr[high];
    
    // Index of smaller element
    int i = low - 1;
    
    // Traverse through all elements
    // Compare each element with pivot
    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    
    // Place pivot in its correct position
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// The main QuickSort function
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[pi] is now at right place
        int pi = partition(arr, low, high);
        
        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Utility function to print the array
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Example usage
int main() {
    std::vector<int> arr = {7, 2, 1, 6, 8, 5, 3, 4};
    
    std::cout << "Original array: ";
    printArray(arr);
    
    quickSort(arr, 0, arr.size() - 1);
    
    std::cout << "Sorted array: ";
    printArray(arr);
    
    return 0;
}
```

### Time Complexity Analysis

1. **Best Case**: O(n log n)
   - Occurs when the pivot always divides the array into equal or nearly equal parts
   
2. **Average Case**: O(n log n)
   - Expected performance with random data
   - Each partition divides the array into roughly equal parts
   
3. **Worst Case**: O(n²)
   - Occurs when the pivot is always the smallest or largest element
   - Can happen with already sorted or reverse sorted arrays
   
### Space Complexity

- **Auxiliary Space**: O(log n)
  - Required for the recursive call stack
  - Can be reduced to O(1) with tail recursion optimization

### Optimization Techniques

1. **Pivot Selection**:
   - Choose median of first, middle, and last elements
   - Random selection
   - Median-of-three method

2. **Handling Small Subarrays**:
   - Use insertion sort for arrays smaller than a threshold (typically 10-20 elements)
   - Reduces overhead of recursion for small arrays

3. **Three-Way Partitioning**:
   - Efficient for arrays with many duplicate elements
   - Separates elements into three groups: less than, equal to, and greater than pivot

### Best Practices and Common Pitfalls

1. **When to Use QuickSort**:
   - Large datasets where average case performance is important
   - When in-place sorting is required
   - When stable sorting is not necessary

2. **When to Avoid QuickSort**:
   - When dealing with nearly sorted data
   - When stable sorting is required
   - When working with very small arrays

3. **Common Mistakes**:
   - Poor pivot selection strategy
   - Not handling edge cases (empty arrays, single elements)
   - Incorrect partition implementation


QuickSort remains one of the most practical and efficient sorting algorithms available. Its combination of good average-case performance, in-place sorting, and cache efficiency makes it the sorting algorithm of choice in many standard libraries and real-world applications. Understanding its implementation details and optimization techniques is crucial for any programmer working with data sorting and manipulation.

## 6. Radix Sort

### Introduction to Radix Sort

Radix sort is a non-comparative integer sorting algorithm that processes numbers digit by digit, from least significant to most significant position. Unlike comparison-based sorting algorithms like quicksort or mergesort, radix sort exploits the fact that information about the size of a number is encoded in the number of digits it has and the value of each digit.

### Motivation Behind Radix Sort

The primary motivation for using radix sort comes from its ability to sort integers in linear time O(d * n), where d is the number of digits in the largest number and n is the number of elements to sort. This can be more efficient than comparison-based sorting algorithms, which have a theoretical lower bound of O(n log n).

Some key advantages that motivate the use of radix sort include:

1. Linear time complexity when the numbers have a fixed number of digits
2. Stable sorting algorithm - maintains relative order of equal elements
3. Works well with fixed-length integer or string keys
4. Particularly efficient when the range of possible digits is small compared to the number of items

### How Radix Sort Works

Radix sort follows these fundamental steps:

1. Find the maximum number in the array to determine the number of digits
2. For each digit position, starting from least significant to most significant:
   - Use counting sort as a subroutine to sort numbers based on the current digit position
   - Rebuild the array for the next iteration

Let's walk through a detailed example to understand how radix sort processes a list of numbers.

#### Detailed Example

Let's sort the following list of numbers: [170, 45, 75, 90, 802, 24, 2, 66]

##### Step-by-Step Process:

**Initial Array**: [170, 45, 75, 90, 802, 24, 2, 66]

**First Pass (Sorting by ones place):**
```
170 → 0
045 → 5
075 → 5
090 → 0
802 → 2
024 → 4
002 → 2
066 → 6

After first pass: [170, 90, 802, 2, 24, 45, 75, 66]
```

**Second Pass (Sorting by tens place):**
```
170 → 7
090 → 9
802 → 0
002 → 0
024 → 2
045 → 4
075 → 7
066 → 6

After second pass: [802, 2, 24, 45, 66, 170, 75, 90]
```

**Third Pass (Sorting by hundreds place):**
```
802 → 8
002 → 0
024 → 0
045 → 0
066 → 0
170 → 1
075 → 0
090 → 0

Final result: [2, 24, 45, 66, 75, 90, 170, 802]
```

### C++ Implementation

Here's a detailed C++ implementation of radix sort with extensive comments explaining each step:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

class RadixSort {
private:
    // Helper function to get the maximum number in the array
    static int getMax(const std::vector<int>& arr) {
        return *std::max_element(arr.begin(), arr.end());
    }
    
    // Helper function to perform counting sort for a specific digit position
    static void countingSort(std::vector<int>& arr, int exp) {
        std::vector<int> output(arr.size());
        std::vector<int> count(10, 0);  // Array to store count of digits (0-9)
        
        // Store count of occurrences of current digit
        for(int i = 0; i < arr.size(); i++) {
            count[(arr[i] / exp) % 10]++;
        }
        
        // Modify count array to contain actual positions
        for(int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        
        // Build the output array
        for(int i = arr.size() - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }
        
        // Copy the output array back to the input array
        for(int i = 0; i < arr.size(); i++) {
            arr[i] = output[i];
        }
    }

public:
    static void sort(std::vector<int>& arr) {
        // Find the maximum number to know the number of digits
        int max = getMax(arr);
        
        // Perform counting sort for every digit position
        // Starting from least significant digit to most significant digit
        for(int exp = 1; max/exp > 0; exp *= 10) {
            countingSort(arr, exp);
            
            // Print the array after each pass (for demonstration)
            std::cout << "After sorting by " << exp << "'s place: ";
            for(int num : arr) {
                std::cout << num << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    
    std::cout << "Original array: ";
    for(int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    RadixSort::sort(arr);
    
    std::cout << "Sorted array: ";
    for(int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
```

### Time and Space Complexity Analysis

Let's analyze the complexity of radix sort:

**Time Complexity:**
- Let d be the number of digits in the largest number
- Let n be the number of elements in the array
- For each digit (d iterations):
  - We perform counting sort which takes O(n) time
- Total time complexity: O(d * n)

**Space Complexity:**
- We need additional arrays for counting sort:
  - Output array of size n
  - Count array of size 10 (for decimal digits)
- Total space complexity: O(n)

### Practical Considerations

When implementing radix sort, consider these practical aspects:

1. **Data Distribution**: Radix sort works best when the numbers have similar numbers of digits. If the numbers vary greatly in size, the algorithm might need to process many empty digit positions.

2. **Memory Usage**: While radix sort has linear time complexity, it requires extra space for the counting sort procedure. This might be a consideration in memory-constrained environments.

3. **Stable Sorting**: Radix sort is stable, meaning it preserves the relative order of equal elements. This can be important in certain applications where maintaining the original order of equal elements is necessary.

4. **Integer-Only Limitation**: The basic implementation works only with integers. Modifications are needed to sort floating-point numbers or strings.


Radix sort is a powerful algorithm when working with integers or fixed-length strings. Its linear time complexity makes it particularly efficient for large datasets where the numbers have a relatively small number of digits. However, its applicability is limited to specific types of data, and the need for extra space should be considered when choosing this algorithm for a particular application.

The implementation provided above demonstrates the algorithm's elegance and efficiency, while the step-by-step example helps understand how the algorithm progressively sorts the data by processing each digit position. Understanding both the theoretical aspects and practical implementation details is crucial for effectively utilizing radix sort in real-world applications.