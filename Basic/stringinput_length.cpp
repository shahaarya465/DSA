#include<iostream>
using namespace std;
int main()
{
    char s[50];
    int count;
    cout<<"Enter string1: ";
    gets(s);
    cout<<s<<endl;
    for(int i=0;s[i]!='\0';i++)
    {
        count++;
    }
cout<<"Length of string: "<<count;
    return 0;
}
