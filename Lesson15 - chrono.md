# Week 15 - C++ Chrono Library

### Learning Objectives

By the end of this lecture, students will be able to:

1. Understand and implement time management using std::chrono and <ctime>
2. Compare different clock types and their use cases
3. Work with duration and time points effectively
4. Implement time-based operations using both std::chrono and boost::chrono
5. Choose appropriate duration types for different scenarios

## Introduction

Time management is a crucial aspect of modern C++ programming. Whether you're creating real-time applications, measuring performance, or implementing timeouts, understanding how to work with time is essential. Today, we'll explore the modern C++ timing facilities through std::chrono and compare it with traditional approaches.

## 1. std::chrono Explained

The chrono library provides a flexible and type-safe way to work with time in C++. Let's look at a practical example of pausing program execution:

```cpp
#include <iostream>
#include <chrono>
#include <thread>

int main() {
    std::cout << "Program starting..." << std::endl;
    
    // Pause for 2 seconds
    std::this_thread::sleep_for(std::chrono::seconds(2));
    
    std::cout << "After 2 seconds pause" << std::endl;
    
    // Pause for 500 milliseconds
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    
    std::cout << "Program completed" << std::endl;
    return 0;
}
```

## 2. <ctime> Explained

The traditional C-style approach using <ctime> offers a simpler but less flexible way to handle time:

```cpp
#include <iostream>
#include <ctime>

int main() {
    std::cout << "Program starting..." << std::endl;
    
    // Pause for 2 seconds using sleep()
    time_t start = time(nullptr);
    while (time(nullptr) - start < 2) {
        // Busy waiting
    }
    
    std::cout << "After 2 seconds pause" << std::endl;
    return 0;
}
```

## 3. Comparison: std::chrono vs <ctime>

| Feature | std::chrono | <ctime> |
|---------|-------------|---------|
| Type Safety | ✓ High | ✗ Low |
| Precision | ✓ High (nanoseconds) | ✗ Limited (seconds) |
| Compile-time Checking | ✓ Yes | ✗ No |
| Platform Independence | ✓ High | ✗ Moderate |
| Ease of Use | Moderate | Simple |
| Modern C++ Integration | ✓ Excellent | ✗ Limited |

## 4. Chrono Duration and Time Period

Duration represents a time span. Here's how to work with different duration types:

```cpp
#include <chrono>
#include <iostream>

int main() {
    // Define different durations
    std::chrono::hours h(1);
    std::chrono::minutes m = std::chrono::duration_cast<std::chrono::minutes>(h);
    std::chrono::seconds s(3600);
    
    std::cout << "Hours to minutes: " << m.count() << std::endl;
    std::cout << "Seconds in 1 hour: " << s.count() << std::endl;
    
    return 0;
}
```

## 5. Duration Casting

Duration casting allows safe conversion between different time units:

```cpp
#include <chrono>
#include <iostream>

int main() {
    std::chrono::milliseconds ms(5432);
    
    // Cast to different units
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(ms);
    auto minutes = std::chrono::duration_cast<std::chrono::minutes>(ms);
    
    std::cout << "Milliseconds: " << ms.count() << std::endl;
    std::cout << "Seconds: " << seconds.count() << std::endl;
    std::cout << "Minutes: " << minutes.count() << std::endl;
    
    return 0;
}
```

## 6. Best Choice for Duration Types

std::chrono::duration<double> is often the best choice for general-purpose duration:

```cpp
#include <chrono>
#include <iostream>

int main() {
    // Using double for high precision and flexibility
    std::chrono::duration<double> time_span(3.5); // 3.5 seconds
    
    std::cout << "Time span in seconds: " << time_span.count() << std::endl;
    
    // Convert to milliseconds while preserving precision
    auto ms = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(time_span);
    std::cout << "Time span in milliseconds: " << ms.count() << std::endl;
    
    return 0;
}
```

## 7. Clock Types

Clocks provide a reference for time measurement in C++. The three main clock types are system_clock, steady_clock, and high_resolution_clock.

Below are examples of using each clock type:

### system_clock

System clock is the wall clock time:

```cpp
#include <chrono>
#include <iostream>

int main() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::cout << "Current time: " << std::ctime(&now_c);
    return 0;
}
```

### steady_clock

Steady clock is a monotonic clock that can't be adjusted:

```cpp
#include <chrono>
#include <iostream>

int main() {
    auto start = std::chrono::steady_clock::now();
    // Some operation
    auto end = std::chrono::steady_clock::now();
    auto duration = end - start;
    std::cout << "Operation took: " 
              << std::chrono::duration_cast<std::chrono::microseconds>(duration).count()
              << " microseconds" << std::endl;
    return 0;
}
```

### high_resolution_clock

High-resolution clock provides the highest precision available:

```cpp
#include <chrono>
#include <iostream>

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    // Some operation
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = end - start;
    std::cout << "Operation took: " 
              << std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count()
              << " nanoseconds" << std::endl;
    return 0;
}
```

## 8. Clock Components

Clocks consist of time points and durations. A time point represents a specific point in time, while a duration represents a time span.

Here's an example of using time points and durations:

```cpp
#include <chrono>
#include <iostream>

int main() {
    // time_point example
    auto now = std::chrono::system_clock::now();
    
    // duration example
    auto duration = std::chrono::hours(1);
    
    // now() function returns current time
    auto current = std::chrono::steady_clock::now();
    
    return 0;
}
```

## 9. Time Point Subtraction

Subtracting one time point from another created by the same clock gives a duration. Here's an example:

```cpp
#include <chrono>
#include <iostream>
#include <thread>

int main() {
    auto start = std::chrono::steady_clock::now();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    auto end = std::chrono::steady_clock::now();
    
    auto duration = end - start;
    std::cout << "Operation took: " 
              << std::chrono::duration_cast<std::chrono::milliseconds>(duration).count()
              << " milliseconds" << std::endl;
    return 0;
}
```

## 10. boost::chrono Library

The boost::chrono library provides additional functionality for time management. Here's an example of measuring the duration of an operation:

```cpp
#include <boost/chrono.hpp>
#include <iostream>

int main() {
    boost::chrono::system_clock::time_point start = boost::chrono::system_clock::now();
    // Some operation
    boost::chrono::system_clock::time_point end = boost::chrono::system_clock::now();
    boost::chrono::duration<double> sec = end - start;
    std::cout << "Operation took: " << sec.count() << " seconds" << std::endl;
    return 0;
}
```

## 11. std::chrono vs. boost::chrono Comparison

We can compare the features of `std::chrono` and `boost::chrono` to choose the right library for our needs:

| Feature | std::chrono | boost::chrono |
|---------|-------------|---------------|
| Standard Support | C++11 onwards | All C++ versions |
| Platform Support | All modern compilers | More platforms |
| Process CPU Clocks | ✗ No | ✓ Yes |
| Thread Clocks | ✗ No | ✓ Yes |
| Integration with STL | ✓ Native | ✓ Good |
| Maintenance | Part of C++ Standard | Boost Community |

## 12. Boost Process Clocks

Boost provides additional clocks for measuring process CPU time. These include `process_real_cpu_clock`, `process_user_cpu_clock`, `process_system_cpu_clock`, and `process_cpu_clock`. 

Here's an example using `process_real_cpu_clock`:

```cpp
#include <boost/chrono.hpp>
#include <iostream>

int main() {
    using namespace boost::chrono;
    
    process_real_cpu_clock::time_point start = process_real_cpu_clock::now();
    // Some CPU-intensive operation
    process_real_cpu_clock::time_point end = process_real_cpu_clock::now();
    
    auto real_time = end - start;
    std::cout << "Real CPU time: " << duration_cast<milliseconds>(real_time).count() 
              << " ms" << std::endl;
    
    return 0;
}
```

## 13. Thread Clock

The `thread_clock` in boost provides a way to measure CPU time spent by a specific thread. Recall that a thread is a sequence of instructions executed by a single thread of control.

Here's an example using `thread_clock`:

```cpp
#include <boost/chrono.hpp>
#include <iostream>
#include <thread>

void cpu_intensive_task() {
    using namespace boost::chrono;
    thread_clock::time_point start = thread_clock::now();
    
    // Some CPU-intensive operation
    for(long i = 0; i < 1000000000; ++i) {
        // Busy work
    }
    
    thread_clock::time_point end = thread_clock::now();
    auto duration = end - start;
    
    std::cout << "Thread CPU time: " 
              << duration_cast<milliseconds>(duration).count()
              << " ms" << std::endl;
}

int main() {
    std::thread t(cpu_intensive_task);
    t.join();
    return 0;
}
```

## Conclusion


Understanding time management in C++ is crucial for developing robust applications. 

The `std::chrono` library provides a modern, type-safe approach to handling time, while `boost::chrono` offers additional functionality for specific use cases. 

Choose the appropriate tools based on your requirements for precision, platform independence, and specific timing needs.

### References

1. Stroustrup, B. (2013). The C++ Programming Language, 4th Edition
2. Meyers, S. (2014). Effective Modern C++
3. C++ Reference: [https://en.cppreference.com/w/cpp/chrono](https://en.cppreference.com/w/cpp/chrono)
4. Boost Documentation: [https://www.boost.org/doc/libs/1_81_0/doc/html/chrono.html](https://www.boost.org/doc/libs/1_81_0/doc/html/chrono.html)

---
*Note: All code examples have been tested with C++17 standard. Some features might require different compiler flags or boost library installation.*