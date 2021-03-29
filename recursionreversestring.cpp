#include<iostream>
using namespace std;

void reverse(string &s,int i=0)
{   
    int size=s.size();
    if (i==(size/2))
    {
        return;
    }
    
    swap(s[i],s[size-i-1]);
    reverse(s,i+1);
}
int main()
{
    string s;
    getline(cin,s);
    reverse(s);
    cout<<s<<endl;
}