#include <iostream>
using namespace std;

/* 
   TOPIC 6: SEARCHING
   ------------------
   Binary Search: Array MUST be sorted. O(log n)
*/

int binarySearch(int a[], int size, int target) {
    int first = 0, last = size - 1, middle;
    
    // Exam Step-by-Step Tracing Logic:
    // 1. Calculate middle
    // 2. If target == a[middle], found!
    // 3. If target > a[middle], search right half (first = middle + 1)
    // 4. If target < a[middle], search left half (last = middle - 1)
    
    while (first <= last) {
        middle = (first + last) / 2;
        if (target == a[middle]) return middle;
        else if (target > a[middle]) first = middle + 1;
        else last = middle - 1;
    }
    return -1;
}

/* 
   TOPIC 7: HASHING
   ----------------
   Collision: When two keys map to the same index.
   Resolution:
   1. Linear Probing (Open Addressing): index = (index + 1) % size
   2. Chaining: Each index is a head of a linked list.
   3. Truncation: Taking specific digits (e.g., first 2 and last 2).
*/

// EXAM SNIPPET: Truncation (Feb 2025 Q3c)
// "Truncate first digits and last two digits of a six digit number"
// Example: 654321 -> First is 6, Last two is 21 -> Result 621
void hashTruncation(int num) {
    int firstDigit = num / 100000;
    int lastTwoDigits = num % 100;
    int result = (firstDigit * 100) + lastTwoDigits;
    cout << "Hash of " << num << " is: " << result << endl;
}

// EXAM SNIPPET: Linear Probing Trace (Feb 2025 Q3d)
/*
   Table size = 7, h(x) = x % 7. Keys: 28, 14, 36, 46
   1. 28 % 7 = 0. Index 0 is FREE. [0]: 28
   2. 14 % 7 = 0. Index 0 is BUSY. (0+1)%7 = 1. Index 1 is FREE. [1]: 14
   3. 36 % 7 = 1. Index 1 is BUSY. (1+1)%7 = 2. Index 2 is FREE. [2]: 36
   4. 46 % 7 = 4. Index 4 is FREE. [4]: 46
*/

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60};
    int target = 40;
    int res = binarySearch(arr, 6, target);
    cout << "Binary Search for 40 found at index: " << res << endl;
    
    hashTruncation(654321);
    
    return 0;
}
