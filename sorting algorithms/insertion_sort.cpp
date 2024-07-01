// Best-case time complexity: O(n)
// Worst-case time complexity: O(n²)
// In-place sorting algorithm
// Space complexity: O(1)

#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(vector<int>& arr) {
    int n = arr.size();

    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int hole = i-1;

        while(hole >= 0 && key < arr[hole]) {
            arr[hole+1] = arr[hole];
            hole--;
        }

        arr[hole + 1] = key;
    }
}

void print_array(const vector<int>& arr) {
    for(int num: arr)
        cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6};

    cout << "Original Array: ";
    print_array(arr);

    insertion_sort(arr);
    cout << "Sorted Array: ";
    print_array(arr);

    return 0;
}