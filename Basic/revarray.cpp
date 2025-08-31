#include <iostream>
using namespace std;
int main()
{
    int x;
    cout<<"Enter the no. of elements of array: ";
    cin>>x;
    int arr[x];
    for(int i=0;i<x;i++)
    {
        cin>>arr[i];
    }
    int rev[x];
  for(int i=0;i<x;i++)
    {
        rev[i]=arr[x-1-i];
        cout<<rev[i]<<" ";
         }
    return 0;
}
