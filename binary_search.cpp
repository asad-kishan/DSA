#include <iostream>
#include <vector>

using namespace std;

// binary search function
int binarySearch(const vector<int> &arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    int mid;
    while(left <= right) {
        mid = left + (right - left) / 2;

        // check if the target is at the mid
        if(target == arr[mid]) {
            return mid;
        }
        // if the target is greater than mid element, ignore the left half
        if(target > arr[mid]) {
            left = mid + 1;
        }
        // if the target is less than mid element, ignore the right half
        if(target < arr[mid]) {
            right = mid - 1;
        }
    }

    // target element not found in the array
    return -1;
}

int main() {
    vector<int> arr = {2, 3, 4, 10, 40, 50, 70};
    int target = 50;

    int result = binarySearch(arr, target);
    if(result != -1) {
        cout << "The element found at index: " << result << endl;
    } else {
        cout << "The element not found in the array!" << endl;
    }

    return 0;
}