#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;


// Recursive Merge Sort
void merge(int arr[] , int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1], R[n2];
 
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    int i = 0, j = 0, k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int arr[] , int l, int r) {
    if (l >= r)
        return;
 
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
 
    merge(arr, l, m, r);
}

// Iterative Merge Sort
void iterativeMergeSort(int arr[],  int n ) {
   
    for (int currSize = 1; currSize <= n - 1; currSize = 2 * currSize) {
        for (int leftStart = 0; leftStart < n - 1; leftStart += 2 * currSize) {
            int mid = min(leftStart + currSize - 1, n - 1);
            int rightEnd = min(leftStart + 2 * currSize - 1, n - 1);
            merge(arr, leftStart, mid, rightEnd);
        }
    }
}

int main() {
srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        int n = rand() % 15001 + 500;
        int arr1[n], arr2[n];
        for (int j = 0; j < n; j++) {
            int num = rand() % 1000;
            arr1[j] = num;
            arr2[j] = num;
    
        }
        
        auto start = high_resolution_clock::now();
        mergeSort(arr1, 0, n-1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Time taken to sort array " << i + 1 << " of length " << n << " using mergesort is " << duration.count() << " microseconds." << endl;

        start = high_resolution_clock::now();
        iterativeMergeSort(arr2, n);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        cout << "Time taken to sort array " << i + 1 << " of length " << n << " using iterativeMergeSort sort is " << duration.count() << " microseconds." << endl;
    }
    return 0;
}
