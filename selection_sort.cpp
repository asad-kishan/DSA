#include <bits/stdc++.h>
using namespace std;

// Selection Sort function
void selectionSort(vector<int>& arr) {
    int n = arr.size();

    // Outer loop to move the boundary between sorted and unsorted part
    for(int i = 0; i < n-1; i++) {
        int minIdx = i; // Assume the minimum is the first one of unsorted part

        // Find the minimum in the unsorted part
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }

        // swap the minimum element with the first unsorted element
        swap(arr[minIdx], arr[i]);
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
    vector<int> arr = {64, 25, 12, 22, 11};

    cout << "Unsorted Array: ";
    printArray(arr);

    selectionSort(arr);
    cout << "Sorted Array: ";
    printArray(arr);

    return 0;
}