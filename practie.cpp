#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    string s="abergrgrwwwwwgvfvcadrkjvtwivmimwvd";
    int freq[26];
    int mx=0;
    for (int i = 0; i < 26; i++)
    {
        freq[i]=0;
    }
    for (int i = 0; i < s.size(); i++)
    {
        freq[s[i]-97]++;
    }
    
    for (int i = 0; i < 26; i++)
    {
        mx=max(mx,freq[i]);
    }
    cout<<mx<<endl;
    transform(s.begin(),s.end(),s.begin(),::toupper);
    cout<<s;
}