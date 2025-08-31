// Matrix Search Algorithm - Search for an element in a 2D matrix using row-wise approach

#include<iostream>
using namespace std;

int main()
{
    int r,c,i,j,k;
    cout<<"Enter number of Rows: "<<endl;
    cin>>r;

    cout<<"Enter number of Columns: "<<endl;
    cin>>c;
    int mat[r][c];
        cout<<"Enter Element you want to search"<<endl;
        cin>>k;
    cout<<"Enter Elements"<<endl;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            cin>>mat[i][j];
        }
    }
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;

    }
int mid=r/2;
if(k>mid)
{
for(i=0;i<mid;i++)
    {
        for(j=0;j<c;j++)
        {
            if(mat[i][j]==k)
            {
            cout<<"["<<i<<"]";
            cout<<"["<<j<<"]";
            }
        }
    }
}
else if(k<mid)
{
for(i=0;i<mid;i++)
    {
        for(j=0;j<c;j++)
        {
            if(mat[i][j]==k)
            {
            cout<<"["<<i<<"]";
            cout<<"["<<j<<"]";
            }
        }
    }
}
else
i=mid;
        for(j=0;j<c;j++)
        {
            if(mat[i][j]==k)
            {
            cout<<"["<<mid<<"]";
            cout<<"["<<j<<"]";
            }
        }

}