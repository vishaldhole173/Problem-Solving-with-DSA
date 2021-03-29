#include<iostream>
using namespace std;
bool isSubstring(string s,string sub)
{   
    if (s.length()<sub.length())
    {
        return false;
    }
    string x=s.substr(1,s.length());
    string y=s.substr(0,sub.length());
    if (sub==y)
    {
        return true;
    }
        return isSubstring(x,sub);
    
}

int main()
{
    // string s="maharashtra";
    // string sub="maha";
    string s;
    string sub;
    cin>>s;
    cin>>sub;
    cout<<isSubstring(s,sub)<<endl;
}