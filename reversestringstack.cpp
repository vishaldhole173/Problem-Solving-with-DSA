#include<iostream>
#include<stack>
using namespace std;

string reverse(string s)
{
    stack<char> st;
    int i=0;
    while (s[i]!='\0')
    {
        st.push(s[i]);
        i++;
    }
    char ans[s.size()];
    int j=0;
    while (!st.empty())
    {
        ans[j]=st.top();
        st.pop();
        j++;
    }
    return ans;
}
string reverseGFG(string s)
{
    string ans="";
    for (int j = (s.size()-1); j >= 0; j--)
    {
        ans+=s[j];
    }
    return ans;
}
int main()
{
    string s;
    getline(cin,s);
    
    cout<<reverseGFG(s)<<endl;
}