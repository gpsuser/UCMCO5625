# Week 12 - Sorting Algorithms 

## Introduction

In this lecture we will cover several fundamental sorting algorithms that are essential for any computer science student to understand. Sorting is the process of arranging items in a particular order, such as alphabetical, numerical, or by some other attribute. 

As a core operation in computing, understanding how different sorting algorithms work, along with their strengths, weaknesses and performance characteristics, provides an important foundation for designing efficient software.

## Objectives

By the end of this lecture, you should be able to:

1. Describe how the insertion sort, selection sort, bubble sort, merge sort, quick sort, and radix sort algorithms work
2. Identify scenarios where each sorting algorithm is most appropriate to use
3. Analyze the time complexity of the covered sorting algorithms using big O notation
4. Implement basic versions of each sorting algorithm in C++

## Sorting Algorithms

### 1. Insertion Sort

#### a. Definition 

Insertion sort is a simple comparison-based sorting algorithm that builds the final sorted list one element at a time. 

It iterates through the input list, removing one element per iteration, finds the location it belongs in the sorted list, and inserts it there, repeating until no input elements remain.

#### b. Application and guidelines for use

Insertion sort is an efficient algorithm for sorting a small number of elements. It is often used as part of more sophisticated algorithms such as quick sort when the number of elements is below a certain threshold. 

Due to its quadratic time complexity, it becomes less practical for larger lists. However, it has several advantages:

- It is very simple to implement 
- It is efficient for small data sets
- It is adaptive, i.e., efficient for data sets that are already substantially sorted
- It is stable, i.e., does not change the relative order of elements with equal keys
- It is an in-place sorting algorithm, i.e., only requires a constant amount O(1) of additional memory space

#### c. Worked example with a list of numbers

Let's consider the following list of numbers: 

`[5, 2, 4, 6, 1, 3]`

We start from the second element, comparing each element with the ones before it, swapping if necessary.

1. Compare 2 with elements to its left, in this case 5. Since 2 is smaller, swap them:
   `[2, 5, 4, 6, 1, 3]`

2. Move to 4. Compare 4 with elements to its left (5). No swapping needed as 4 is already in its correct position: 
   `[2, 5, 4, 6, 1, 3]`
   
3. Compare 6 with elements to its left (4, 5). No swapping needed:
   `[2, 5, 4, 6, 1, 3]`

4. Compare 1 with elements to its left (6, 4, 5, 2). Swap 1 and 6, then 1 and 4, then 1 and 5, then 1 and 2:
   `[2, 5, 4, 1, 6, 3]` 
   `[2, 5, 1, 4, 6, 3]`
   `[2, 1, 5, 4, 6, 3]` 
   `[1, 2, 5, 4, 6, 3]`

5. Compare 3 with elements to its left (6, 4, 5, 2, 1). Swap 3 and 6, then 3 and 4, then 3 and 5:  
   `[1, 2, 5, 4, 3, 6]`
   `[1, 2, 5, 3, 4, 6]`
   `[1, 2, 3, 5, 4, 6]`

The list is now sorted:
`[1, 2, 3, 4, 5, 6]`

#### d. Worked example (C++)

```cpp
void insertionSort(int arr[], int n) 
{ 
    for (int i = 1; i < n; i++) { 
        int key = arr[i]; 
        int j = i - 1; 
  
        /* Move elements of arr[0..i-1], that are 
        greater than key, to one position ahead 
        of their current position */
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
} 
```

#### e. Time complexity

Insertion sort has a time complexity of O(n^2) in the average and worst cases, where n is the number of items being sorted. This is because there are two nested loops in the algorithm.

However, in the best case (where the list is already sorted), the time complexity is O(n), as the inner loop will not trigger any swaps.

### 2. Selection Sort

#### a. Definition

Selection sort is an in-place comparison-based sorting algorithm. It divides the input list into two parts: a sorted portion at the left end and an unsorted portion at the right end. Initially, the sorted portion is empty. 

The algorithm proceeds by finding the smallest element in the unsorted portion, swapping it with the leftmost unsorted element, and moving the sublist boundaries one element to the right.

#### b. Application and guidelines for use

Selection sort is noted for its simplicity and has performance advantages over more complicated algorithms in certain situations, particularly where auxiliary memory is limited.

However, it is not a very efficient algorithm for large lists, as its average and worst-case time complexity is `O(n^2)`, where n is the number of items being sorted.

Selection sort is an in-place sorting algorithm, i.e., it does not require any extra storage space.

#### c. Worked example with a list of numbers

Let's again consider the list: 

`[5, 2, 4, 6, 1, 3]`

In the first pass, we find the minimum element (1) and swap it with the first element (5):

`[1, 2, 4, 6, 5, 3]`

In the second pass, we start from the second element, find the minimum element in the remaining unsorted list (2), and swap it with the second element:

`[1, 2, 4, 6, 5, 3]`

In the third pass, we start from the third element, find the minimum element in the remaining unsorted list (3), and swap it with the third element (4):

`[1, 2, 3, 6, 5, 4]`

The process continues until the entire list is sorted:

`[1, 2, 3, 4, 5, 6]`

#### d. Worked example (C++)

```cpp
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        int min_idx = i;
        for (int j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
 
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}
```

#### e. Time complexity

The time complexity of Selection Sort is` O(n^2)` as there are two nested loops:

- One loop to select an element of Array one by one = `O(n)`
- Another loop to compare that element with every other Array element = O(n)

Therefore overall complexity = `O(n) * O(n) = O(n^2)`

### 3. Bubble Sort

#### a. Definition

Bubble sort, sometimes referred to as sinking sort, is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted.

#### b. Application and guidelines for use

Bubble sort is a simple algorithm to implement and understand. However, it is very inefficient as its average and worst case complexity are of `O(n^2)` where n is the number of items to be sorted. 

Bubble sort is not suitable for large data sets. But for small data sets, bubble sort provides a simple and intuitive approach to sorting.

#### c. Worked example with a list of numbers

Let's sort the list `[5, 1, 4, 2, 8]` using Bubble Sort.

First Pass:
- `[5, 1, 4, 2, 8]` -> `[1, 5, 4, 2, 8]`, swaps 5 and 1 
- `[1, 5, 4, 2, 8]` -> `[1, 4, 5, 2, 8]`, swaps 5 and 4
- `[1, 4, 5, 2, 8]` -> `[1, 4, 2, 5, 8]`, swaps 5 and 2
- `[1, 4, 2, 5, 8]` -> `[1, 4, 2, 5, 8]`, no swaps needed

Second Pass:
- `[1, 4, 2, 5, 8]` -> `[1, 4, 2, 5, 8]`, no swaps needed
- `[1, 4, 2, 5, 8]` -> `[1, 2, 4, 5, 8]`, swaps 4 and 2
- `[1, 2, 4, 5, 8]` -> `[1, 2, 4, 5, 8]`, no swaps needed
- `[1, 2, 4, 5, 8]` -> `[1, 2, 4, 5, 8]`, no swaps needed

Now, the array is already sorted, but the algorithm does not know if it is completed. The algorithm needs one whole pass without any swaps to know it is sorted.

Third Pass:
- `[1, 2, 4, 5, 8]` -> `[1, 2, 4, 5, 8]`, no swaps needed
- `[1, 2, 4, 5, 8]` -> `[1, 2, 4, 5, 8]`, no swaps needed
- `[1, 2, 4, 5, 8]` -> `[1, 2, 4, 5, 8]`, no swaps needed
- `[1, 2, 4, 5, 8]` -> `[1, 2, 4, 5, 8]`, no swaps needed

The list is now sorted: `[1, 2, 4, 5, 8]`

#### d. Worked example (C++)

```cpp
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)    
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}
```

#### e. Time complexity

Bubble Sort has an average and worst-case time complexity of O(n^2), where n is the number of items being sorted. This is because:

1. In each iteration, it compares each element with its adjacent element - `O(n)`
2. In the worst case, we need n-1 iterations to sort the array - `O(n)`

Therefore, the overall complexity is `O(n^2)`.

The best case time complexity is `O(n)` when the array is already sorted.

### 4. Merge Sort

#### a. Definition

Merge sort is a divide-and-conquer algorithm. It divides the input array into two halves, calls itself for the two halves, and then merges the two sorted halves. The merge() function is used for merging two halves.

#### b. Application and guidelines for use

Merge sort is a very efficient sorting algorithm - it has a time complexity of `O(n log n)`.  This means that it will take less time than algorithms like insertion sort or selection sort when sorting large datasets.

However, merge sort requires additional space proportional to the size of the list being sorted. In the worst case, the space complexity is `O(n)`. This is because it creates temporary arrays during the merge process.

Merge sort is a stable sort, meaning that the relative order of equal elements is preserved. It's also not an in-place sorting algorithm due to its space complexity.

#### c. Worked example with a list of numbers

Let's consider the list `[38, 27, 43, 3, 9, 82, 10]`

1. Divide the list into two halves:
   `[38, 27, 43, 3]` and `[9, 82, 10]`

2. Recursively sort the two halves:
   `[27, 3, 38, 43]` and `[9, 10, 82]` 

3. Merge the sorted halves:
   `[3, 9, 10, 27, 38, 43, 82]`

The list is now sorted.

#### d. Worked example (C++)

```cpp
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // Create temp arrays
    int L[n1], R[n2];
 
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    // Merge the temp arrays back into arr[l..r]
 
    // Initial index of first subarray
    int i = 0;
 
    // Initial index of second subarray
    int j = 0;
 
    // Initial index of merged subarray
    int k = l;
 
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
 
    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int arr[],int l,int r){
    if(l>=r){
        return;//returns recursively
    }
    int m =l+ (r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}
```

#### e. Time complexity

The time complexity of Merge Sort is `O(n log n)` in all 3 cases (worst, average and best) as merge sort always divides the array into two halves and takes linear time to merge two halves.

Let's derive the time complexity:

- If we have an array of size n, we divide it into two halves. Let's assume the time complexity of merging these two halves is f(n).
- Now, we have two arrays of size n/2. To sort these arrays, the time complexity for each will be f(n/2).
- Total time complexity: f(n) = 2f(n/2) + O(n), where O(n) is the time to merge the two halves.
- Using the Master Theorem, we get the time complexity as `O(n log n)`.

The space complexity of Merge Sort is `O(n) `as we are creating temporary arrays in every recursive call.

### 5. Quick Sort

#### a. Definition

Quick Sort is a divide-and-conquer algorithm that works by selecting a 'pivot' element from the array and partitioning the other elements into two sub-arrays, according to whether they are less than or greater than the pivot. The sub-arrays are then recursively sorted.

#### b. Application and guidelines for use

Quick Sort is particularly effective when:

Working with large datasets
Memory space is limited (as it can be implemented with in-place partitioning)
Average-case performance is more important than worst-case guarantees
Random access to elements is efficient (like in arrays)


The basic idea of quicksort is to select a pivot element from the list and partition the other elements into two sublists, one with elements less than the pivot and another with elements greater than the pivot. The pivot selection and partitioning process is repeated recursively on the sublists until the list is sorted.

Guidelines for optimal use:

Choose an appropriate pivot selection strategy
Consider the characteristics of your input data
Be aware of the stack space requirements for recursion
Implement a hybrid approach with insertion sort for small subarrays


#### c. Worked example with a list of numbers

We'll use the following list for our example:

[8, 3, 1, 7, 2, 5, 4, 6]

## Step 1: Choose a pivot element
- In this example, let's choose the last element, 6, as the pivot.
- The list is now: [8, 3, 1, 7, 2, 5, 4, (6)]

## Step 2: Partition the list
- Move elements less than the pivot to the left and elements greater than the pivot to the right.
- After partitioning, the list becomes: [3, 1, 2, 5, 4, (6), 8, 7]
- The pivot element (6) is now in its final sorted position.

## Step 3: Recursively apply quicksort to the sublists
- The list is divided into two sublists: [3, 1, 2, 5, 4] and [8, 7]
- Recursively apply steps 1-3 to each sublist.

### Sublist 1: [3, 1, 2, 5, 4]
- Choose 4 as the pivot
- After partitioning: [3, 1, 2, (4), 5]
- Sublists: [3, 1, 2] and [5]

#### Sublist 1.1: [3, 1, 2]
- Choose 2 as the pivot
- After partitioning: [1, (2), 3]
- Sublists: [1] and [3]
- Both sublists have only one element, so they are sorted.

#### Sublist 1.2: [5]
- Only one element, already sorted.

### Sublist 2: [8, 7]
- Choose 7 as the pivot
- After partitioning: [(7), 8]
- Sublists: [] and [8]
- Both sublists have one or zero elements, so they are sorted.

The final sorted list: [1, 2, 3, 4, 5, 6, 7, 8]

#### d. Worked example (C++)

```cpp
#include <iostream>
#include <vector>

class QuickSort {
private:
    // Partition function that arranges elements around a pivot
    int partition(std::vector<int>& arr, int low, int high) {
        int pivot = arr[high];    // Choose the rightmost element as pivot
        int i = (low - 1);        // Index of smaller element

        for (int j = low; j <= high - 1; j++) {
            // If current element is smaller than or equal to pivot
            if (arr[j] <= pivot) {
                i++;    // Increment index of smaller element
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        return (i + 1);
    }

public:
    // Main quicksort function
    void quickSort(std::vector<int>& arr, int low, int high) {
        if (low < high) {
            // pi is partitioning index
            int pi = partition(arr, low, high);

            // Separately sort elements before and after partition
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
};

// Usage example
int main() {
    std::vector<int> arr = {8, 3, 1, 7, 2, 5, 4, 6};
    QuickSort sorter;
    
    std::cout << "Original array: ";
    for (int num : arr) std::cout << num << " ";
    
    sorter.quickSort(arr, 0, arr.size() - 1);
    
    std::cout << "\nSorted array: ";
    for (int num : arr) std::cout << num << " ";
    
    return 0;
}
```

In this implementation:
1. We define the base case: if the list has 0 or 1 elements, it's already sorted, so we return the list as is.
2. We choose the last element as the pivot.
3. We partition the list into two sublists using list comprehensions: `left` contains elements less than the pivot, and `right` contains elements greater than or equal to the pivot.
4. We recursively apply quicksort to the `left` and `right` sublists and combine the results with the pivot in the middle.

The output will be:
```
[1, 2, 3, 4, 5, 6, 7, 8]
```

#### e. Time complexity

Quick Sort's time complexity varies depending on the pivot selection and input data:

Best Case: O(n log n)

Occurs when the pivot always divides the array into equal halves
Each level of recursion processes n elements
There are log n levels


Average Case: O(n log n)

Occurs with random pivot selection
Most practical implementations achieve this


Worst Case: `O(n²)`

Occurs when the pivot is always the smallest or largest element
Common with already sorted arrays if last/first element is chosen as pivot



Space Complexity:` O(log n) `for recursion stack in the average case

### 6. Radix Sort

#### a. Definition

Radix Sort is a non-comparative integer sorting algorithm that sorts data with integer keys by grouping the keys by individual digits that share the same significant position and value. It processes each digit position, starting from the least significant digit to the most significant digit.

#### b. Application and guidelines for use

Radix Sort is particularly effective when:

Sorting integers or strings of fixed length
The range of possible digits is relatively small
Stable sorting is required
Memory usage is not a primary concern

Guidelines for optimal use:

Ensure input data consists of fixed-length integers or strings
Consider available memory (as it requires additional space)
Compare the range of possible digits with input size
Use counting sort as a subroutine for each digit

#### c. Worked example with a list of numbers

Let's sort the array: [170, 45, 75, 90, 802, 24, 2, 66]

Step-by-step sorting by digit position:

First Pass (Sort by ones place):
CopyInitial: [170, 45, 75, 90, 802, 24, 2, 66]

After:   [170, 90, 2, 802, 24, 45, 75, 66]
          ^    ^   ^   ^    ^   ^   ^   ^
          0    0   2   2    4   5   5   6

Second Pass (Sort by tens place):
CopyBefore: [170, 90, 2, 802, 24, 45, 75, 66]

After:  [2, 802, 24, 45, 66, 170, 75, 90]
        ^   ^    ^   ^   ^    ^   ^   ^
        02  02   24  45  66   70  75  90

Third Pass (Sort by hundreds place):
CopyBefore: [2, 802, 24, 45, 66, 170, 75, 90]

After:  [2, 24, 45, 66, 75, 90, 170,802]

#### d. Worked example (C++)

```cpp
#include <iostream>
#include <vector>

class RadixSort {
private:
    // Function to get maximum value in arr[]
    int getMax(const std::vector<int>& arr) {
        int max = arr[0];
        for (int i = 1; i < arr.size(); i++)
            if (arr[i] > max)
                max = arr[i];
        return max;
    }

    // Counting sort for a specific digit position
    void countSort(std::vector<int>& arr, int exp) {
        std::vector<int> output(arr.size());
        std::vector<int> count(10, 0);

        // Store count of occurrences
        for (int i = 0; i < arr.size(); i++)
            count[(arr[i] / exp) % 10]++;

        // Change count[i] to contain actual position
        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        // Build the output array
        for (int i = arr.size() - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        // Copy output array to arr[]
        for (int i = 0; i < arr.size(); i++)
            arr[i] = output[i];
    }

public:
    void radixSort(std::vector<int>& arr) {
        int m = getMax(arr);

        // Do counting sort for every digit
        for (int exp = 1; m / exp > 0; exp *= 10)
            countSort(arr, exp);
    }
};

// Usage example
int main() {
    std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    RadixSort sorter;
    
    std::cout << "Original array: ";
    for (int num : arr) std::cout << num << " ";
    
    sorter.radixSort(arr);
    
    std::cout << "\nSorted array: ";
    for (int num : arr) std::cout << num << " ";
    
    return 0;
}

```

#### e. Time complexity

Radix Sort's time complexity is determined by:

n: number of elements
d: number of digits in the largest number

Time Complexity: `O(d * (n + k))`

where k is the range of values for each digit (typically 10 for decimal numbers)
If d is constant and k is small relative to n, this simplifies to O(n)

Space Complexity: `O(n + k)`

Additional space needed for counting sort at each digit position

## Summary and Comparison

Below is a comprehensive table comparing these sorting algorithms. 

| Algorithm | Description | Motivation/Use Cases | Time Complexity |
|-----------|-------------|---------------------|-----------------|
| Insertion Sort | Works by building a sorted array one element at a time, repeatedly inserting a new element into the sorted portion by shifting larger elements right. Similar to how most people sort playing cards in their hands. | Excellent for small datasets and nearly-sorted arrays. Very efficient when elements only need to move a small distance. Uses minimal extra space and works well for ongoing data streams. | Best case: O(n) when array is nearly sorted<br>Average/Worst case: O(n²) |
| Selection Sort | Repeatedly finds the minimum element from the unsorted portion and places it at the end of the sorted portion. Maintains two subarrays: sorted and unsorted. | Useful when memory writes are expensive, as it makes the minimum possible number of swaps (O(n)). Simple to implement and performs well on small arrays. | Best/Average/Worst case: O(n²)<br>Always makes same number of comparisons regardless of initial order |
| Bubble Sort | Repeatedly steps through the array, compares adjacent elements and swaps them if they're in the wrong order. The largest unsorted element "bubbles up" to its correct position in each pass. | Rarely used in practice due to poor performance, but valuable as a teaching tool for introducing sorting concepts. Simple to understand and implement. | Best case: O(n) when already sorted<br>Average/Worst case: O(n²) |
| Merge Sort | Divides array into two halves, recursively sorts them, then merges the sorted halves. Uses the "divide-and-conquer" strategy and guarantees stable sorting. | Excellent for sorting linked lists and when stable sorting is required. Predictable performance regardless of input data. Parallelizes well for large datasets. | Best/Average/Worst case: O(n log n)<br>Requires O(n) extra space |
| Quick Sort | Selects a 'pivot' element and partitions array around it, recursively sorting the sub-arrays. Effectiveness heavily depends on pivot selection strategy. | Usually the fastest in practice for random data. Widely used as the standard sorting algorithm in many language libraries. Uses minimal extra space for in-place implementation. | Best/Average case: O(n log n)<br>Worst case: O(n²) with poor pivot selection<br>In-place version possible |
| Radix Sort | Non-comparative integer sorting algorithm that sorts numbers digit by digit, from least to most significant. Uses counting sort as a subroutine for each digit. | Excellent for integers or strings of fixed length. Can be faster than comparison-based sorts for specific types of data. Particularly efficient when number of digits is small compared to number of elements. | Best/Average/Worst case: O(d(n + k)) where d is number of digits and k is the range of values for each digit<br>Requires O(n + k) extra space |

This table outlines the fundamental characteristics of each sorting algorithm, but there are some important additional considerations worth noting:

1. Space complexity often trades off against time complexity. For instance, Merge Sort's consistent O(n log n) performance comes at the cost of requiring additional memory.

2. Cache performance can significantly impact real-world efficiency. Selection Sort and Insertion Sort can sometimes outperform theoretically faster algorithms on very small arrays due to better cache utilization.

3. While Quick Sort has a worse theoretical worst-case than Merge Sort, it's often faster in practice due to better locality of reference and simpler operations, which is why it's commonly used as the default sorting algorithm in many programming language libraries.

4. The concept of "stability" (maintaining relative order of equal elements) can be crucial in some applications. Merge Sort is inherently stable, while Quick Sort typically isn't in its basic form.

5. The choice of sorting algorithm should be based on the specific requirements of the problem at hand, including the size of the dataset, the nature of the data, and the desired performance characteristics.

## Conclusion

* In this lecture, we explored fundamental sorting algorithms. We discussed their definitions, applications, and time complexities, and provided worked examples in C++.

* Understanding these algorithms and their characteristics is crucial for any computer science student or practitioner. 

* Building a strong foundation with these fundamental algorithms will prepare you to tackle more complex problems and make informed decisions when choosing the appropriate sorting technique for a given scenario.


## References

Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). Introduction to Algorithms (3rd ed.). MIT Press.
Sedgewick, R., & Wayne, K. (2011). Algorithms (4th ed.). Addison-Wesley Professional.
Knuth, D. E. (1998). The Art of Computer Programming, Volume 3: Sorting and Searching (2nd ed.). Addison-Wesley Professional.







