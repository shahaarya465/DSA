#include <iostream>
using namespace std;
int main()
{
    int x;
    cout<<"Enter no. of elements: ";
    cin>>x;
    char arr[x];
    for(int i=0; i<x; i++)
    {
        cin>>arr[i];
    }
    char rev[x];
    for(int i=0; i<x; i++)
    {
        rev[i]=arr[x-1-i];
        cout<<rev[i];
    }
    return 0;
}
