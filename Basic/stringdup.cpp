#include<iostream>
using namespace std;
int main()
{
    char s[50],x;
    int count=0;
    cout<<"Enter string1: ";
    gets(s);
    cout<<s<<endl;
    cout<<"Enter the character to be duplicated: ";
    cin>>x;
    for(int i=0;i<50;i++)
    {
        if(s[i]==x)
        count++;
    }
cout<<"Number of times "<<x<<" occurs: "<<count;
    return 0;
}

