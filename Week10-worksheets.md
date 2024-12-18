# Week 10 - Dictionary Types: Practice Worksheets

---

## Worksheet 1

### Question 1 (Simple)

Write a function that counts how many collisions occur when inserting the following keys into a hash table of size 10 using the hash function h(k) = k % 10. Keys to insert: 13, 23, 33, 43, 15. Show your work step by step.

### Question 2 (Medium)

Implement a simple dictionary using a Binary Search Tree that stores string keys and integer values. Include methods for insert() and find(). Your implementation should maintain the BST property. You don't need to implement balancing.

### Question 3 (Medium-Advanced)

Write a function that determines whether a given Binary Search Tree implementation of a dictionary is "height-balanced" (i.e., the heights of the two subtrees of any node never differ by more than one). Include a method that returns the height of any node.

---

## Worksheet 2


Fill in the blanks with the appropriate terms or values. Choose from the scrambled answers provided below.

1. In a hash table, the ________ is the ratio of the number of stored elements to the table size.

2. A Binary Search Tree maintains the property that all keys in the ________ subtree are less than the current node's key.

3. The time complexity of searching in a hash table with perfect hashing is ________.

4. When implementing separate chaining in a hash table, each array position contains a ________.

5. The STL container ________ implements an ordered dictionary using a Red-Black Tree.

6. In open addressing with linear probing, if a collision occurs at position i, the next position tried is ________.

7. A hash table should be resized when its load factor exceeds ________.

8. The worst-case time complexity of searching in an unbalanced BST is ________.

9. ________ is a collision resolution strategy that uses a second hash function to determine the interval between probe attempts.

10. The STL container ________ implements an unordered dictionary using a hash table.

### Scrambled Answers

- Double hashing
- std::map
- O(1)
- linked list
- 0.7
- left
- (i + 1) % size
- std::unordered_map
- O(n)
- load factor

