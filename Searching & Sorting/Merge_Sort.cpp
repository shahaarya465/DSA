// Merge Sort Implementation

#include <iostream>

using namespace std;

int op = 0;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    op += 2;
    for (int i = 0; i < n1; ++i) {
        L[i] = arr[left + i];
        op += 2;
    }
    for (int i = 0; i < n2; ++i) {
        R[i] = arr[mid + 1 + i];
        op += 2;
    }
    int i = 0, j = 0, k = left;
    op += 3;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
            op += 2;
        } else {
            arr[k] = R[j];
            ++j;
            op += 2;
        }
        ++k;
        op++;
    }
    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
        op += 3;
    }
    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
        op += 3;
    }
}

void mergeSort(int arr[], int left, int right) {
    op += 3;
    if (left < right) {
        int mid = left + (right - left) / 2;
        op += 4;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
        op += 3;
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    mergeSort(arr, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Total number of operations: " << op << endl;
    return 0;
}