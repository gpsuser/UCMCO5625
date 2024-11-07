# Big O Notation

`Big O notation` is a mathematical notation used to describe the upper bound of an algorithm’s running time or space requirements in terms of the size of the input. 

* It provides a high-level understanding of the algorithm’s efficiency and performance, especially as the input size grows.
* Big O notation focuses on the worst-case scenario, helping to predict the behavior of an algorithm under maximum load.

## Clock Cycles
A `clock cycle` is a single tick of the clock in a computer’s CPU. During each clock cycle, the CPU can perform a basic operation, such as fetching an instruction, decoding it, or executing it. 
* The number of clock cycles an algorithm takes to complete can be used to measure its performance.

## Relationship Between Big O Notation and Clock Cycles
Big O notation abstracts away the specific details of hardware, such as clock cycles, to provide a more general understanding of an algorithm’s efficiency. 

However, the number of clock cycles required to execute an algorithm can give a practical sense of its performance. 

`For example`, an algorithm with a time complexity of `O(n^2)`  will require more clock cycles - as the input `size ( n )` increases - when compared to an algorithm with a time complexity of `O(n)`