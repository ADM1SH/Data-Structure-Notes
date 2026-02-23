#include <iostream>
using namespace std;

/* 
   TOPIC 2: POINTERS & DYNAMIC MEMORY
   ---------------------------------
   Key Concepts:
   1. *ptr -> Value stored at the address (Dereferencing)
   2. &var -> Address of the variable
   3. new  -> Allocate memory on the heap
   4. delete -> Free heap memory
*/

// --- EXAM SNIPPET: POINTER TRACING (From Feb 2025 Paper) ---
void exam_tracing_1() {
    cout << "--- Exam Tracing Snippet 1 ---" << endl;
    int array[] = {10, 20, 30, 40}, num = 50;
    int *ptr1, *ptr2;
    
    ptr1 = array;          // ptr1 points to array[0] (10)
    *(ptr1 + 1) = *ptr1 + 1; // array[1] = 10 + 1 = 11
    ptr2 = &num;           // ptr2 points to num (50)
    *ptr2 = *ptr1 + 3;     // num = 10 + 3 = 13
    ptr1[3] = array[2];    // array[3] = array[2] = 30
    ptr2 = &num;           // ptr2 still points to num (13)
    int value = num;       // value = 13
    *ptr2 = value + 10;    // num = 13 + 10 = 23
    
    // Output tracing: (ptr1+i) + value
    // ptr1 points to array start: {10, 11, 30, 30}
    // value = 23 (since num was updated via ptr2)
    for (int i = 0; i < 4; i++) {
        cout << *(ptr1 + i) + value << " ";
        // i=0: 10 + 23 = 33
        // i=1: 11 + 23 = 34
        // i=2: 30 + 23 = 53
        // i=3: 30 + 23 = 53
    }
    cout << endl << endl;
}

// --- EXAM SNIPPET: POINTER TRACING (From July 2025 Paper) ---
void exam_tracing_2() {
    cout << "--- Exam Tracing Snippet 2 ---" << endl;
    int a[] = {2, 20, 14, 6};
    int n = 18;
    int &v = n; // Reference variable: v is just another name for n
    int *p1, *p2;

    p1 = a;      // p1 -> a[0] (2)
    p2 = &n;     // p2 -> n (18)
    *(p1 + 3) = *p1 * (*p2 + 1); // a[3] = 2 * (18 + 1) = 38
    *p2 = *(p1 + 2) * 3;         // n = 14 * 3 = 42
    p1[1] = a[0] * 4;            // a[1] = 2 * 4 = 8
    *p2 = v / 3;                 // n = 42 / 3 = 14 (v is n)

    // Output tracing: *(p1+i) - v
    // a = {2, 8, 14, 38}, v = 14
    for (int i = 3; i >= 0; i--) {
        cout << *(p1 + i) - v << " ";
        // i=3: 38 - 14 = 24
        // i=2: 14 - 14 = 0
        // i=1: 8 - 14 = -6
        // i=0: 2 - 14 = -12
    }
    cout << endl << endl;
}

int main() {
    // Basic Pointer usage
    int x = 10;
    int *p = &x;
    cout << "Value of x: " << x << endl;
    cout << "Value via pointer: " << *p << endl;
    
    // Dynamic Allocation
    int *dynamicArray = new int[5];
    for(int i=0; i<5; i++) dynamicArray[i] = i * 10;
    delete[] dynamicArray;

    exam_tracing_1();
    exam_tracing_2();

    return 0;
}
