# Week 18 Lecture - Exception Handling in C++

---

## Learning Objectives

By the end of this lecture, students will be able to:

1. Understand the concept of exception handling in C++ and its importance
2. Implement basic exception handling using try, catch, and throw mechanisms
3. Work with standard exception classes in C++
4. Create custom exception classes by inheriting from std::exception
5. Apply advanced exception handling techniques using modern C++ features
6. Evaluate when to use exception handling versus other error-handling approaches

---

## Introduction

Exception handling is a critical aspect of robust software development. In any non-trivial application, things can go wrong during execution: files may not be found, network connections may fail, or invalid inputs might be provided. As professional developers, we need systematic ways to detect, signal, and handle these exceptional circumstances.

This lecture explores C++'s exception handling mechanisms, which provide a structured and extensible approach to managing errors. Unlike simple error codes or error flags, exceptions in C++ offer a powerful way to separate error-handling code from normal program logic, making programs more readable and maintainable.

---

## 1. Understanding Exception Handling in C++

### What is Exception Handling?

Exception handling is a programming language construct designed to handle runtime anomalies or exceptional conditions that disrupt the normal flow of program execution. These anomalies can range from arithmetic errors (like division by zero) to resource allocation failures.

### Motivation for Using Exception Handling

Traditional error handling approaches often suffer from several limitations:

| Traditional Error Handling | Problems |
|---------------------------|----------|
| Return error codes | Can be ignored easily; pollutes function interfaces |
| Global error flags | Creates hidden dependencies; difficult to handle errors at appropriate locations |
| If-else cascades | Mixes business logic with error handling; becomes unwieldy in complex code |

Exception handling provides several benefits:

* **Separation of concerns**: Normal code path remains clean, while error handling is separate
* **Propagation**: Errors can be handled at appropriate levels of the call stack
* **Type safety**: Different exception types can signal different error conditions
* **Resource management**: Combined with RAII, ensures proper cleanup even when errors occur
* **Hierarchical organization**: Exception class hierarchies allow for catching categories of exceptions

As Stroustrup, the creator of C++, notes: "Exception handling is for handling exceptional circumstances that can be detected only during run time" (Stroustrup, 2013, p.387).

---

## 2. The try, catch, and throw Mechanisms

C++ exception handling revolves around three keywords: `try`, `catch`, and `throw`.

### The `throw` Statement

The `throw` keyword is used to signal an exceptional condition. It can throw an object of any type, though it's common practice to throw objects derived from `std::exception`.

```cpp
if (denominator == 0) {
    throw std::runtime_error("Division by zero attempted");
}
```

### The `try` Block

A `try` block identifies a section of code in which exceptions might be thrown and need to be caught.

```cpp
try {
    // Code that might throw an exception
    int result = numerator / denominator;
}
```

### The `catch` Block

A `catch` block specifies how a particular type of exception should be handled.

```cpp
catch (const std::runtime_error& e) {
    // Handle runtime_error exceptions
    std::cerr << "Runtime error: " << e.what() << std::endl;
}
```

### Complete Example

```cpp
#include <iostream>
#include <stdexcept>

double divide(double numerator, double denominator) {
    if (denominator == 0) {
        throw std::runtime_error("Division by zero attempted");
    }
    return numerator / denominator;
}

int main() {
    try {
        double result = divide(10, 0);
        std::cout << "Result: " << result << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    
    std::cout << "Program continues after exception handling" << std::endl;
    return 0;
}
```

In this example, the division operation is encapsulated in a function that throws an exception when division by zero is attempted. The main function catches this exception and reports the error, allowing the program to continue execution.

---

## 3. Handling Multiple Exceptions

C++ allows catching different types of exceptions with multiple catch blocks.

```cpp
#include <iostream>
#include <stdexcept>
#include <string>
#include <cmath>

double computeValue(const std::string& operation, double value) {
    if (operation.empty()) {
        throw std::invalid_argument("Empty operation string");
    }
    
    if (operation == "sqrt") {
        if (value < 0) {
            throw std::domain_error("Cannot take square root of negative number");
        }
        return std::sqrt(value);
    }
    else if (operation == "log") {
        if (value <= 0) {
            throw std::domain_error("Cannot take logarithm of non-positive number");
        }
        return std::log(value);
    }
    
    throw std::runtime_error("Unknown operation: " + operation);
}

int main() {
    try {
        double result = computeValue("sqrt", -4.0);
        std::cout << "Result: " << result << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    }
    catch (const std::domain_error& e) {
        std::cerr << "Domain error: " << e.what() << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Runtime error: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Standard exception: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown exception caught" << std::endl;
    }
    
    return 0;
}
```

### Catch Block Order Matters

Catch blocks are evaluated in order. Since derived exceptions can be caught by base exception handlers, more specific exception types should be caught before more general ones.

```cpp
try {
    // code that might throw
}
catch (const std::domain_error& e) {
    // Handle domain_error
}
catch (const std::logic_error& e) {
    // Handle other logic_errors (except domain_error, which was already caught)
}
catch (const std::exception& e) {
    // Handle any other standard exceptions
}
catch (...) {
    // Handle any exception not caught above
}
```

### Catch-All Handler

The `catch(...)` syntax provides a way to catch any exception, regardless of type. This can be useful as a safety net, but should be used with caution as it provides no information about the exception caught.

---

## 4. Standard Exception Classes

The C++ Standard Library provides a hierarchy of exception classes derived from `std::exception`.

### The `std::exception` Base Class

`std::exception` is the base class for all standard exceptions. It provides the virtual `what()` member function which returns a C-style string describing the exception.

```cpp
#include <iostream>
#include <exception>

void someFunction() {
    throw std::exception();
}

int main() {
    try {
        someFunction();
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}
```

### Common Standard Exceptions

| Exception Class | Header | Description |
|----------------|--------|-------------|
| std::logic_error | \<stdexcept\> | Exceptions that could be detected at compile time |
| std::runtime_error | \<stdexcept\> | Exceptions that can only be detected at runtime |
| std::bad_alloc | \<new\> | Thrown by new when memory allocation fails |
| std::bad_cast | \<typeinfo\> | Thrown by dynamic_cast when it fails in a dynamic cast |
| std::bad_typeid | \<typeinfo\> | Thrown by typeid when it is applied to a null pointer |
| std::ios_base::failure | \<ios\> | Thrown by functions in the iostream library |

### Using `std::runtime_error`

`std::runtime_error` is particularly useful for exceptions that can only be detected during program execution:

```cpp
#include <iostream>
#include <stdexcept>
#include <fstream>

void readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + filename);
    }
    
    // Read from file...
}

int main() {
    try {
        readFromFile("nonexistent.txt");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Runtime error: " << e.what() << std::endl;
    }
    return 0;
}
```

---

## 5. Creating Custom Exceptions

While the standard exceptions cover many common scenarios, custom applications often benefit from domain-specific exception types.

### Deriving from `std::exception`

Best practice is to create custom exceptions by inheriting from `std::exception` or one of its derived classes:

```cpp
#include <iostream>
#include <exception>
#include <string>

class DatabaseException : public std::exception {
private:
    std::string message;

public:
    explicit DatabaseException(const std::string& msg) : message(msg) {}
    
    // Override what() to provide custom error message
    const char* what() const noexcept override {
        return message.c_str();
    }
};

void connectToDatabase(const std::string& connectionString) {
    if (connectionString.empty()) {
        throw DatabaseException("Empty connection string provided");
    }
    
    // Connection logic...
    throw DatabaseException("Failed to connect to database server");
}

int main() {
    try {
        connectToDatabase("server=localhost;user=root;");
    }
    catch (const DatabaseException& e) {
        std::cerr << "Database error: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Standard exception: " << e.what() << std::endl;
    }
    return 0;
}
```

### Explanation of Custom Exception Class

Let's break down the custom exception class:

```cpp
class DatabaseException : public std::exception {
private:
    std::string message;  // Store the error message

public:
    // Constructor takes a custom message
    explicit DatabaseException(const std::string& msg) : message(msg) {}
    
    // Override what() to return our custom message
    const char* what() const noexcept override {
        return message.c_str();  // Convert std::string to C-style string
    }
};
```

* `public std::exception`: Our class inherits from std::exception
* `message` member: Stores the custom error message
* `explicit` constructor: Prevents implicit conversions from string to DatabaseException
* `what() const noexcept override`: Overrides the virtual function from std::exception
  * `const`: Doesn't modify the exception object
  * `noexcept`: Guarantees no exceptions will be thrown from this function
  * Returns a C-style string with the error message

### Creating Exception Hierarchies

For complex applications, we can create hierarchies of exception classes:

```cpp
class DatabaseException : public std::exception {
    // Base implementation
};

class ConnectionException : public DatabaseException {
    // Connection-specific implementation
};

class QueryException : public DatabaseException {
    // Query-specific implementation
};
```

This approach allows catching exceptions at different levels of specificity:

```cpp
try {
    // Database operations
}
catch (const ConnectionException& e) {
    // Handle connection issues
}
catch (const QueryException& e) {
    // Handle query issues
}
catch (const DatabaseException& e) {
    // Handle any other database issues
}
```

---

## 6. Providing Additional Information with Exceptions

Custom exceptions can include additional context beyond just a message.

### Example with Extended Information

```cpp
#include <iostream>
#include <exception>
#include <string>
#include <sstream>

class FileException : public std::exception {
private:
    std::string filename;
    int errorCode;
    std::string message;

public:
    FileException(const std::string& file, int code, const std::string& msg)
        : filename(file), errorCode(code), message(msg) {
        // Build the full error message
        std::ostringstream oss;
        oss << "File error [" << errorCode << "] in " << filename 
            << ": " << message;
        fullMessage = oss.str();
    }
    
    const char* what() const noexcept override {
        return fullMessage.c_str();
    }
    
    // Additional accessors for specific information
    const std::string& getFilename() const { return filename; }
    int getErrorCode() const { return errorCode; }
    const std::string& getErrorMessage() const { return message; }

private:
    std::string fullMessage;
};

void processFile(const std::string& filename) {
    if (filename.empty()) {
        throw FileException("", 1001, "Empty filename provided");
    }
    
    // Simulate file opening error
    throw FileException(filename, 1002, "File not found");
}

int main() {
    try {
        processFile("data.txt");
    }
    catch (const FileException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        
        // Access specific error details
        std::cerr << "Details:" << std::endl
                  << "  File: " << e.getFilename() << std::endl
                  << "  Code: " << e.getErrorCode() << std::endl
                  << "  Message: " << e.getErrorMessage() << std::endl;
    }
    return 0;
}
```

This example demonstrates how a custom exception can:
1. Store multiple pieces of information about the error
2. Provide a comprehensive message through `what()`
3. Offer specific accessors for detailed error information

### DIY Exception with Detailed Explanation

Here's a comprehensive example of a custom exception class with line-by-line explanation:

```cpp
#include <iostream>
#include <exception>
#include <string>
#include <ctime>

class NetworkException : public std::exception {
private:
    int errorCode;            // Numeric error code
    std::string errorMessage; // Descriptive error message
    std::string timestamp;    // When the error occurred
    std::string fullMessage;  // Combined error information

public:
    // Constructor with error code and message
    NetworkException(int code, const std::string& message) 
        : errorCode(code), errorMessage(message) {
        
        // Generate timestamp
        time_t now = time(nullptr);
        char timeBuffer[80];
        strftime(timeBuffer, sizeof(timeBuffer), "%Y-%m-%d %H:%M:%S", 
                 localtime(&now));
        timestamp = timeBuffer;
        
        // Build the complete error message
        fullMessage = "[" + timestamp + "] Network error " + 
                      std::to_string(errorCode) + ": " + errorMessage;
    }
    
    // Override what() to return our custom message
    const char* what() const noexcept override {
        return fullMessage.c_str();
    }
    
    // Accessors for specific error information
    int getErrorCode() const {
        return errorCode;
    }
    
    const std::string& getErrorMessage() const {
        return errorMessage;
    }
    
    const std::string& getTimestamp() const {
        return timestamp;
    }
};

// Function that might throw our custom exception
void sendData(const std::string& server, const std::string& data) {
    if (server.empty()) {
        throw NetworkException(404, "Server address not specified");
    }
    
    if (data.empty()) {
        throw NetworkException(400, "Empty data payload");
    }
    
    // Simulate a connection timeout
    throw NetworkException(408, "Connection timeout to " + server);
}

int main() {
    try {
        sendData("api.example.com", "Hello, server!");
    }
    catch (const NetworkException& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
        
        // We can also access specific parts of the error
        std::cerr << "Error code: " << e.getErrorCode() << std::endl;
        std::cerr << "Error message: " << e.getErrorMessage() << std::endl;
        std::cerr << "Timestamp: " << e.getTimestamp() << std::endl;
        
        // Log or handle the error appropriately
        if (e.getErrorCode() == 408) {
            std::cerr << "Retrying connection..." << std::endl;
            // Retry logic here
        }
    }
    
    return 0;
}
```

### Line-by-Line Explanation:

1. `class NetworkException : public std::exception {`
   - Declares our custom exception class, inheriting from std::exception

2. `private: int errorCode; std::string errorMessage; std::string timestamp; std::string fullMessage;`
   - Declares private member variables to store error details

3. `NetworkException(int code, const std::string& message) : errorCode(code), errorMessage(message) {`
   - Constructor that initializes the error code and message using an initializer list

4. `time_t now = time(nullptr); char timeBuffer[80]; strftime(...);`
   - Creates a human-readable timestamp for when the exception was created

5. `fullMessage = "[" + timestamp + "] Network error " + std::to_string(errorCode) + ": " + errorMessage;`
   - Builds a comprehensive error message combining all the information

6. `const char* what() const noexcept override {`
   - Overrides the what() method from std::exception
   - `const` means it doesn't modify the object
   - `noexcept` promises it won't throw exceptions
   - Returns a C-style string (const char*)

7. `return fullMessage.c_str();`
   - Converts our std::string to the C-style string required by what()

8. `int getErrorCode() const { return errorCode; }`
   - Accessor method for the error code
   - `const` means it doesn't modify the object

9. Similar accessor methods for other private members

10. `void sendData(const std::string& server, const std::string& data) {`
    - A function that demonstrates throwing our custom exception

11. `throw NetworkException(404, "Server address not specified");`
    - Creates and throws a NetworkException with specific error details

12. `try { sendData("api.example.com", "Hello, server!"); }`
    - Attempts to call our function within a try block

13. `catch (const NetworkException& e) {`
    - Catches our specific exception type
    - `const` for efficiency (we don't need to modify the exception)
    - `&` to avoid copying the exception object

14. `std::cerr << "Caught exception: " << e.what() << std::endl;`
    - Outputs the full error message from what()

15. `std::cerr << "Error code: " << e.getErrorCode() << std::endl;`
    - Accesses specific error details using our accessor methods

16. `if (e.getErrorCode() == 408) {`
    - Demonstrates how specific error codes can trigger specific handling logic

This approach allows for:
1. Richer error information than a simple message
2. Type-based catch blocks that can identify error categories
3. Structured error data that can guide error handling strategies
4. Detailed logging for debugging and diagnostic purposes

---

## 7. Advanced Exception Handling Features

### The `noexcept` Specifier

C++11 introduced the `noexcept` specifier to indicate that a function will not throw exceptions.

```cpp
void safeFunction() noexcept {
    // This function promises not to throw
}
```

#### Benefits of `noexcept`:

1. **Performance optimization**: Compiler can optimize code knowing no exceptions will be thrown
2. **Documentation**: Clearly indicates function behavior regarding exceptions
3. **Correctness**: Runtime check ensures program terminates if the function does throw (instead of undefined behavior)

#### Example Usage:

```cpp
#include <iostream>
#include <vector>

// Function that won't throw exceptions
void processData(const std::vector<int>& data) noexcept {
    for (int value : data) {
        std::cout << "Processing: " << value << std::endl;
    }
}

// Function that may throw exceptions
void validateData(const std::vector<int>& data) {
    if (data.empty()) {
        throw std::invalid_argument("Empty data set provided");
    }
    
    for (int value : data) {
        if (value < 0) {
            throw std::domain_error("Negative values not allowed");
        }
    }
}

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5};
    
    try {
        validateData(data);  // May throw
        processData(data);   // Won't throw
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}
```

### `std::terminate`

`std::terminate` is a function called when:
1. An exception is thrown but not caught
2. A `noexcept` function throws an exception
3. A destructor throws during stack unwinding
4. `std::nested_exception::rethrow_nested` is called for an exception with no nested exception
5. `std::terminate()` is explicitly called

#### Example:

```cpp
#include <iostream>
#include <exception>

void functhatTerminates() noexcept {
    std::cout << "About to throw from a noexcept function..." << std::endl;
    throw std::runtime_error("This will call terminate()");
}

int main() {
    std::cout << "Calling function..." << std::endl;
    try {
        functhatTerminates();
    }
    catch (const std::exception& e) {
        // This won't catch the exception because std::terminate
        // is called before control reaches this catch block
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    
    std::cout << "This line will never be reached" << std::endl;
    return 0;
}
```

### `std::unexpected` and `std::set_unexpected` (Deprecated)

> **Note**: `std::unexpected` and `std::set_unexpected` were part of C++'s dynamic exception specification system, which has been deprecated in C++11 and removed in C++17. They were used with the now-deprecated `throw()` exception specification.

For historical context:

```cpp
// Pre-C++17 code (deprecated)
void oldStyleFunction() throw(std::runtime_error) {
    throw std::logic_error("This would have called unexpected()");
}

void unexpectedHandler() {
    std::cerr << "Unexpected exception thrown!" << std::endl;
    throw; // Re-throw the current exception
}

// In main:
std::set_unexpected(unexpectedHandler);
```

Modern C++ should use `noexcept` instead:

```cpp
void modernFunction() noexcept {
    // Implementation that won't throw
}
```

### Exception Propagation with `std::exception_ptr`, `std::current_exception` and `std::rethrow_exception`

These facilities allow capturing, storing, and rethrowing exceptions across contexts, such as between threads.

```cpp
#include <iostream>
#include <exception>
#include <string>
#include <thread>
#include <mutex>

std::exception_ptr globalExceptionPtr = nullptr;
std::mutex exceptionMutex;

void threadFunction() {
    try {
        // Simulate an error in the thread
        throw std::runtime_error("Error occurred in thread");
    }
    catch (...) {
        // Capture the current exception
        std::lock_guard<std::mutex> lock(exceptionMutex);
        globalExceptionPtr = std::current_exception();
    }
}

int main() {
    std::thread t(threadFunction);
    t.join();
    
    // Check if an exception was captured
    if (globalExceptionPtr) {
        try {
            // Rethrow the captured exception
            std::rethrow_exception(globalExceptionPtr);
        }
        catch (const std::exception& e) {
            std::cerr << "Caught exception from thread: " << e.what() << std::endl;
        }
    }
    
    return 0;
}
```

Key points:
1. `std::current_exception()` captures the currently handled exception
2. `std::exception_ptr` stores a reference to an exception object
3. `std::rethrow_exception()` rethrows a previously captured exception

### Nested Exceptions

`std::nested_exception` allows encapsulating one exception inside another, which is useful for preserving the original cause of an error when translating between exception types.

```cpp
#include <iostream>
#include <exception>
#include <stdexcept>

class ApplicationException : public std::runtime_error, public std::nested_exception {
public:
    explicit ApplicationException(const std::string& msg)
        : std::runtime_error(msg) {
        // std::nested_exception constructor captures the current exception
    }
};

void lowLevelFunction() {
    throw std::runtime_error("Low-level failure");
}

void midLevelFunction() {
    try {
        lowLevelFunction();
    }
    catch (...) {
        throw ApplicationException("Mid-level failure");
    }
}

void highLevelFunction() {
    try {
        midLevelFunction();
    }
    catch (const ApplicationException& e) {
        std::cerr << "High-level caught: " << e.what() << std::endl;
        
        try {
            // Rethrow the nested exception (if any)
            e.rethrow_nested();
        }
        catch (const std::exception& nested) {
            std::cerr << "Caused by: " << nested.what() << std::endl;
        }
    }
}

int main() {
    try {
        highLevelFunction();
    }
    catch (const std::exception& e) {
        std::cerr << "Main caught: " << e.what() << std::endl;
    }
    
    return 0;
}
```

Output:
```
High-level caught: Mid-level failure
Caused by: Low-level failure
```

This demonstrates how to create an exception chain that preserves the entire error context.

---

## 8. Best Practices for Exception Handling

### Do's and Don'ts

| Do | Don't |
|----|-------|
| Use exceptions for exceptional conditions | Use exceptions for normal control flow |
| Catch exceptions by const reference | Catch by value (avoid copying) |
| Keep the exception hierarchy simple | Create deep, complex exception hierarchies |
| Use RAII to ensure proper cleanup | Rely on catch blocks for resource management |
| Document the exceptions a function might throw | Throw undocumented exception types |
| Make exception objects lightweight | Include large data structures in exceptions |
| Include relevant context in exceptions | Throw generic exceptions with vague messages |

### When to Use Exceptions vs. Error Codes

| Exceptions | Error Codes |
|------------|-------------|
| For unexpected or exceptional cases | For expected or frequent error conditions |
| When error handling is far from error detection | When errors are handled locally |
| For constructor failures | For performance-critical code paths |
| When errors can't be ignored | When all errors must be explicitly checked |
| For system-level or unrecoverable errors | For predictable, recoverable errors |

### Exception Safety Guarantees

* **Basic guarantee**: If an exception occurs, no resources are leaked, and the program remains in a valid (though possibly different) state
* **Strong guarantee**: If an exception occurs, the operation has no effect (state is rolled back)
* **No-throw guarantee**: The operation will not throw exceptions (noexcept)

---

## 9. Performance Considerations

### Exception Overhead

Exceptions in C++ follow the "zero-cost exception handling" principle: there is no runtime overhead if no exceptions are thrown. However, when exceptions are thrown:

1. Construction of the exception object
2. Unwinding the stack (calling destructors)
3. Finding the appropriate catch handler
4. Exception table size in the executable

### Optimizing Exception Use

1. Use exceptions only for exceptional conditions, not normal control flow
2. Keep exception classes small
3. Use move semantics when throwing objects with dynamic resources
4. Use noexcept where appropriate to enable compiler optimizations
5. Consider error codes for performance-critical paths with expected failures

As Sutter and Alexandrescu note in their book "C++ Coding Standards": "Prefer to use exceptions to report errors. Use status codes when exceptions cannot be used or when they would provide no advantage." (Sutter and Alexandrescu, 2004, p.87).

---

## 10. Exception Handling in Modern C++

### C++11 Enhancements

* Introduction of noexcept
* std::exception_ptr and related functions
* std::nested_exception

### C++17 Changes

* Removal of dynamic exception specifications (throw())
* noexcept becomes part of the function type

### C++20 Additions

* std::source_location for capturing source information in exceptions
* Coroutines with special exception handling considerations

---

## Conclusion

Exception handling is a powerful mechanism in C++ that allows for structured error management. When used appropriately, exceptions lead to more robust, maintainable code by:

1. Separating error handling from normal program logic
2. Ensuring errors cannot be silently ignored
3. Providing a structured way to propagate errors up the call stack
4. Working seamlessly with RAII for resource management

The key to effective exception handling is judicious use. Not every error condition warrants an exception, but for truly exceptional circumstances that disrupt normal program flow, C++'s exception mechanisms provide the tools needed to handle errors gracefully.

As we've seen in this lecture, C++ offers a comprehensive set of exception handling features from basic try-catch-throw mechanisms to advanced tools like std::nested_exception and std::exception_ptr. Mastering these tools will significantly improve your ability to write robust, error-resistant C++ applications.

---

## References

Alexandrescu, A. and Sutter, H. (2004) *C++ Coding Standards: 101 Rules, Guidelines, and Best Practices*. Boston: Addison-Wesley Professional.

ISO/IEC (2017) *International Standard ISO/IEC 14882:2017(E) – Programming Language C++*. Geneva: International Organization for Standardization.

Josuttis, N.M. (2012) *The C++ Standard Library: A Tutorial and Reference*. 2nd ed. Boston: Addison-Wesley Professional.

Meyers, S. (2014) *Effective Modern C++: 42 Specific Ways to Improve Your Use of C++11 and C++14*. Sebastopol: O'Reilly Media.

Stroustrup, B. (2013) *The C++ Programming Language*. 4th ed. Boston: Addison-Wesley Professional.

---

## Exercises

1. Implement a simple calculator program that uses exception handling to deal with invalid inputs (division by zero, invalid operations).

2. Create a custom exception hierarchy for a bank account simulation with specific exceptions for InsufficientFunds, AccountLocked, and InvalidTransaction.

3. Modify an existing program to use std::exception_ptr to propagate exceptions between threads.

4. Implement a function template that provides strong exception safety guarantees using the "copy-and-swap" idiom.

5. Analyze a piece of code for exception safety issues and propose improvements.