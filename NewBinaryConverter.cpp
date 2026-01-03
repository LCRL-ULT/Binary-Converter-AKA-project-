#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// Iterative method
string iterativeBinary(int n) {
    if (n == 0) return "0";
    string result = "";
    while (n > 0) {
        result = char((n % 2) + '0') + result;
        n /= 2;
    }
    return result;
}

// Recursive method
string recursiveBinary(int n) {
    if (n == 0) return "0";
    if (n == 1) return "1";
    return recursiveBinary(n / 2) + char((n % 2) + '0');
}

int main() {
    int number;
    cout << "Enter a decimal number: ";
    cin >> number;
    
    // Get results
    string iterResult = iterativeBinary(number);
    string recResult = recursiveBinary(number);
    
    cout << "\nIterative: " << iterResult << endl;
    cout << "Recursive: " << recResult << endl;
    
    if (iterResult == recResult) {
        cout << "Results match!" << endl;
    }
    
    // Timing test
    int testRuns = 1000000; // 1 million runs
    
    clock_t start1 = clock();
    for (int i = 0; i < testRuns; i++) {
        iterativeBinary(number);
    }
    double time1 = (double)(clock() - start1) / CLOCKS_PER_SEC;
    
    clock_t start2 = clock();
    for (int i = 0; i < testRuns; i++) {
        recursiveBinary(number);
    }
    double time2 = (double)(clock() - start2) / CLOCKS_PER_SEC;
    
    cout << "\n=== Timing Comparison ===" << endl;
    cout << testRuns << " runs each:" << endl;
    cout << "Iterative: " << time1 << " seconds" << endl;
    cout << "Recursive: " << time2 << " seconds" << endl;
    
    if (time1 < time2) {
        cout << "Iterative is faster" << endl;
    } else if (time2 < time1) {
        cout << "Recursive is faster" << endl;
    }
    
    return 0;
}