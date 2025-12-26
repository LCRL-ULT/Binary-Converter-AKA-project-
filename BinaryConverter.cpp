#include <iostream>
#include <string>
using namespace std;

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
    
    string iterativeResult = decimalToBinaryIterative(number);
    string recursiveResult = decimalToBinaryRecursiveWrapper(number);
    
    cout << "Iterative result: " << iterativeResult << endl;
    cout << "Recursive result: " << recursiveResult << endl;
    
    if (iterativeResult == recursiveResult) {
        cout << " Both algorithms give the same result!" << endl;
    } else {
        cout << " Results differ!" << endl;
    }
    
    return 0;
}