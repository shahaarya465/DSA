// Binary Search Algorithm - Search for an element in a sorted array using divide and conquer

#include <iostream>
using namespace std;
int binarySearch(int arr[], int left, int right, int x)
{
    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] < x)
            left = mid + 1;

        else
            right = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[10];
    cout << "Enter 10 elements: ";
    for (int i = 0; i < 10; i++)
        cin >> arr[i];
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;
    cout << "Enter the element to search: ";
    cin >> x;
    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1)
        cout << "Element is not present in array";
    else
        cout << "Element is present at index " << result;
    return 0;
}