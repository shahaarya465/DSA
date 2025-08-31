#include <iostream>
using namespace std;
int main()
{
    int x,sum=0;
    cout<<"Enter the no. of elements of array: ";
    cin>>x;
    int a[x];
    for(int i=0;i<x;i++)
    {
        cin>>a[i];
         sum=sum+a[i];
    }
    for(int j=0;j<x;j++)
    {
        cout<<a[j]<<" ";
    }
            cout<<endl<<"SUM: "<<sum;
    return 0;
}
