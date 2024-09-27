#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; // size of the left half
    int n2 = right - mid;    // size of the right half

    // Temporary arrays to store the values of left and right halves
    vector<int> leftArr(n1), rightArr(n2);

    // Copy data to temporary arrays
    for(int i = 0; i < n1; i++) {
        leftArr[i] = arr[left+i];
    }
    for(int i = 0; i < n2; i++) {
        rightArr[i] = arr[mid+1+i];
    }

    // Merge the two halves back into original array
    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2) {
        if(leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    // Copy remaining values of leftArr (if any)
    while(i < n1) {
        arr[k++] = leftArr[i++];
    }
    // Copy remaining values of rightArr (if any)
    while(j < n2) {
        arr[k++] = rightArr[j++];
    }
}

// Merge Sort function
void mergeSort(vector<int>& arr, int left, int right) {
    if(left < right) {
        int mid = left + (right - left) /2;

        // Recursively sort left and right halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);

        // Merge the two sorted halves
        merge(arr, left, mid, right);
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
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Unsorted Array: ";
    printArray(arr);

    mergeSort(arr, 0, arr.size()-1);
    cout << "Sorted Array: ";
    printArray(arr);

    return 0;
}