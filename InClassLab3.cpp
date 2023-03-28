#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void optimizedBubbleSort(int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        int n = rand() % 15001 + 500;
        int arr1[n], arr2[n], arr3[n], arr4[n];
        for (int j = 0; j < n; j++) {
            int num = rand() % 1000;
            arr1[j] = num;
            arr2[j] = num;
            arr3[j] = num;
            arr4[j] = num;
        }
        auto start = high_resolution_clock::now();
        insertionSort(arr1, n);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        cout << "Time taken to sort array " << i + 1 << " of length " << n << " using insertion sort is " << duration.count() << " milliseconds." << endl;

        start = high_resolution_clock::now();
        bubbleSort(arr2, n);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        cout << "Time taken to sort array " << i + 1 << " of length " << n << " using bubble sort is " << duration.count() << " milliseconds." << endl;

        start = high_resolution_clock::now();
        optimizedBubbleSort(arr3, n);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        cout << "Time taken to sort array " << i + 1 << " of length " << n << " using optimized bubble sort is " << duration.count() << " milliseconds." << endl;

        start = high_resolution_clock::now();
        selectionSort(arr4, n);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        cout << "Time taken to sort array " << i + 1 << " of length " << n << " using selection sort is " << duration.count() << " milliseconds." << endl;

    }
    return 0;
}

