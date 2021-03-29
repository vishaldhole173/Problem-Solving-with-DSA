#include<iostream>
#include<climits>
#include<unordered_map>
using namespace std;
int main()
{
    string s="unordered_map o(1)complexity";
    unordered_map<char,int> m;
    int max=INT_MIN;
    char mx;
    for (int i = 0; i < s.length(); i++)
    {
        m[s[i]]++;
    }
    for (int i = 0; i < m.size(); i++)
    {
        if(m[s[i]]>max)
        {
            max=m[s[i]];
            mx=s[i];
        }
    }
    cout<<mx<<" has occured most times i.e. "<<max<<" times"<<endl;
}