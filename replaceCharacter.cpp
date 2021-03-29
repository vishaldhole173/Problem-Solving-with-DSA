#include<iostream>
using namespace std;
int main()
{
    string s="addddddddddaaaaaaadddddddd";
    char c='d';
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]==c)
        {
            s[i]='*';
        }
    }
    cout<<s;
}