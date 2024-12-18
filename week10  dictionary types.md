# Week 10 - Dictionary Types in C++

## Introduction

This is Week 10 of our Further Programming and Algorithms course. Today, we'll explore Dictionary Types, which are fundamental data structures that enable efficient storage and retrieval of data using key-value pairs. 

These structures form the backbone of many modern applications, from database systems to caching mechanisms.

## 1. Keys and Values

### 1.1 Concept Overview

The dictionary data structure, also known as an associative array, implements a collection of key-value pairs where each key must be unique. Think of it like a real dictionary where each word (key) has its definition (value).

### 1.2 Guidelines for Use

- Keys must be unique and immutable
- Values can be of any type and duplicated
- Keys should be comparable (for ordered dictionaries)

### 1.3 Functionality

Keys serve as indices to access their associated values:

```cpp
template<typename K, typename V>
class Dictionary {
public:
    virtual void insert(const K& key, const V& value) = 0;
    virtual V* find(const K& key) = 0;
    virtual bool remove(const K& key) = 0;
    virtual bool contains(const K& key) const = 0;
};
```

### 1.4 Time Complexity

The efficiency depends on the implementation (BST or Hash Table):

- BST: O(log n) average case
- Hash Table: O(1) average case

### 1.5 Strengths

- Natural mapping of real-world relationships
- Efficient data retrieval
- Flexible value types

### 1.6 Weaknesses

- Additional memory overhead
- Performance depends on key distribution
- May require complex hash functions or comparison operators

### 1.7 Security Implications

- Potential for collision attacks in hash-based implementations
- Memory exhaustion vulnerabilities if unbounded
- Side-channel attacks possible through timing analysis

### 1.8 Example Implementation

```cpp
#include <iostream>
#include <stdexcept>

template<typename K, typename V>
class SimpleDictionary {
private:
    struct Entry {
        K key;
        V value;
        Entry* next;
        Entry(const K& k, const V& v) : key(k), value(v), next(nullptr) {}
    };
    
    Entry* entries[100];  // Simple fixed-size implementation
    
    size_t hash(const K& key) const {
        return std::hash<K>{}(key) % 100;
    }

public:
    SimpleDictionary() {
        for (int i = 0; i < 100; i++) {
            entries[i] = nullptr;
        }
    }
    
    void insert(const K& key, const V& value) {
        size_t index = hash(key);
        Entry* current = entries[index];
        
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;  // Update existing
                return;
            }
            current = current->next;
        }
        
        // Insert new entry
        Entry* newEntry = new Entry(key, value);
        newEntry->next = entries[index];
        entries[index] = newEntry;
    }
    
    V get(const K& key) const {
        size_t index = hash(key);
        Entry* current = entries[index];
        
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        
        throw std::runtime_error("Key not found");
    }
};
```

## 2. Dictionary Implementations

### 2.1 Binary Search Tree Implementation

Binary Search Trees (BSTs) provide an ordered dictionary implementation where keys are maintained in a sorted structure.

### 2.2 Hash Table Implementation

Hash Tables provide an unordered but typically faster implementation using a hash function to map keys to array indices.

## 3. Binary Search Tree

### 3.1 Concept Overview

A BST is a hierarchical data structure where each node contains a key-value pair, and:

- Left subtree contains only nodes with keys less than the node's key
- Right subtree contains only nodes with keys greater than the node's key

### 3.2 BST Keys

Keys must be comparable and maintain the BST property:

```cpp
template<typename K, typename V>
struct Node {
    K key;
    V value;
    Node* left;
    Node* right;
    
    Node(const K& k, const V& v) 
        : key(k), value(v), left(nullptr), right(nullptr) {}
};
```

### 3.3 BST Depth

Tree depth affects performance:
- Balanced tree: O(log n)
- Degenerate tree: O(n)

### 3.4 Implementation Example

```cpp
template<typename K, typename V>
class BSTDictionary {
private:
    struct Node {
        K key;
        V value;
        Node* left;
        Node* right;
        
        Node(const K& k, const V& v) 
            : key(k), value(v), left(nullptr), right(nullptr) {}
    };
    
    Node* root;
    
    Node* insert(Node* node, const K& key, const V& value) {
        if (node == nullptr) {
            return new Node(key, value);
        }
        
        if (key < node->key) {
            node->left = insert(node->left, key, value);
        } else if (key > node->key) {
            node->right = insert(node->right, key, value);
        } else {
            node->value = value;  // Update existing
        }
        
        return node;
    }
    
public:
    BSTDictionary() : root(nullptr) {}
    
    void insert(const K& key, const V& value) {
        root = insert(root, key, value);
    }
    
    // Other methods (find, remove, etc.) would go here
};
```

## 4. Hash Tables

### 4.1 Concept Overview

Hash tables use a hash function to compute an index where a key-value pair should be stored in an array.

### 4.2 Guidelines for Use

- Choose appropriate hash function
- Handle collisions effectively
- Monitor load factor

### 4.3 Collisions in Hash Tables

#### Understanding Collisions

A collision occurs when our hash function maps two different keys to the same index in our array. This is inevitable due to the pigeonhole principle - when we have more possible keys than array positions, at least two keys must hash to the same location.

#### Collision Example

Let's work through a step-by-step example of collision handling using linear probing:

Suppose we have a hash table with 7 slots (indices 0-6) and we're using the simple hash function:

```cpp
hash(key) = key % 7
```

Let's insert the following key-value pairs:

1. (15, "Apple")  → hash(15) = 1
2. (22, "Banana") → hash(22) = 1  // Collision!
3. (8, "Cherry")  → hash(8) = 1   // Another collision!

Here's how linear probing resolves these collisions:

```cpp
// Step-by-step insertion process
// Initial array: [empty, empty, empty, empty, empty, empty, empty]

// 1. Insert (15, "Apple")
hash(15) = 15 % 7 = 1
array[1] = "Apple"
// Array: [empty, Apple, empty, empty, empty, empty, empty]

// 2. Insert (22, "Banana")
hash(22) = 22 % 7 = 1  // Collision!
// Try next slot (1 + 1) % 7 = 2
array[2] = "Banana"
// Array: [empty, Apple, Banana, empty, empty, empty, empty]

// 3. Insert (8, "Cherry")
hash(8) = 8 % 7 = 1    // Collision!
// Try next slot (1 + 1) % 7 = 2  // Occupied!
// Try next slot (1 + 2) % 7 = 3
array[3] = "Cherry"
// Array: [empty, Apple, Banana, Cherry, empty, empty, empty]
```

#### Collision Resolution Strategies

1. **Open Addressing**
   - Linear Probing: Check next slot sequentially
   - Quadratic Probing: Check slots at quadratic intervals
   - Double Hashing: Use second hash function to determine interval

```cpp
// Linear Probing Implementation
size_t findSlot(const K& key) {
    size_t index = hash(key);
    size_t i = 0;
    
    while (true) {
        size_t currentSlot = (index + i) % capacity;
        if (!table[currentSlot].occupied) {
            return currentSlot;  // Found empty slot
        }
        if (table[currentSlot].key == key) {
            return currentSlot;  // Found key
        }
        i++;
        if (i >= capacity) throw std::runtime_error("Table full");
    }
}
```

2. **Separate Chaining**

   - Maintain linked list at each array position
   - All colliding elements go into the same list

```cpp
template<typename K, typename V>
class HashTableChaining {
private:
    struct Node {
        K key;
        V value;
        Node* next;
        Node(const K& k, const V& v) : key(k), value(v), next(nullptr) {}
    };
    
    std::vector<Node*> table;
    size_t size;
    
public:
    HashTableChaining(size_t capacity = 997) : table(capacity, nullptr), size(0) {}
    
    void insert(const K& key, const V& value) {
        size_t index = hash(key);
        Node* current = table[index];
        
        // Check if key exists
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;  // Update existing
                return;
            }
            current = current->next;
        }
        
        // Insert new node at beginning of chain
        Node* newNode = new Node(key, value);
        newNode->next = table[index];
        table[index] = newNode;
        size++;
    }
};
```

#### Intuition Behind Collision Resolution

The choice of collision resolution strategy reflects a space-time tradeoff:

1. **Open Addressing**
   - Pros: Better cache performance (data locality)
   - Cons: Susceptible to clustering
   - Intuition: Like finding a parking spot - if your preferred spot is taken, you look nearby

2. **Separate Chaining**
   - Pros: Less affected by high load factors
   - Cons: Extra memory for pointers
   - Intuition: Like an apartment building - multiple residents can live at same address

#### Load Factor and Rehashing

The load factor (α) is the ratio of stored elements to table size:

```cpp
float loadFactor() const {
    return static_cast<float>(size) / capacity;
}
```

When α exceeds a threshold (typically 0.7 for open addressing, can be higher for chaining), we should resize the table:

```cpp
void rehash() {
    std::vector<Entry> oldTable = std::move(table);
    capacity *= 2;
    table.resize(capacity);
    size = 0;
    
    for (const auto& entry : oldTable) {
        if (entry.occupied) {
            insert(entry.key, entry.value);
        }
    }
}
```

### 4.4 Implementation Example

```cpp
template<typename K, typename V>
class HashTable {
private:
    struct Entry {
        K key;
        V value;
        bool occupied;
        
        Entry() : occupied(false) {}
    };
    
    Entry* table;
    size_t capacity;
    size_t size;
    
    size_t hash(const K& key) const {
        return std::hash<K>{}(key) % capacity;
    }
    
    size_t probe(size_t index, size_t attempt) const {
        return (index + attempt) % capacity;  // Linear probing
    }

public:
    HashTable(size_t cap = 997) : capacity(cap), size(0) {
        table = new Entry[capacity];
    }
    
    void insert(const K& key, const V& value) {
        size_t index = hash(key);
        size_t attempt = 0;
        
        while (attempt < capacity) {
            size_t curr = probe(index, attempt);
            
            if (!table[curr].occupied) {
                table[curr].key = key;
                table[curr].value = value;
                table[curr].occupied = true;
                size++;
                return;
            }
            
            if (table[curr].key == key) {
                table[curr].value = value;
                return;
            }
            
            attempt++;
        }
        
        throw std::runtime_error("Hash table is full");
    }
};
```

## 5. STL Dictionaries

### 5.1 std::map

- Ordered dictionary implementation using Red-Black Trees
- Guaranteed O(log n) operations

```cpp
#include <map>

std::map<string, int> scores;
scores["Alice"] = 100;
scores["Bob"] = 95;
```

### 5.2 std::unordered_map

- Unordered dictionary implementation using hash tables
- Average O(1) operations

```cpp
#include <unordered_map>

std::unordered_map<string, int> scores;
scores["Alice"] = 100;
scores["Bob"] = 95;
```

## Comparison: BST vs Hash Tables

| Aspect | Binary Search Tree | Hash Table |
|--------|-------------------|------------|
| Order | Maintains key order | No key order |
| Search Time | O(log n) average | O(1) average |
| Worst Case | O(n) unbalanced | O(n) many collisions |
| Memory | O(n) | O(n) but with higher constant |
| Iteration | In-order traversal | No guaranteed order |
| Implementation | More complex | Simpler |
| Key Requirements | Comparable | Hashable |
| Collision Handling | N/A | Required |
| Use Case | Ordered data, range queries | Fast lookup, no order needed |

## Conclusion

Dictionary types are versatile data structures that provide efficient key-value storage and retrieval. The choice between BST and hash table implementations depends on specific requirements:

- Use BST (std::map) when order matters or range queries are needed
- Use hash tables (std::unordered_map) when constant-time lookup is priority
- Consider security implications when implementing custom solutions

## References

1. Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). Introduction to Algorithms (3rd ed.). MIT Press.
2. Stroustrup, B. (2013). The C++ Programming Language (4th ed.). Addison-Wesley.
3. Meyers, S. (2015). Effective Modern C++. O'Reilly Media.
4. ISO/IEC. (2017). ISO International Standard ISO/IEC 14882:2017(E) – Programming Language C++. Geneva, Switzerland: International Organization for Standardization (ISO).
