# Week 14: Pseudorandom Number Generation in C++

## Learning Objectives

By the end of this lecture, students will be able to:
1. Understand the concept and importance of pseudorandom number generation
2. Implement and analyze different PRNG algorithms
3. Compare various random number generation methods in C++
4. Create custom probability distributions using modern C++ random facilities
5. Evaluate the strengths and weaknesses of different PRNG approaches

## Introduction

Random numbers play a crucial role in various computing applications, from cryptography to game development. However, generating truly random numbers on a deterministic machine presents an interesting challenge. This is where pseudorandom number generation (PRNG) comes into play.

## 1. Pseudorandom Number Generation Explained

Pseudorandom number generation is a process of generating sequences of numbers that approximate the properties of random numbers. These sequences are:
- Deterministic (same seed produces same sequence)
- Statistically random (pass various statistical tests)
- Periodic (eventually repeat, but with a very long period)

Key characteristics of a good PRNG:
- Long period length
- Good statistical distribution
- Efficiency in generation
- Reproducibility when needed

## 2. Methods for PRNG - Background Context

### 2.1 Linear Congruential Generator (LCG)

The LCG is one of the oldest and simplest PRNG algorithms, defined by the recurrence relation:
```
Xn+1 = (a * Xn + c) mod m
```
Where:
- a is the multiplier
- c is the increment
- m is the modulus
- X0 is the seed

Here's a sample implementation:

```cpp
class LinearCongruentialGenerator {
private:
    uint64_t state;
    const uint64_t a = 1664525;
    const uint64_t c = 1013904223;
    const uint64_t m = 0xFFFFFFFF;  // 2^32

public:
    LinearCongruentialGenerator(uint64_t seed = 1) : state(seed) {}
    
    uint32_t next() {
        state = (a * state + c) % m;
        return state;
    }
    
    // Generate a number in range [min, max]
    int32_t nextInRange(int32_t min, int32_t max) {
        return min + (next() % (max - min + 1));
    }
};
```

### 2.2 Mersenne Twister

The Mersenne Twister is a more sophisticated PRNG that addresses many limitations of simpler generators. It provides a period of 2^19937-1 and excellent statistical properties.

Basic implementation (simplified version):

```cpp
class MersenneTwister {
private:
    static const int N = 624;
    static const int M = 397;
    uint32_t mt[N];
    int index;

    void twist() {
        const uint32_t MATRIX_A = 0x9908b0df;
        const uint32_t UPPER_MASK = 0x80000000;
        const uint32_t LOWER_MASK = 0x7fffffff;

        for (int i = 0; i < N; i++) {
            uint32_t x = (mt[i] & UPPER_MASK) + (mt[(i + 1) % N] & LOWER_MASK);
            uint32_t xA = x >> 1;
            if (x % 2) xA ^= MATRIX_A;
            mt[i] = mt[(i + M) % N] ^ xA;
        }
        index = 0;
    }

public:
    MersenneTwister(uint32_t seed = 5489) {
        mt[0] = seed;
        for (int i = 1; i < N; i++) {
            mt[i] = 1812433253UL * (mt[i-1] ^ (mt[i-1] >> 30)) + i;
        }
        index = N;
    }

    uint32_t next() {
        if (index >= N) twist();
        
        uint32_t y = mt[index++];
        y ^= (y >> 11);
        y ^= (y << 7) & 0x9d2c5680;
        y ^= (y << 15) & 0xefc60000;
        y ^= (y >> 18);
        
        return y;
    }
};
```

### 2.3 Subtract with Carry Generator

The Subtract with Carry (SWC) generator is another method that offers good statistical properties and a relatively long period.

```cpp
class SubtractWithCarryGenerator {
private:
    static const int LAG = 24;
    uint32_t state[LAG];
    int index;
    int carry;

public:
    SubtractWithCarryGenerator(uint32_t seed = 12345) {
        // Initialize state using LCG
        uint32_t lcg = seed;
        for (int i = 0; i < LAG; i++) {
            lcg = 1664525 * lcg + 1013904223;
            state[i] = lcg;
        }
        index = 0;
        carry = 0;
    }

    uint32_t next() {
        const int SHORT_LAG = 10;
        uint32_t result = state[(index + LAG - SHORT_LAG) % LAG] - 
                         state[index] - carry;
        
        carry = (result > state[(index + LAG - SHORT_LAG) % LAG]) ? 1 : 0;
        state[index] = result;
        index = (index + 1) % LAG;
        
        return result;
    }
};
```

## 3. Rand() Explained

The classic `rand()` function from C's standard library is still commonly seen but has several limitations:

```cpp
#include <cstdlib>

// Seeding the generator
srand(time(nullptr));

// Generating random numbers
int random_number = rand();
int random_range = rand() % 100; // 0-99
```

### 3.1 The Trouble with Rand()

Problems with `rand()`:
1. Small period (RAND_MAX is often just 32767)
2. Poor statistical properties
3. Modulo bias when generating ranges
4. Not thread-safe
5. Implementation-dependent behavior

## 4. std::random Explained

Modern C++ provides a much more robust random number facility through the `<random>` header:

```cpp
#include <random>
#include <iostream>

int main() {
    // Create a random device for seeding
    std::random_device rd;
    
    // Create a Mersenne Twister generator
    std::mt19937 gen(rd());
    
    // Generate some random numbers
    for(int i = 0; i < 5; i++) {
        std::cout << gen() << std::endl;
    }
    
    return 0;
}
```

## 5. Custom Distributions

### 5.1 Uniform Integer Distribution

```cpp
#include <random>
#include <iostream>

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    
    // Generate integers in range [1, 6] (like a die)
    std::uniform_int_distribution<> dis(1, 6);
    
    for(int i = 0; i < 10; i++) {
        std::cout << dis(gen) << " ";
    }
    return 0;
}
```

### 5.2 Uniform Real Distribution

```cpp
#include <random>
#include <iostream>

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    
    // Generate real numbers in range [0.0, 1.0)
    std::uniform_real_distribution<double> dis(0.0, 1.0);
    
    for(int i = 0; i < 5; i++) {
        std::cout << dis(gen) << std::endl;
    }
    return 0;
}
```

### 5.3 Discrete Distribution

```cpp
#include <random>
#include <iostream>
#include <vector>

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    
    // Define probabilities for outcomes 0,1,2,3
    std::vector<double> probabilities = {0.1, 0.4, 0.3, 0.2};
    std::discrete_distribution<> dis(probabilities.begin(), probabilities.end());
    
    // Generate and count outcomes
    std::vector<int> counts(4, 0);
    for(int i = 0; i < 1000; i++) {
        counts[dis(gen)]++;
    }
    
    // Print results
    for(int i = 0; i < counts.size(); i++) {
        std::cout << "Outcome " << i << ": " 
                 << static_cast<double>(counts[i])/10 << "%" << std::endl;
    }
    return 0;
}
```

## Conclusion

Modern C++ provides powerful tools for generating pseudorandom numbers that are suitable for various applications. While simple generators like LCG can be useful for basic needs, more sophisticated generators like Mersenne Twister combined with proper distributions should be used for serious applications.

Key takeaways:
- Avoid `rand()` in modern C++ code
- Use `std::random_device` for seeding
- Choose appropriate generators based on needs
- Use proper distributions rather than modulo operations
- Consider thread safety in concurrent applications

## References

1. Matsumoto, M., & Nishimura, T. (1998). Mersenne twister: a 623-dimensionally equidistributed uniform pseudo-random number generator. *ACM Transactions on Modeling and Computer Simulation*, 8(1), 3-30.

2. Knuth, D. E. (1997). *The Art of Computer Programming, Volume 2: Seminumerical Algorithms*. Addison-Wesley Professional.

3. Stroustrup, B. (2013). *The C++ Programming Language*, 4th Edition. Addison-Wesley Professional.

4. C++ Reference. (2023). *Random number generation*. https://en.cppreference.com/w/cpp/numeric/random