# Exercises for Lesson 14

# PRNG Practice Exercise Solutions

## Exercise 1: Linear Congruential Generator for Integers

This exercise requires generating 20 random integers between 20 and 30 using a linear congruential generator. We'll implement the LCG and then use it to generate numbers in our desired range.

```cpp
#include <iostream>
#include <iomanip>

class LinearCongruentialGenerator {
private:
    uint64_t state;
    // Using parameters similar to glibc's LCG
    const uint64_t a = 1103515245;
    const uint64_t c = 12345;
    const uint64_t m = 1ULL << 31;  // 2^31

public:
    LinearCongruentialGenerator(uint64_t seed = 1) : state(seed) {}
    
    // Generate next random number
    uint32_t next() {
        state = (a * state + c) % m;
        return state;
    }
    
    // Generate number in specific range [min, max]
    int32_t nextInRange(int32_t min, int32_t max) {
        // Using floating-point division to avoid modulo bias
        double normalized = static_cast<double>(next()) / m;
        return min + static_cast<int32_t>(normalized * (max - min + 1));
    }
};

int main() {
    LinearCongruentialGenerator lcg(time(nullptr));  // Seed with current time
    
    std::cout << "20 random integers between 20 and 30:\n";
    for(int i = 0; i < 20; i++) {
        std::cout << lcg.nextInRange(20, 30) << " ";
        if((i + 1) % 5 == 0) std::cout << "\n";  // New line every 5 numbers
    }
    return 0;
}
```

## Exercise 2: Subtract with Carry Generator for Doubles

For this exercise, we'll generate 20 random doubles between 20 and 50 using a subtract with carry generator. We'll extend our previous SWC implementation to handle double values.

```cpp
#include <iostream>
#include <iomanip>

class SubtractWithCarryGenerator {
private:
    static const int LAG = 24;
    uint32_t state[LAG];
    int index;
    int carry;
    
    // Maximum value for normalization
    const double MAX_VAL = 4294967295.0;  // 2^32 - 1

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
    
    // Generate double in range [min, max]
    double nextDouble(double min, double max) {
        double normalized = static_cast<double>(next()) / MAX_VAL;
        return min + normalized * (max - min);
    }
};

int main() {
    SubtractWithCarryGenerator swc(time(nullptr));
    
    std::cout << "20 random doubles between 20 and 50:\n";
    std::cout << std::fixed << std::setprecision(6);  // Set precision for output
    
    for(int i = 0; i < 20; i++) {
        std::cout << swc.nextDouble(20.0, 50.0) << " ";
        if((i + 1) % 4 == 0) std::cout << "\n";  // New line every 4 numbers
    }
    return 0;
}
```

## Exercise 3: Mersenne Twister with Random Device Seed

This exercise asks for 50 random doubles between -273 and 100 using a 64-bit Mersenne Twister seeded by a random device. We'll use the standard library's implementation.

```cpp
#include <iostream>
#include <random>
#include <iomanip>

int main() {
    // Create random device for seeding
    std::random_device rd;
    
    // Create 64-bit Mersenne Twister
    std::mt19937_64 gen(rd());
    
    // Create distribution for our range
    std::uniform_real_distribution<double> dis(-273.0, 100.0);
    
    std::cout << "50 random doubles between -273 and 100:\n";
    std::cout << std::fixed << std::setprecision(6);
    
    for(int i = 0; i < 50; i++) {
        std::cout << dis(gen) << " ";
        if((i + 1) % 4 == 0) std::cout << "\n";
    }
    return 0;
}
```

## Exercise 4: Normal Distribution with Mersenne Twister

Here we'll generate 100 normally distributed doubles with mean 100 and standard deviation 10, using a Mersenne Twister seeded with 4.

```cpp
#include <iostream>
#include <random>
#include <iomanip>

int main() {
    // Create Mersenne Twister with seed 4
    std::mt19937 gen(4);
    
    // Create normal distribution with mean 100 and standard deviation 10
    std::normal_distribution<double> dis(100.0, 10.0);
    
    std::cout << "100 normally distributed doubles (mean=100, std=10):\n";
    std::cout << std::fixed << std::setprecision(6);
    
    for(int i = 0; i < 100; i++) {
        std::cout << dis(gen) << " ";
        if((i + 1) % 4 == 0) std::cout << "\n";
    }
    return 0;
}
```

## Exercise 5: Custom Probability Distribution for Even/Odd Numbers

This exercise requires generating 100 integers between 0 and 9, where even numbers should be twice as likely as odd numbers. We'll use a discrete distribution to achieve this.

```cpp
#include <iostream>
#include <random>
#include <vector>
#include <map>

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    
    // Create probability weights: 2 for even numbers, 1 for odd numbers
    std::vector<double> weights = {2, 1, 2, 1, 2, 1, 2, 1, 2, 1};
    std::discrete_distribution<> dis(weights.begin(), weights.end());
    
    // Map to count occurrences of each number
    std::map<int, int> counts;
    
    // Generate 100 numbers
    std::cout << "100 random integers (0-9) with even numbers twice as likely:\n";
    for(int i = 0; i < 100; i++) {
        int num = dis(gen);
        counts[num]++;
        std::cout << num << " ";
        if((i + 1) % 20 == 0) std::cout << "\n";
    }
    
    // Print distribution statistics
    std::cout << "\nDistribution statistics:\n";
    for(const auto& pair : counts) {
        std::cout << "Number " << pair.first << ": " 
                 << pair.second << " times (" 
                 << static_cast<double>(pair.second) << "%)\n";
    }
    return 0;
}
```

### Implementation Notes

1. For the LCG implementation, we used parameters similar to those used in glibc to ensure good statistical properties. We also used floating-point division to avoid modulo bias when generating numbers in a specific range.

2. The SWC generator implementation includes proper normalization to generate doubles in the desired range. The large lag value (24) helps ensure a good period length.

3. For the Mersenne Twister examples, we used the standard library implementation which is both efficient and well-tested. The 64-bit version (mt19937_64) provides even better statistical properties than the 32-bit version.

4. The normal distribution example demonstrates how easy it is to generate non-uniform distributions using the standard library's facilities.

5. For the final exercise, we used a discrete distribution with weights of 2 for even numbers and 1 for odd numbers, which ensures that even numbers are twice as likely to be selected. We also included counting code to verify the distribution.

### Additional Considerations

- All implementations include proper seeding mechanisms to ensure different sequences on each run.
- Output formatting is included to make the results readable.
- Error checking could be added for production code.
- The solutions demonstrate both custom implementations and standard library usage.

Feel free to experiment with different seeds and parameters to see how they affect the output distributions.