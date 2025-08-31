// Array Correction Algorithm - Fix a sorted array by correcting two swapped elements

#include <iostream>
void fixSwappedElements(int arr[], int n) {
    int first = -1, second = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            if (first == -1) {
                first = i;
            } else {
                second = i + 1;
            }
        }
    }
    if (second == -1) {
        second = first + 1;
    }
    std::swap(arr[first], arr[second]);
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
int main() {
    int n;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;
    int arr[n];
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    std::cout << "Original array: ";
    printArray(arr, n);
    fixSwappedElements(arr, n);
    std::cout << "Fixed array: ";
    printArray(arr, n);
    return 0;
}
