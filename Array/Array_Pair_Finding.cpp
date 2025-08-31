// Array Pair Finding - Check if array elements can form pairs whose sum is divisible by k

#include <iostream>
using namespace std;
bool canPair(int[], int, int);
int main()
{
    int n, k;
    cout << "Enter the No of Elements : ";
    cin >> n;
    cout << "Enter the Value of K : ";
    cin >> k;
    int arr[n];
    cout << "Enter the Elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    canPair(arr, n, k);
}
bool canPair(int arr[], int n, int k)
{
    int check[n], count = 0;
    if (n % 2 != 0)
    {
        cout << "Array should have an even number of elements" << endl;
        return false;
    }
    for (int i = 0; i < n; i++)
    {
        check[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (((arr[i] + arr[j]) % k == 0) && check[i] != 1 && check[j] != 1)
            {
                cout << "(" << arr[i] << " , " << arr[j] << ")" << endl;
                check[i] = 1;
                check[j] = 1;
                count++;
            }
        }
    }
    if (count == 0)
    {
        cout << "No Pair Found" << endl;
        return false;
    }
    else
    {
        cout << "Total Number of Pair: " << count << endl;
        if (n / 2 == count)
            cout << "This is a Complete Perfect Pair" << endl;
        return true;
    }
}
