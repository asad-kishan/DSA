#include <bits/stdc++.h>
using namespace std;

// Place elements less than the pivot to the left and greater than the pivot to the right of the pivot 
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // last element chosen as the pivot
    int i = low - 1;       // Index of smaller element

    // Place elements less than the pivot to the left
    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            swap(arr[++i], arr[j]);
        }
    }

    // Place the pivot just after the smaller elements
    swap(arr[++i], arr[high]);

    return i; // return the pivot's position
}

// Quick Sort function
void quickSort(vector<int>& arr, int low, int high) {
    if(low < high) {
        int pivotIdx = partition(arr, low, high);

        // Recursiveley sort elements before and after the pivot
        quickSort(arr, low, pivotIdx-1);
        quickSort(arr, pivotIdx+1, high);
    }
}

// Function to print the array
void printArray(const vector<int>& arr) {
    for(auto num: arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {10, 7, 8, 9 , 1, 5};

    cout << "Unsorted Array: ";
    printArray(arr);

    quickSort(arr, 0, arr.size()-1);
    cout << "Sorted Array: ";
    printArray(arr);

    return 0;
}