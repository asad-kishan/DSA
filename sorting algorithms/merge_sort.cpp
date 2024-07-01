// Best-case time complexity: O(nlogn)
// Worst-case time complexity: O(nlogn)
// Space complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for(int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2) {
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while(i < n1)
        arr[k++] = L[i++];
    
    while(j < n2)
        arr[k++] = R[j++];
}

void merge_sort(vector<int>& arr, int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);

        merge(arr, left, mid, right);
    }
}

void print_array(const vector<int>& arr) {
    for(int num: arr) 
        cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();

    cout << "Original Array: ";
    print_array(arr);

    merge_sort(arr, 0, n-1);
    cout << "Sorted Array: ";
    print_array(arr);

    return 0;
}