# Binary Converter: Iterative vs. Recursive

This project provides a comparison between two different algorithmic approaches to converting a decimal (base-10) number into a binary (base-2) string using C++.

## Project Overview
The goal of this project is to analyze the performance and implementation differences between:
1. **Iterative Approach**: Using a loop to calculate binary digits.
2. **Recursive Approach**: Using function self-calls to build the binary string.

## Time Complexity Analysis

### 1. Iterative Algorithm
* **Logic**: Uses a `while` loop to divide the number by 2 until it reaches zero.
* **Time Complexity**: **O(log n)**, where *n* is the input decimal number. This is because the number of iterations is determined by how many times *n* can be divided by 2.
* **Space Complexity**: **O(log n)** to store the resulting string characters.

### 2. Recursive Algorithm
* **Logic**: Calls itself with `n / 2` and appends the remainder `n % 2` to the result.
* **Time Complexity**: **O(log n)**. Similar to the iterative version, the number of recursive calls is proportional to the number of bits in the binary representation.
* **Space Complexity**: **O(log n)**. Each recursive call adds a new frame to the call stack, which can lead to higher memory usage than the iterative approach for extremely large numbers.

## How to Run
1. Ensure you have a C++ compiler installed (like GCC/MinGW).
2. Compile the code:
   ```bash
   g++ BinaryConverter.cpp -o BinaryConverter
