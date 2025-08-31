// Linear Search Algorithm - Search for an element in an unsorted array

#include <iostream>
using namespace std;

int search(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
            return i;
    }
    return -1;
}
int main()
{
    int n, x;
    cout << "Enter the no. of elements of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the element to search: " << endl;
    cin >> x;
    int result = search(arr, n, x);

    if (result == -1)
        cout << "Element not found" << endl;
    else
        cout << result << " is the index of the element " << x << " of the given array." << endl;

    return 0;
}
