#include <bits/stdc++.h>
using namespace std;

// Bubble Sort function
void bubbleSort(vector<int>& arr) {
    int n = arr.size();

    for(int i = 0; i < n-1; i++) {
        bool swapped = false;

        // Compare adjacent elements in unsorted part
        for(int j = 1; j < n-i; j++) {
            if(arr[j] < arr[j-1]) {
                swap(arr[j], arr[j-1]); // Swap if they are in wrong order
                swapped = true;
            }
        }

        // If no two elements were swapped, the array is already sorted
        if(!swapped) {
            break;
        }
    }
}

// Function to print the array
void printArray(const vector<int>& arr) {
    for(auto num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    cout << "Unsorted Array: ";
    printArray(arr);

    bubbleSort(arr);
    cout << "Sorted Array: ";
    printArray(arr);

    return 0;
}