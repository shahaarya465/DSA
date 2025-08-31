#include <iostream>
using namespace std;
int main()
{
    int a,b;
    cout<<"Enter rows: ";
    cin>>a;
     cout<<"Enter columns: ";
    cin>>b;
    int x[a][b],y[a][b],sum[a][b];

    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            cin>>x[i][j];
        }
    }
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            cin>>y[i][j];
        }
    }
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            sum[i][j]=x[i][j]+y[i][j];
        }
    }
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            cout<<sum[i][j]<<" ";
        }
        cout<<endl;
    }
}
