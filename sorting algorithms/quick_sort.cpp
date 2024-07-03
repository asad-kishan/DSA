// Best-case time complexity: O(nlogn)
// Worst-case time complexity: O(n²)
// In-place sorting algorithm
// Best case space complexity: O(logn)
// Best case space complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[right];
    int pivotIdx = left;

    for(int i = left; i < right; i++) {
        if(arr[i] <= pivot)
            swap(arr[i], arr[pivotIdx++]);
    }
    swap(arr[pivotIdx], arr[right]);

    return pivotIdx;
}

void quick_sort(vector<int>& arr, int left, int right) {
    if(left < right) {
        int pivotIdx = partition(arr, left, right);

        quick_sort(arr, left, pivotIdx - 1);
        quick_sort(arr, pivotIdx + 1, right);
    }
}

void print_array(const vector<int>& arr) {
    for(int num: arr)
        cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();

    cout << "Original Array: ";
    print_array(arr);

    quick_sort(arr, 0, n - 1);
    cout << "Sorted Array: ";
    print_array(arr);

    return 0;
}