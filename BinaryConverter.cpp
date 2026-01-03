#include <iostream>
#include <string>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Your original functions - UNCHANGED
// Iterative
string decimalToBinaryIterative(int n) {
    if (n == 0) return "0";

    string result = "";
    while (n > 0) {
        result = char((n % 2) + '0') + result;
        n /= 2;
    }
    return result;
}

// Recursive
string decimalToBinaryRecursive(int n) {
    if (n == 0) return "";
    return decimalToBinaryRecursive(n / 2) + char((n % 2) + '0');
}

// Recursive wrapper to handle n=0 case
string decimalToBinaryRecursiveWrapper(int n) {
    if (n == 0) return "0";
    return decimalToBinaryRecursive(n);
}

int main() {
    int number;

    cout << "Enter a decimal number: ";
    cin >> number;

    // Test Iterative with speed measurement
    auto start_iter = high_resolution_clock::now();
    string iterativeResult = decimalToBinaryIterative(number);
    auto end_iter = high_resolution_clock::now();

    // Calculate time in microseconds as decimal
    duration<double, micro> iterative_time = end_iter - start_iter;

    cout << "Iterative result: " << iterativeResult << endl;
    cout << "Iterative speed: " << iterative_time.count() << " microseconds" << endl;

    // Test Recursive with speed measurement
    auto start_recur = high_resolution_clock::now();
    string recursiveResult = decimalToBinaryRecursiveWrapper(number);
    auto end_recur = high_resolution_clock::now();

    // Calculate time in microseconds as decimal
    duration<double, micro> recursive_time = end_recur - start_recur;

    cout << "Recursive result: " << recursiveResult << endl;
    cout << "Recursive speed: " << recursive_time.count() << " microseconds" << endl;

    // Verification
    if (iterativeResult == recursiveResult) {
        cout << " Both algorithms give the same result!" << endl;
    } else {
        cout << " Results differ!" << endl;
    }

    return 0;
}