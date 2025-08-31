// String Processing - Find the length of the longest word in a string

#include <iostream>
using namespace std;

int longestWordLength(string str)
{
    int n = str.length();
    int maxLength = 0, current = 0;

    for (int i = 0; i < n; i++)
    {
        if (str[i] != ' ' && str[i] != '.')
            current++;
        else
        {
            maxLength = max(maxLength, current);
            current = 0;
        }
    }
    return max(maxLength, current);
}
int main()
{
    string s = "There is a banana tree.";
    cout << "The string is: " << s << endl;
    cout << "The length of the longest word in the string is: " << longestWordLength(s) << endl;
    return 0;
}
