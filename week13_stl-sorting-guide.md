# Week 13 - Understanding STL Sorting Library and Implementing Quicksort

## Introduction to STL Sorting Library

The Standard Template Library (STL) in C++ provides a powerful and flexible sorting framework through its `algorithm` header. The primary motivation behind using the STL sorting library is to provide programmers with efficient, well-tested, and generic sorting implementations that work with any container type and any data type that supports comparison operations.

### Key Benefits of STL Sorting

The STL sorting library offers several advantages that make it an essential tool for C++ developers:

1. Generic Programming: The sorting algorithms work with any container that provides random access iterators
2. Optimization: The implementation automatically chooses the most efficient sorting algorithm based on the data size and type
3. Type Safety: Template-based implementation ensures compile-time type checking
4. Customization: Supports custom comparison functions for complex sorting requirements

## Core Sorting Functions

The STL provides several key sorting functions:

### std::sort
The primary sorting function that implements an introsort algorithm - a hybrid of quicksort, heapsort, and insertion sort. It automatically chooses the most efficient approach based on the data characteristics.

```cpp
std::sort(begin_iterator, end_iterator);
std::sort(begin_iterator, end_iterator, comparison_function);
```

### std::stable_sort
Maintains the relative order of equal elements, implementing a modified merge sort algorithm.

```cpp
std::stable_sort(begin_iterator, end_iterator);
std::stable_sort(begin_iterator, end_iterator, comparison_function);
```

### std::partial_sort
Sorts only a portion of the container, useful when you only need the first N elements sorted.

```cpp
std::partial_sort(begin_iterator, middle_iterator, end_iterator);
```

## Implementing Quicksort Using STL

Let's implement a quicksort algorithm that leverages STL components. We'll break this down into steps:

1. First, we'll create a template-based implementation
2. Use STL algorithms for partitioning
3. Implement both iterative and recursive versions

### Template-Based Quicksort Implementation

```cpp
#include <algorithm>
#include <vector>
#include <iterator>
#include <functional>

template<typename RandomIt, typename Compare = std::less<>>
void quicksort(RandomIt first, RandomIt last, Compare comp = Compare{}) {
    // Base case: if range is less than 2 elements, return
    if (std::distance(first, last) < 2) return;
    
    // Choose pivot (using median-of-three)
    auto pivot_it = first + std::distance(first, last)/2;
    
    // Partition the range
    auto partition_point = std::partition(first, last,
        [=](const auto& elem) { return comp(elem, *pivot_it); });
    
    // Recursively sort both partitions
    quicksort(first, partition_point, comp);
    quicksort(partition_point, last, comp);
}
```

### Detailed Example Usage

Here's a complete example showing how to use our quicksort implementation with different data types and comparison functions:

```cpp
#include <iostream>
#include <vector>
#include <string>

// Custom structure for demonstration
struct Person {
    std::string name;
    int age;
    
    // Constructor
    Person(std::string n, int a) : name(std::move(n)), age(a) {}
};

int main() {
    // Example 1: Sorting integers
    std::vector<int> numbers = {64, 34, 25, 12, 22, 11, 90};
    quicksort(numbers.begin(), numbers.end());
    
    std::cout << "Sorted numbers:\n";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n\n";
    
    // Example 2: Sorting strings
    std::vector<std::string> words = {"banana", "apple", "cherry", "date"};
    quicksort(words.begin(), words.end());
    
    std::cout << "Sorted words:\n";
    for (const auto& word : words) {
        std::cout << word << " ";
    }
    std::cout << "\n\n";
    
    // Example 3: Sorting custom objects
    std::vector<Person> people = {
        {"Alice", 30},
        {"Bob", 25},
        {"Charlie", 35},
        {"David", 28}
    };
    
    // Sort by age
    quicksort(people.begin(), people.end(),
        [](const Person& a, const Person& b) { return a.age < b.age; });
    
    std::cout << "People sorted by age:\n";
    for (const auto& person : people) {
        std::cout << person.name << ": " << person.age << "\n";
    }
    
    return 0;
}
```

## Performance Considerations

When implementing quicksort using STL components, several factors affect performance:

1. Pivot Selection: The median-of-three method helps avoid worst-case scenarios
2. Partition Strategy: STL's partition algorithm is highly optimized
3. Memory Usage: Our implementation is in-place, using O(log n) stack space
4. Iterator Type: Random access iterators provide the best performance

### Time Complexity Analysis

- Average Case: O(n log n)
- Worst Case: O(n²) (rare with good pivot selection)
- Best Case: O(n log n)
- Space Complexity: O(log n)

## Best Practices and Tips

When using STL sorting components or implementing custom sorting algorithms:

1. Consider using std::sort for general-purpose sorting unless you have specific requirements that necessitate a custom implementation

2. Use std::stable_sort when maintaining relative order of equal elements is important

3. Profile your specific use case to determine if a custom implementation provides meaningful benefits

4. For small datasets (n < 10), simpler algorithms like insertion sort might perform better

5. Always validate your sorting implementation with edge cases:
   - Empty containers
   - Single-element containers
   - Already sorted data
   - Reverse sorted data
   - Data with many duplicates

## Conclusion

The STL sorting library provides robust, efficient, and flexible sorting capabilities that are suitable for most applications. While understanding and implementing quicksort manually is valuable for learning and specific optimizations, the STL implementation should be your go-to choice for production code unless you have very specific requirements that justify a custom implementation.

Remember that the STL sorting algorithms are:
- Extensively tested
- Optimized for different hardware architectures
- Maintained and updated with each C++ standard
- Designed to work seamlessly with other STL components

This makes them an excellent choice for most sorting needs in C++ applications.
