# Week 7

## Lecture Session - C++ Templates: Genericity and Code Reusability

## Introduction

Templates are a powerful feature in C++ that enable generic programming, allowing developers to write flexible, reusable code that works with multiple data types without sacrificing performance or type safety. In this lecture, we'll explore the world of C++ templates, understanding their fundamental concepts, implementation strategies, and best practices.

### Learning Objectives
By the end of this lecture, you will be able to:
- Understand the motivation behind templates
- Implement template functions and template classes
- Differentiate between template and non-template approaches
- Recognize when and how to use templates effectively

## 1. Templates vs. No Templates: A Comparative Overview

### The Problem of Type Specificity

Consider a scenario where you need to write functions or classes that can work with multiple data types:

**Without Templates (Traditional Approach):**
```cpp
int findMax(int a, int b) {
    return (a > b) ? a : b;
}

double findMax(double a, double b) {
    return (a > b) ? a : b;
}
```

**Drawbacks of the Non-Template Approach:**
- Code duplication
- Maintenance overhead
- Limited flexibility
- Increased potential for errors

**With Templates:**
```cpp
template <typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}
```

**Advantages of Templates:**
- Single implementation for multiple types
- Type-safe generic programming
- Compile-time type checking
- Zero runtime overhead
- Improved code maintainability

## 2. Template Function Overloading

### Concept of Function Template Overloading
Function templates can be overloaded based on different parameter types or number of parameters:

```cpp
// Generic template function
template <typename T>
T add(T a, T b) {
    return a + b;
}

// Specialized overload for different number of parameters
template <typename T>
T add(T a, T b, T c) {
    return a + b + c;
}

// Explicit specialization for specific type
template <>
const char* add(const char* a, const char* b) {
    // Custom string concatenation logic
    // Detailed implementation would go here
    return nullptr; // Placeholder
}
```

**Key Characteristics:**
- Compiler selects the most appropriate template function
- Allows fine-grained control over type-specific behaviors
- Enables optimization and type-specific implementations

## 3. Template Functions: Deep Dive

### Implementation Strategies
1. **Function Template Basics:**
```cpp
template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}
```


2. **Multiple Type Parameters:**
```cpp
template <typename T1, typename T2>
void printPair(T1 first, T2 second) {
    std::cout << first << ", " << second << std::endl;
}
```

### Security Implications
- Compile-time type checking prevents runtime type errors
- Template instantiation occurs at compile-time
- No additional runtime overhead compared to manually written type-specific functions
- Potential risk of code bloat with excessive template instantiations

**Key Considerations:**
- Type safety
- Performance optimization
- Code reusability
- Compile-time error detection

## 4. Template Classes: Dynamic Array Implementation

### Non-Template Dynamic Array (Traditional Approach)
```cpp
class IntArray {
private:
    int* data;
    size_t size;
    size_t capacity;

public:
    IntArray() : data(nullptr), size(0), capacity(0) {}
    
    void push_back(int value) {
        if (size == capacity) {
            // Resize logic for int-specific array
            capacity = capacity == 0 ? 1 : capacity * 2;
            int* newData = new int[capacity];
            
            // Copy existing elements
            for (size_t i = 0; i < size; ++i) {
                newData[i] = data[i];
            }
            
            delete[] data;
            data = newData;
        }
        data[size++] = value;
    }
    
    ~IntArray() {
        delete[] data;
    }
};
```

### Template Class Implementation
```cpp
template <typename T>
class DynamicArray {
private:
    T* data;
    size_t size;
    size_t capacity;

public:
    DynamicArray() : data(nullptr), size(0), capacity(0) {}
    
    void push_back(const T& value) {
        if (size == capacity) {
            // Generic resize logic
            capacity = capacity == 0 ? 1 : capacity * 2;
            T* newData = new T[capacity];
            
            // Copy existing elements
            for (size_t i = 0; i < size; ++i) {
                newData[i] = data[i];
            }
            
            delete[] data;
            data = newData;
        }
        data[size++] = value;
    }
    
    T& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }
    
    ~DynamicArray() {
        delete[] data;
    }
};
```

### Example Usage of Template Dynamic Array
```cpp
int main() {
    // Integer dynamic array
    DynamicArray<int> intArray;
    intArray.push_back(10);
    intArray.push_back(20);
    
    // String dynamic array
    DynamicArray<std::string> stringArray;
    stringArray.push_back("Hello");
    stringArray.push_back("World");
    
    return 0;
}
```

## Comparative Analysis: Template Functions vs. Template Classes

| Aspect | Template Functions | Template Classes | Security Considerations |
|--------|-------------------|-----------------|------------------------|
| **Definition** | Generic functions that can work with multiple types | Generic class blueprints for creating type-safe containers/data structures | Compile-time type checking reduces runtime errors |
| **Type Handling** | Instantiated for each unique type combination | Generates a new class for each type used | Potential code bloat with many instantiations |
| **Flexibility** | Operate on parameters of different types | Can encapsulate complex data structures and behaviors | Strong type safety |
| **Performance** | Zero runtime overhead | Minimal performance penalty | Inline expansion and compile-time optimization |
| **Use Cases** | Utility functions, algorithms | Containers, data structures | Careful memory management required |
| **Potential Risks** | Increased binary size | Potential for complex template metaprogramming | Memory leaks if not properly managed |

## Conclusion

Templates represent a powerful paradigm in C++ that enables generic, type-safe, and efficient programming. By understanding their implementation and nuances, you can write more flexible and maintainable code.

### Key Takeaways
- Templates provide compile-time polymorphism
- They eliminate code duplication
- Offer type safety without runtime overhead
- Enable powerful generic programming techniques

### Recommended Next Steps
- Practice implementing template functions and classes
- Explore advanced template metaprogramming techniques
- Understand template specialization
- Learn about concepts and constraints in modern C++

### Further Reading
- "Modern C++ Design" by Andrei Alexandrescu
- C++ Reference Documentation on Templates
- ISO C++ Standard Documentation

---

## Coding Exercise Suggestions
1. Implement a template-based Stack class
2. Create a template function for binary search
3. Develop a template-based Matrix class
4. Experiment with template function overloading

## Quiz Preparation
- Understand the compilation process of templates
- Identify scenarios where templates are most beneficial
- Compare template and non-template implementations
