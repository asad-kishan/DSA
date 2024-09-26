#include <iostream>
#include <vector>
using namespace std;

// // Insertion Sort function
void insertionSort(vector<int>& arr) {
    int n = arr.size();

    for(int i = 1; i < n; i++) {   
        int key = arr[i]; // Element to be inserted in the right position in the sorted part
        int j = i - 1;

        // Move elements of sorted part that are greater than key one position to right
        while(j >= 0 && key < arr[j]) {
            arr[j+1] = arr[j];
            j--;
        }

        // Insert the key in correct position
        arr[j+1] = key;
    }
}

// Insertion Sort function (straight forward approach)
// void insertionSort(vector<int>& arr) {
//     int n = arr.size();

//     for(int i = 1; i < n; i++) {       
//         for(int j = i; j > 0; j--) {
//             if(arr[j] < arr[j-1]) {
//                 swap(arr[j], arr[j-1]);
//             } else {
//                 break;
//             }
//         }
//     }
// }

// Function to print the array
void printArray(const vector<int>& arr) {
    for(auto num: arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6};

    cout << "Unsorted Array: ";
    printArray(arr);

    insertionSort(arr);
    cout << "Sorted Array: ";
    printArray(arr);

    return 0;
}

