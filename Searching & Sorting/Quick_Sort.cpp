// Quick Sort Implementation

#include <iostream>
#include <cstdlib>
using namespace std;

int quick_operations = 0;


int partition(int arr[], int low, int high, string pivotType) {
    int pivotIndex;
    
    if (pivotType == "Best") {
        pivotIndex = low + (high - low) / 2;
    } 
    else if (pivotType == "Average") {
        pivotIndex = low + rand() % (high - low + 1);
    } 
    else { 
        pivotIndex = high;
    }

    swap(arr[pivotIndex], arr[high]);
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        quick_operations++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            quick_operations++;
        }
    }
    swap(arr[i + 1], arr[high]);
    quick_operations++;
    return (i + 1);
}

void quickSort(int arr[], int low, int high, string pivotType) {
    if (low < high) {
        int pi = partition(arr, low, high, pivotType);
        quickSort(arr, low, pi - 1, pivotType);
        quickSort(arr, pi + 1, high, pivotType);
    }
}

void runQuickSort(int arr[], int n, string caseType, string pivotType) {
    quick_operations = 0;
    quickSort(arr, 0, n - 1, pivotType);
    cout << "Input Size: " << n << " | Case: " << caseType << " | Operations: " << quick_operations << endl;
}

int main() {
    int sizes[] = {5, 10, 15, 20};

    for (int s = 0; s < 4; s++) {
        int n = sizes[s];
        int bestCase[n], avgCase[n], worstCase[n];

        for (int i = 0; i < n; i++) bestCase[i] = i;
        runQuickSort(bestCase, n, "Best", "Best");

        for (int i = 0; i < n; i++) avgCase[i] = rand() % 100;
        runQuickSort(avgCase, n, "Average", "Average");

        for (int i = 0; i < n; i++) worstCase[i] = n - i;
        runQuickSort(worstCase, n, "Worst", "Worst");
    }
    return 0;
}