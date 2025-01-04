# Week 11 - Heap Data Structures


## Learning Objectives

By the end of this lecture, students will be able to:

1. Understand the concept of heap data structures and their properties
2. Implement and manipulate binary heaps using array representation
3. Analyze the time complexity of heap operations
4. Apply heap operations in practical programming scenarios
5. Utilize STL heap implementations effectively
6. Implement heapsort and understand its advantages
7. Design and implement priority queues using heaps

## Introduction

In today's lecture, we'll explore heap data structures, which are specialized tree-based structures that satisfy the heap property. Heaps are fundamental to many important algorithms and applications, including priority queues, scheduling algorithms, and graph algorithms like Dijkstra's shortest path.

## 1. Heaps

A heap is a specialized tree-based data structure that satisfies the heap property. Think of it as a binary tree with additional constraints that make it efficient for certain operations.

Key characteristics:
- Complete binary tree structure
- Specialized ordering between parent and child nodes
- Efficient for finding minimum or maximum elements
- Can be efficiently implemented using arrays

### Use Cases
- Priority queues
- Scheduling algorithms
- Graph algorithms
- Memory management systems

## 2. Binary Heaps

A binary heap is a complete binary tree where each node satisfies the heap property.

There are two types of heap properties:

1. **Max-Heap Property:**
   - Each parent node is greater than or equal to its children
   - The root contains the maximum element

2. **Min-Heap Property:**
   - Each parent node is less than or equal to its children
   - The root contains the minimum element

Expressed mathematically:

```
For a max heap:
A[PARENT(i)] ≥ A[i] 

For a min heap:  
A[PARENT(i)] ≤ A[i]
```

Where `PARENT(i) = ⌊i/2⌋`
    
The heap property guarantees that the root element will be the minimum or maximum.

The choice between a min or max heap depends on the specific application.


Figure 1: Min Heap Example
![img1](/img/img1.png)

Binary heaps are the most common type of heap. In a binary heap, each node has at most two children. Typical binary heap operations include:

* `find-min` or `find-max`: Find the minimum or maximum element in O(1) time  
* `insert`: Add a new key to the heap in O(log n) time
* `extract-min/max`: Remove and return the minimum/maximum element in O(log n) time
* `heapify`: Construct a heap from an array of elements in O(n) time


### Visual Representation

```
Max Heap Example:                Min Heap Example:
       100                            3
      /   \                         /   \
    19     36                     7     6
   /  \   /  \                  / \   / \
  17  3  25  1                8   9  10  12
```

## 3. Heap Insertion

When inserting a new element into a heap, we follow these steps:

1. Add the element at the bottom-rightmost position
2. Perform percolate up (bubble up) operation

Stated slightly differently:

1. Append new element to bottom level of heap
2. Compare added element with its parent; if they are in correct order, stop
3. If not, swap elements and go to step 2

Figure 2: Heap Insertion Example
![img2](/img/img2.png)

Example code:

```cpp
void MinHeap::insert(int val) {
    heap.push_back(val);
    int idx = size() - 1;
    
    while (idx > 0 && heap[parent(idx)] > heap[idx]) {
        swap(heap[parent(idx)], heap[idx]);
        idx = parent(idx);
    }
}
```

Time Complexity: O(log n)

### Percolate Up version

The process of moving a newly inserted element up the heap until it satisfies the heap property.

```cpp
template<typename T>
class MaxHeap {
private:
    std::vector<T> heap;
    
    void percolateUp(int index) {
        T temp = heap[index];
        while (index > 0 && temp > heap[(index - 1) / 2]) {
            heap[index] = heap[(index - 1) / 2];
            index = (index - 1) / 2;
        }
        heap[index] = temp;
    }

public:
    void insert(const T& element) {
        heap.push_back(element);
        percolateUp(heap.size() - 1);
    }
};
```

Time Complexity: O(log n)

## 4. Extracting Minimum/Maximum

The process involves:
1. Remove root element (min/max)
2. Move last element to root
3. Percolate down to maintain heap property

Figure 3: Heap Extraction Example
![img3](/img/img3.png)

```cpp
template<typename T>
T MaxHeap<T>::extractMax() {
    if (heap.empty()) {
        throw std::runtime_error("Heap is empty");
    }
    
    T maxElement = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    
    if (!heap.empty()) {
        percolateDown(0);
    }
    
    return maxElement;
}

private:
void percolateDown(int index) {
    int maxIndex = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    
    if (leftChild < heap.size() && heap[leftChild] > heap[maxIndex]) {
        maxIndex = leftChild;
    }
    
    if (rightChild < heap.size() && heap[rightChild] > heap[maxIndex]) {
        maxIndex = rightChild;
    }
    
    if (maxIndex != index) {
        std::swap(heap[index], heap[maxIndex]);
        percolateDown(maxIndex);
    }
}
```

Extraction has O(log n) time complexity due to the downward traversal to restore heap property.

## 5. Array Implementation

Heaps are typically implemented using arrays, which provides cache efficiency and eliminates the need for storing pointers.

For a heap element at index `i`:
- Its left child is at index `2i + 1`  
- Its right child is at index `2i + 2`
- Its parent is at index `floor((i-1) / 2)`

Figure 4: Array Representation of a Heap
![img4](/img/img4.png)

Some benefits of array implementation:

- Access to any node using index calculations 
- Memory efficient (no need to store pointers)  
- Easier to implement than binary trees

Here's how a basic heap struct could look in C++:

```cpp
struct MinHeap {
    vector<int> heap;
    
    int parent(int i) { return (i-1) / 2; }
    int leftChild(int i) { return 2*i + 1; }
    int rightChild(int i) { return 2*i + 2; }
    
    int size() { return heap.size(); }
    bool isEmpty() { return heap.empty(); }
    int getMin() { return heap[0]; }
    
    void insert(int val);
    int extractMin();
};
```

Her is a simplified example of a MinHeap class implementation:

```cpp
template<typename T>
class MinHeap {
private:
    std::vector<T> array;
    
public:
    MinHeap() = default;
    
    void insert(const T& value) {
        array.push_back(value);
        percolateUp(array.size() - 1);
    }
    
    bool isEmpty() const {
        return array.empty();
    }
    
    size_t size() const {
        return array.size();
    }
};
```

## 6. STL Implementation

The C++ standard library provides several heap-related functions in the `<algorithm>` header:

- `make_heap(first, last, comp)`: Constructs a heap in the range [first,last) with comparison function comp
- `push_heap(first, last, comp)`: Inserts an element at position last-1 into the heap [first,last) with comp  
- `pop_heap(first, last, comp)`: Swaps the value in first position with the value in last-1 position and makes [first,last-1) into a heap with comp
- `sort_heap(first, last, comp)`: Converts the heap [first,last) into a sorted range with comp

Using `vector` and these STL functions, a heap can be easily constructed and manipulated:

```cpp
vector<int> v {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
  
make_heap(v.begin(), v.end());
  
cout << "Heap: ";
for (auto i : v) cout << i << " ";
cout << endl;
  
v.push_back(25);
push_heap(v.begin(), v.end());
  
cout << "Heap after push: ";  
for (auto i : v) cout << i << " ";
cout << endl;
  
pop_heap(v.begin(), v.end());
int largest = v.back();
v.pop_back();
cout << "Largest element: " << largest << endl;
  
sort_heap(v.begin(), v.end());
  
cout << "Sorted heap: ";
for (auto i : v) cout << i << " ";
cout << endl;
```

Output:
```
Heap: 16 14 10 8 7 9 3 2 4 1 
Heap after push: 25 16 10 14 7 9 3 2 4 1 8 
Largest element: 25
Sorted heap: 1 2 3 4 7 8 9 10 14 16
```

The STL heap functions use max-heap by default. To make them construct min-heap, use `greater<int>()` as the comparison function.

## 7. Heap Sort

Heapsort is a comparison-based sorting technique that uses a binary heap to sort elements. It has three steps:

1. Build a max heap from the input array
2. Repeatedly extract max element from heap and place at end of array
3. After all elements extracted, array is sorted in ascending order

`heapsort` is typically an in-place sorting algorithm with no additional memory requirements.

Implementation sketch:

```cpp
template <typename T>
void heapsort(vector<T>& arr) {
    int n = arr.size();
    
    // Build max heap
    for (int i = n/2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    // Extract elements one by one
    for (int i = n-1; i > 0; i--) { 
        swap(arr[0], arr[i]); 
  
        // Rebuild heap
        heapify(arr, i, 0); 
    } 
}

template <typename T>
void heapify(vector<T>& arr, int n, int root) {
    int largest = root;
    int left = 2*root + 1;
    int right = 2*root + 2;
  
    if (left < n && arr[left] > arr[largest]) 
        largest = left; 
  
    if (right < n && arr[right] > arr[largest]) 
        largest = right; 
  
    if (largest != root) { 
        swap(arr[root], arr[largest]); 
  
        heapify(arr, n, largest); 
    } 
}
```

Heapsort has an overall time complexity of O(n log n) and space complexity of O(1) - making it efficient and practical for sorting large datasets.

## 8. Priority Queue

A priority queue is an abstract data type that operates similar to a regular queue but with priorities attached to elements.

Priority queues retrieve elements in order of priority. They support two main operations:

- `insert(key, value)`: Add element with key and value
- `extract-min/max()`: Remove and return element with minimum/maximum key value

```cpp
#include <queue>

// Max priority queue
std::priority_queue<int> maxPQ;

// Min priority queue
std::priority_queue<int, std::vector<int>, std::greater<int>> minPQ;

// Custom comparator
struct Compare {
    bool operator()(const Task& a, const Task& b) {
        return a.priority < b.priority;
    }
};
std::priority_queue<Task, std::vector<Task>, Compare> taskQueue;
```


### Priority Queues with Heaps

Binary heaps are a natural and efficient underlying data structure for priority queues as both have O(log n) insertion and extraction.

In C++, the `priority_queue` class is a heap-implemented container adapter that provides constant time lookup of max element and logarithmic time insertion and extraction.

Example:

```cpp
priority_queue<int> pq; 
  
pq.push(10); 
pq.push(20); 
pq.push(5); 
pq.push(30);
  
cout << "Elements in priority queue: ";
while(!pq.empty()) {
    cout << pq.top() << " ";
    pq.pop();
}
```

Output:
```
Elements in priority queue: 30 20 10 5
```

`priority_queue` uses max heap by default. For min heap behavior, use `priority_queue<int, vector<int>, greater<int>>`.


## Summary Table

| Operation | Description | Time Complexity |
|-----------|-------------|-----------------|
| Insert | Add element to heap | O(log n) |
| Extract Min/Max | Remove and return root | O(log n) |
| Peek Min/Max | View root without removal | O(1) |
| Build Heap | Create heap from array | O(n) |
| Heapify | Maintain heap property | O(log n) |
| Heap Sort | Sort using heap | O(n log n) |

In terms of strengths, heaps provide excellent performance for accessing min/max, inserting, and extracting elements. They are especially well-suited for algorithms needing repeated minimum or maximum selections. 

The main weakness of heaps is that they do not offer efficient search or traversal for non-min/max elements, which takes O(n) linear time. For those use cases, binary search trees may be more appropriate.

## Complete Working Example

Here's a template implementation of heapsort with custom comparator:

```cpp
#include <iostream>
#include <vector>
#include <functional>

template<typename T, typename Compare = std::less<T>>
class Heap {
private:
    std::vector<T> data;
    Compare comp;

    void heapifyDown(size_t index) {
        size_t size = data.size();
        size_t largest = index;
        size_t left = 2 * index + 1;
        size_t right = 2 * index + 2;

        if (left < size && comp(data[largest], data[left]))
            largest = left;

        if (right < size && comp(data[largest], data[right]))
            largest = right;

        if (largest != index) {
            std::swap(data[index], data[largest]);
            heapifyDown(largest);
        }
    }

    void heapifyUp(size_t index) {
        while (index > 0) {
            size_t parent = (index - 1) / 2;
            if (comp(data[parent], data[index])) {
                std::swap(data[parent], data[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

public:
    void push(const T& value) {
        data.push_back(value);
        heapifyUp(data.size() - 1);
    }

    T pop() {
        if (data.empty()) throw std::runtime_error("Heap is empty");
        
        T result = data[0];
        data[0] = data.back();
        data.pop_back();
        
        if (!data.empty()) {
            heapifyDown(0);
        }
        
        return result;
    }

    const T& top() const {
        if (data.empty()) throw std::runtime_error("Heap is empty");
        return data[0];
    }

    bool empty() const { return data.empty(); }
    size_t size() const { return data.size(); }
};

// Usage example
int main() {
    Heap<int, std::greater<int>> minHeap; // Min heap
    std::vector<int> numbers = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    
    // Insert numbers
    for (int num : numbers) {
        minHeap.push(num);
    }
    
    // Extract in sorted order
    std::cout << "Sorted numbers: ";
    while (!minHeap.empty()) {
        std::cout << minHeap.pop() << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
```

## Security Considerations

When implementing heaps, consider these security aspects:

1. Buffer Overflow Protection
   - Validate array indices
   - Check for integer overflow in index calculations

2. Memory Management
   - Properly handle memory allocation/deallocation
   - Consider using smart pointers in modern C++

3. Exception Safety
   - Implement strong exception guarantees
   - Handle memory allocation failures

Always analyze your heap implementation through a security lens and apply secure coding practices relevant to the application context.

## Conclusion

Heaps are versatile data structures that provide efficient solutions for many programming problems. They are especially useful in scenarios requiring quick access to minimum or maximum elements. Understanding heap operations and their implementation is crucial for developing efficient algorithms and systems.

## References

1. Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). Introduction to Algorithms (3rd ed.). MIT Press.
2. Sedgewick, R., & Wayne, K. (2011). Algorithms (4th ed.). Addison-Wesley Professional.
3. Stroustrup, B. (2013). The C++ Programming Language (4th ed.). Addison-Wesley Professional.
4. ISO/IEC. (2017). ISO International Standard ISO/IEC 14882:2017(E) – Programming Language C++. Geneva, Switzerland: International Organization for Standardization (ISO).
5. Introduction to Algorithms, 3rd Edition by Cormen, Leiserson, Rivest, Stein 
6. The Algorithm Design Manual by Steven S. Skiena
7. Wikipedia articles on Binary Heap and Heapsort
8. C++ Reference on std::priority_queue: https://en.cppreference.com/w/cpp/container/priority_queue  
9. Morgan, M. (2024). Lecture 11 Heaps [PowerPoint slides].Retrieved from [URL](https://moodle.chester.ac.uk/course/view.php?id=7314)