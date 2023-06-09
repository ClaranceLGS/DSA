#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <stack>
using namespace std;
using namespace std::chrono;

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
// swap function
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// quicksort without recursion
 void nonrecquicksort(int arr[], int left, int right) {
    stack<int> st; //stack to keep track of the partitions to be sorted
    st.push(right);
    st.push(left);

    while (!st.empty()) {
        left = st.top();
        st.pop();
        right = st.top();
        st.pop();

        int pivot = arr[(left + right) / 2];
        int i = left, j = right;

        while (i <= j) {
            while (arr[i] < pivot) {
                i++;
            }

            while (arr[j] > pivot) {
                j--;
            }

            if (i <= j) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        if (left < j) {
            st.push(j);
            st.push(left);
        }

        if (i < right) {
            st.push(right);
            st.push(i);
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
        quicksort(arr1, 0, n-1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Time taken to sort array " << i + 1 << " of length " << n << " using quicksort is " << duration.count() << " microseconds." << endl;

        start = high_resolution_clock::now();
        nonrecquicksort(arr2, 0, n-1);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        cout << "Time taken to sort array " << i + 1 << " of length " << n << " using non recursive quick sort is " << duration.count() << " microseconds." << endl;
    }
    return 0;
}