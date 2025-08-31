// Selection Sort Algorithm - Sort array by repeatedly finding minimum element and placing it at beginning

#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    int i, j, min_index,count=0;

    for (i = 0; i < n-1; i++) {
        min_index = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_index])
                {
                min_index = j;
                count++;
                }
        swap(arr[min_index], arr[i]);
    }
    cout<<"No. of swaps: "<<count<<endl;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    selectionSort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}