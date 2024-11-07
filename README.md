# Additional Course notes : Algorithms, Data Structures and C++

## Week 1

## Week 2

## Week 3

## Week 4 - Big O Notation

`Big O notation` is a mathematical notation used to describe the upper bound of an algorithm's running time or space requirements in terms of the size of the input.

* It provides a high-level understanding of the algorithm's efficiency and performance, especially as the input size grows.
* Big O notation focuses on the worst-case scenario, helping to predict the behavior of an algorithm under maximum load.

## Clock Cycles

A `clock cycle` is a single tick of the clock in a computer's CPU. 

* During each clock cycle, the CPU can perform a basic operation, such as fetching an instruction, decoding it, or executing it. 
* The number of clock cycles an algorithm takes to complete can be used to measure its performance.

## Relationship Between Big O Notation and Clock Cycles

Big O notation abstracts away the specific details of hardware, such as clock cycles, to provide a more general understanding of an algorithm's efficiency.

However, the number of clock cycles required to execute an algorithm can give a practical sense of its performance. 

`For example`, an algorithm with a time complexity of `O(n^2)`  will require more clock cycles - as the input `size ( n )` increases - when compared to an algorithm with a time complexity of `O(n)`


### Challenge

Write a C++ program that finds all pairs of elements in an array whose sum is equal to a given target value. The program should then determine the time complexity of the solution using Big O notation.

May need to use a `hash table` to solve this problem.

**What is a Hash Table?**

A hash table is a data structure that stores key-value pairs. It uses a special function called a hash function to map keys to specific locations (indices) in an array. This allows for incredibly fast lookups, insertions, and deletions of elements.

**How does it work?**

1. **Hash Function:** When you want to store a key-value pair, the hash function takes the key as input and generates a hash code (an integer). This hash code is then used to calculate an index within the array.
2. **Array (Buckets):** The hash table uses an array to store the key-value pairs. Each element of the array is called a bucket.
3. **Collisions:** Sometimes, two different keys might produce the same hash code, leading to a collision. To handle this, different techniques like chaining or open addressing are used within the buckets.

**Simple Example:**

Imagine you're creating a phonebook using a hash table. The names are the keys, and the phone numbers are the values.

1. **Hash Function:** You define a hash function that takes a name and generates a number between 0 and 9.
2. **Array:** You create an array with 10 buckets (indexed from 0 to 9).
3. **Insertion:**
    - To add "Alice" with phone number "123-4567", you hash "Alice" to get 3. You store the pair ("Alice", "123-4567") in the 3rd bucket.
    - To add "Bob" with phone number "987-6543", you hash "Bob" and get 7. You store the pair ("Bob", "987-6543") in the 7th bucket.

**Lookup:**

To find Alice's phone number:

1. Hash "Alice" to get 3.
2. Look in the 3rd bucket and retrieve her phone number.

**Key Points:**

* Hash tables offer near-constant time (O(1)) for lookups, insertions, and deletions on average.
* A good hash function is crucial for efficient performance.
* Collision handling techniques are essential to manage multiple keys mapping to the same bucket.


