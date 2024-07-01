// Best-case time complexity: O(n)
// Worst-case time complexity: O(n²)
// In-place sorting algorithm
// Space complexity: O(1)

#include <iostream>
#include<vector>

using namespace std;

void bubble_sort(vector<int>& arr) {
    int n = arr.size();
    bool swaped = false;

    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j+1] < arr[j]) {
                swap(arr[j+1], arr[j]);
                swaped = true;
            }
        }

        if(!swaped)
            break;
    }
}

void print_array(const vector<int>& arr) {
    for(int num : arr)
        cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};

    cout << "Original Array: ";
    print_array(arr);

    bubble_sort(arr);
    cout << "Sorted Array: ";
    print_array(arr);

    return 0;
}
