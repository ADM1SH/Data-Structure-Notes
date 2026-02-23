#include <iostream>
using namespace std;

/* 
   TOPIC 8: SORTING
   ----------------
   1. Selection Sort: Find smallest, swap with first. Repeat for rest.
   2. Merge Sort: Divide and Conquer. Split into halves, sort, and merge.
*/

// --- SELECTION SORT (Descending Order - Feb 2025 style) ---
void selectionSortDescending(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[max_idx]) {
                max_idx = j;
            }
        }
        // Swap
        int temp = a[i];
        a[i] = a[max_idx];
        a[max_idx] = temp;
        
        // Tracing for exam: Print state after each pass
        cout << "Pass " << i + 1 << ": ";
        for(int k=0; k<n; k++) cout << a[k] << " ";
        cout << endl;
    }
}

/* 
   MERGE SORT CONCEPT (July 2025 Q4a)
   Definition: This sorting algorithm uses the concept of divide and conquer. 
   The list is divided into halves/two repeatedly until all the elements becomes individual. 
   Then, compare the two individual elements, place them in the correct order, ascending or 
   descending, and combine. The process is repeated until all the elements are recompiled as a whole.
*/

void merge(int arr[], int l, int m, int r) {
    // Standard merge logic (usually not asked to write fully in exam, 
    // but good for context)
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int arr[] = {30, 20, 10, 50, 40};
    int n = 5;
    
    cout << "Selection Sort (Descending) steps:" << endl;
    selectionSortDescending(arr, n);
    
    return 0;
}
