#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// Iterative
string iterativeBinary(int n) {
    if (n == 0) return "0";
    string result = "";
    while (n > 0) {
        result = char((n % 2) + '0') + result;
        n /= 2;
    }
    return result;
}

// Recursive
string recursiveBinary(int n) {
    if (n == 0) return "0";
    if (n == 1) return "1";
    return recursiveBinary(n / 2) + char((n % 2) + '0');
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;
    
    // Run 1 million times to see difference
    int runs = 1000000;
    
    // Time iterative
    clock_t start1 = clock();
    string iter_result;
    for (int i = 0; i < runs; i++) {
        iter_result = iterativeBinary(n);
    }
    clock_t end1 = clock();
    double time1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
    
    // Time recursive
    clock_t start2 = clock();
    string rec_result;
    for (int i = 0; i < runs; i++) {
        rec_result = recursiveBinary(n);
    }
    clock_t end2 = clock();
    double time2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
    
    // Display results
    cout << "\nIterative: " << iter_result << endl;
    cout << "Recursive: " << rec_result << endl;
    
    if (iter_result == rec_result) {
        cout << "Results match!\n";
    }
    
    // Show timing
    cout << "\nTiming (" << runs << " runs):" << endl;
    cout << "Iterative: " << time1 << " seconds" << endl;
    cout << "Recursive: " << time2 << " seconds" << endl;
    
    // Simple comparison
    if (time1 < time2) {
        cout << "Iterative is faster" << endl;
    } else if (time2 < time1) {
        cout << "Recursive is faster" << endl;
    } else {
        cout << "Same speed" << endl;
    }
    
    return 0;
}