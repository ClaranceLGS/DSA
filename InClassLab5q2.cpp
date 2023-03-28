#include <iostream>
#include <iomanip>
using namespace std;

//partition the array and return the index of the pivot element
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // select the last element as pivot
    int i = low - 1; // index of smaller element

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++; 
            swap(arr[i], arr[j]); 
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// recursive quicksort function
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // partition the array
        quicksort(arr, low, pi - 1); // sort the left subarray
        quicksort(arr, pi + 1, high); // sort the right subarray
    }
}

double findmedian(int arr[], int n) {
    quicksort(arr, 0, n-1); // call quicksort to sort the array
    if (n % 2 == 0)
        return (double)(arr[n/2] + arr[n/2 - 1])/2;
    else
        return (double)arr[n/2];
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];

    // take an input stream of n integers
    cout << "Enter the elements of the array: "; 
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

/*
    // create random array of n integers
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 101 - 50; // generate a random number between -50 and 50
    }

    // print the random array
    cout << "The random array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
*/

    for (int i = 0; i < n; i++) {
        double median = findmedian(arr, i+1); // call findmedian() for subarray of size i+1

        cout << "Sorted :" << " ";

        for (int j = 0; j <= i; j++) {
            cout << arr[j] << " ";
        }
        
        cout << endl;

        cout << "Median : " << fixed << setprecision(1) << median << endl; 
    }
  return 0;
}