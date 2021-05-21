#include<bits/stdc++.h>
using namespace std;
vector<string> v;
void generate(string s,int open,int close)
{
    if(open==0 && close==0)
    {
        v.push_back(s);
        return;
    }
    if(open>0)
    {
        s.push_back('(');
        generate(s,open-1,close);
        //backtracking
        s.pop_back();
    }
    if(close>open && close>0)
    {
        s.push_back(')');
        generate(s,open,close-1);
        //backtracking
        s.pop_back();
    }
}
int main()
{   
    int l=1e9+7;
    int n;
    cin>>n;
    generate("",n,n);
    for(auto x:v)
    {
        cout<<x<<endl;
    }
    cout<<l<<endl;
}