# Week 8

## Lecture Session: Stacks and Queues in C++

## Introduction

Today, we will explore two fundamental data structures that are crucial for problem-solving and algorithm development.

* By the end of this session, you will be equipped with the knowledge to implement these data structures both manually and using the Standard Template Library (STL).
* We will cover their uses, functionalities, and security implications, and demonstrate their implementation through C++ code examples.

## 1. Stacks and Queues

Stacks and Queues are abstract data types that operate on a collection of elements.

* They are integral in managing data in a particular order and are widely used in various applications, including algorithms, memory management, and task scheduling.

### Similarities

- Both are linear data structures.
- Both allow insertion and deletion of elements.

### Differences

- **Stack:** Follows Last In, First Out (LIFO) principle.
- **Queue:** Follows First In, First Out (FIFO) principle.

## 2. Stacks

A Stack is a collection where elements are added and removed from the same end, known as the "top" of the stack.

### Main Concepts

- **Push:** Add an element to the top.
- **Pop:** Remove the top element.
- **Peek:** View the top element without removing it.

### Functionality

Stacks are used for tasks like reversing a string, parsing expressions in compilers, and handling function calls in recursion.

### Example Code

```cpp
#include <iostream>
#include <stack>

int main() {
    std::stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    std::cout << "Top element: " << myStack.top() << std::endl;
    myStack.pop();
    std::cout << "Top element after pop: " << myStack.top() << std::endl;

    return 0;
}
```

### Security Implications

Stacks, when not managed properly, can lead to stack overflow, a common security risk in programming.

## 3. STL Stack

The C++ Standard Template Library (STL) provides a `stack` class that simplifies stack operations.

## 4. Queues

A Queue is a collection where elements are added at one end, known as the "rear," and removed from the other end, known as the "front."

### Main Concepts

- **Enqueue:** Add an element to the rear.
- **Dequeue:** Remove the front element.
- **Front:** View the front element without removing it.

### Functionality

Queues are used in scenarios like task scheduling, managing processes in an operating system, and breadth-first search in graphs.

```cpp
#include <iostream>
#include <queue>

int main() {
    std::queue<int> myQueue;
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    std::cout << "Front element: " << myQueue.front() << std::endl;
    myQueue.pop();
    std::cout << "Front element after pop: " << myQueue.front() << std::endl;

    return 0;
}
```

### Security Implications

Proper management is necessary to avoid memory leaks and ensure efficient element handling.

## 5. The empty() method

The `empty()` method checks if the stack or queue is empty.

```cpp
if(myStack.empty()) {
    std::cout << "Stack is empty" << std::endl;
}

if(myQueue.empty()) {
    std::cout << "Queue is empty" << std::endl;
}
```

## 6. Stack Functions in STL

- `push()`: Adds an element to the stack.
- `pop()`: Removes the top element from the stack.
- `top()`: Returns the top element of the stack.
- `empty()`: Checks if the stack is empty.
- `size()`: Returns the number of elements in the stack.

## Summary Table: Stacks and Queues

| Feature     | Stacks                     | Queues                     |
|-------------|----------------------------|----------------------------|
| Order       | LIFO                       | FIFO                       |
| Main Methods| push(), pop(), top()       | push(), pop(), front()     |
| Use Cases   | Function calls, expression parsing | Task scheduling, process management |
| Security    | Risk of overflow           | Risk of memory leaks       |

## Conclusion

Understanding Stacks and Queues is fundamental for efficient data management and algorithm design. Their principles of LIFO and FIFO provide versatile solutions for numerous computational problems. With this knowledge, you're now equipped to implement these structures both manually and using the STL, ensuring robust and secure coding practices in your future projects.

Remember, Stacks and Queues are just the beginning. Mastering these will pave the way for more complex data structures and algorithms, enhancing your problem-solving toolkit. Happy coding!
