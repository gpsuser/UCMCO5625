
# Lecture 13 - Custom Data Types, Operator Overloading, and Comparison Functions within the context of Sorting in C++

## Introduction to Custom Data Types

In C++, creating custom data types allows us to model complex real-world entities that aren't well-represented by built-in types like `int` or `float`. Let's explore this concept through a practical example.

### Motivation for Custom Data Types

Imagine we're building a scientific application that needs to work with 2D points in a coordinate system. While we could represent a point using two separate variables for x and y coordinates, this approach becomes unwieldy when we need to:

- Pass points as function parameters
- Store collections of points
- Ensure coordinates stay together as a logical unit
- Implement operations that work with points as single entities

### Example: Creating a Point Class

Here's how we might implement a basic Point class:

```cpp
class Point {
private:
    double x;
    double y;

public:
    // Constructor
    Point(double x_coord = 0.0, double y_coord = 0.0) : x(x_coord), y(y_coord) {}

    // Accessor methods
    double getX() const { return x; }
    double getY() const { return y; }

    // Mutator methods
    void setX(double x_coord) { x = x_coord; }
    void setY(double y_coord) { y = y_coord; }
};
```

## Understanding Operator Overloading

### Motivation for Operator Overloading

When working with custom types, we often want them to behave similarly to built-in types. For instance, with our Point class, it would be natural to:

- Add two points using the + operator
- Compare points using ==  
- Print points  

Operator overloading lets us define these intuitive behaviors for our custom types.

### Example: Basic Operator Overloading

Let's add the ability to add two points and check if they're equal:

```cpp
class Point {
    // Previous members remain the same...

public:
    // Overload + operator for adding points
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    // Overload == operator for comparing points
    bool operator==(const Point& other) const {
        return (x == other.x) && (y == other.y);
    }

    // Overload << operator for easy printing
    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};
```

## Advanced Example: Operator Overloading for Sorting

Let's extend our Point class to support sorting based on distance from the origin. This example demonstrates how operator overloading can make our custom types work seamlessly with standard library algorithms.

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


class Point {
private:
    double x;
    double y;

    // Helper method to calculate distance from origin
    double distanceFromOrigin() const {
        return std::sqrt(x * x + y * y);
    }

public:
    // Constructor
    Point(double x_coord = 0.0, double y_coord = 0.0) : x(x_coord), y(y_coord) {}

    // Accessor methods
    double getX() const { return x; }
    double getY() const { return y; }

    // Mutator methods
    void setX(double x_coord) { x = x_coord; }
    void setY(double y_coord) { y = y_coord; }



    // Overload + operator for adding points
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    // Overload == operator for comparing points
    bool operator==(const Point& other) const {
        return (x == other.x) && (y == other.y);
    }

    // Overload << operator for easy printing
    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }

    // Overload < operator for sorting
    bool operator<(const Point& other) const {
        return distanceFromOrigin() < other.distanceFromOrigin();
    }


};


// Example usage
int main() {
    std::vector<Point> points = {
        Point(3, 4),
        Point(1, 2),
        Point(5, 12),
        Point(0, 1)
    };

    // Sort points by distance from origin
    sort(points.begin(), points.end());

    // Print sorted points
    std::cout << "Points sorted by distance from origin:" << std::endl;
    for (const auto& point : points) {
        std::cout << point << " - Distance: "
            << std::sqrt(point.getX() * point.getX() + point.getY() * point.getY())
            << std::endl;
    }

    return 0;
}

```

Sample Output:

```
Points sorted by distance from origin:
(0, 1) - Distance: 1
(1, 2) - Distance: 2.23607
(3, 4) - Distance: 5
(5, 12) - Distance: 13
```

This code will output the points sorted by their distance from the origin (0,0), demonstrating how operator overloading allows our custom Point class to work naturally with standard C++ sorting algorithms.

### Key Takeaways

1. Custom data types allow us to create abstractions that match our problem domain.
2. Operator overloading lets these custom types behave intuitively, similar to built-in types.
3. By implementing comparison operators, we can make our custom types work seamlessly with standard library algorithms like sort.

When used appropriately, these features make our code more readable, maintainable, and less prone to errors by allowing us to work with abstractions that closely match the problem we're solving.

---

Next, let's explore comparison functions in C++ and how they relate to operator overloading.

# Understanding Comparison Functions and Operators in C++

## Introduction

In our previous discussion about custom data types and operator overloading, we focused on implementing comparison operators directly within our Point class. However, C++ offers another powerful approach to handling comparisons: comparison functions. 

Let's explore how these two approaches relate and when to use each one.

## Comparison Functions vs. Comparison Operators

### Comparison Operators

Recall our Point class implementation where we overloaded the < operator:

```cpp
class Point {
    // ... other members ...
    
    bool operator<(const Point& other) const {
        return distanceFromOrigin() < other.distanceFromOrigin();
    }
};
```

This approach embeds the comparison logic directly in the class. While straightforward, it has a limitation: we can only define one "natural" ordering for our type.

### Comparison Functions

Comparison functions provide more flexibility by separating the comparison logic from the class definition. They are typically implemented as standalone functions or function objects (functors). Here's how we might implement a comparison function for our Point class:

```cpp
// A standalone comparison function
bool compareByDistanceFromOrigin(const Point& p1, const Point& p2) {
    return p1.distanceFromOrigin() < p2.distanceFromOrigin();
}

// A function object (functor) approach
struct PointComparator {
    bool operator()(const Point& p1, const Point& p2) const {
        return p1.distanceFromOrigin() < p2.distanceFromOrigin();
    }
};
```

## Advanced Example: Multiple Comparison Strategies

Let's expand our Point class to demonstrate how comparison functions provide more flexibility than operator overloading alone:

```cpp
class Point {
private:
    double x;
    double y;

public:
    Point(double x_coord = 0.0, double y_coord = 0.0) : x(x_coord), y(y_coord) {}

    double getX() const { return x; }
    double getY() const { return y; }

    // Helper method made public for use in comparison functions
    double distanceFromOrigin() const {
        return std::sqrt(x*x + y*y);
    }

    // Basic comparison operator remains for "natural" ordering
    bool operator<(const Point& other) const {
        return distanceFromOrigin() < other.distanceFromOrigin();
    }
};

// Different comparison strategies as function objects
struct CompareByX {
    bool operator()(const Point& p1, const Point& p2) const {
        return p1.getX() < p2.getX();
    }
};

struct CompareByY {
    bool operator()(const Point& p1, const Point& p2) const {
        return p1.getY() < p2.getY();
    }
};

struct CompareByDistance {
    Point reference;
    
    CompareByDistance(const Point& ref = Point(0, 0)) : reference(ref) {}
    
    bool operator()(const Point& p1, const Point& p2) const {
        double dist1 = std::sqrt(std::pow(p1.getX() - reference.getX(), 2) + 
                               std::pow(p1.getY() - reference.getY(), 2));
        double dist2 = std::sqrt(std::pow(p2.getX() - reference.getX(), 2) + 
                               std::pow(p2.getY() - reference.getY(), 2));
        return dist1 < dist2;
    }
};

// Example usage
int main() {
    std::vector<Point> points = {
        Point(3, 4),
        Point(1, 2),
        Point(5, 12),
        Point(0, 1)
    };

    // Sort using default comparison operator
    std::sort(points.begin(), points.end());
    std::cout << "Sorted by distance from origin (using operator<):\n";
    for (const auto& p : points) {
        std::cout << "(" << p.getX() << ", " << p.getY() << ")\n";
    }

    // Sort by X-coordinate using comparison function
    std::sort(points.begin(), points.end(), CompareByX());
    std::cout << "\nSorted by X-coordinate:\n";
    for (const auto& p : points) {
        std::cout << "(" << p.getX() << ", " << p.getY() << ")\n";
    }

    // Sort by distance from a reference point (1,1)
    std::sort(points.begin(), points.end(), CompareByDistance(Point(1, 1)));
    std::cout << "\nSorted by distance from (1,1):\n";
    for (const auto& p : points) {
        std::cout << "(" << p.getX() << ", " << p.getY() << ")\n";
    }

    return 0;
}
```

Sample Output:

```
Sorted by distance from origin (using operator<):
(0, 1)
(1, 2)
(3, 4)
(5, 12)

Sorted by X-coordinate:
(0, 1)
(1, 2)
(3, 4)
(5, 12)

Sorted by distance from (1,1):
(0, 1)
(1, 2)
(3, 4)
(5, 12)
```

This example demonstrates how comparison functions can encapsulate different comparison strategies, allowing us to sort our custom type based on various criteria.


## When to Use Each Approach

### Use Operator Overloading When:

1. There is a clear, single "natural" ordering for your type
2. The comparison logic is fundamental to the type's behavior
3. You want to enable use with standard library functions that expect operator

### Use Comparison Functions When:

1. Multiple valid ordering criteria exist
2. The comparison logic might change at runtime
3. The comparison depends on external factors
4. You want to keep the class interface smaller and more focused

## Integration with Standard Library

The C++ Standard Library is designed to work with both approaches. For example, `std::sort` can use either:

```cpp
// Using operator
std::sort(points.begin(), points.end());

// Using comparison function
std::sort(points.begin(), points.end(), CompareByX());

// Using lambda expression (another form of comparison function)
std::sort(points.begin(), points.end(), 
    [](const Point& p1, const Point& p2) { return p1.getX() < p2.getX(); });
```

## Modern C++ Considerations

In C++20, the spaceship operator (`<=>`) was introduced to simplify comparison operations. While this is a significant improvement for operator overloading, comparison functions remain valuable for their flexibility and separation of concerns.

Understanding both approaches gives you the tools to choose the most appropriate solution for your specific needs, leading to more maintainable and flexible code.










