#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    string s="vishalbharatdholefromkarad";
    unordered_map<char,int> m;
    for (int i = 0; i < s.length(); i++)
    {
        m[s[i]]++;
    }
    for (int i = 0; i <s.length(); i++)
    {
        if(m[s[i]]>1)
        {
            s[i]='*';
        }
    }
    cout<<s<<endl;
    
}