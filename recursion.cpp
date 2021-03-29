#include<iostream>
#include<stack>
#include<bits/stdc++.h>
using namespace std;

int fact(int n)
{
    if(n==1 || n==0)
    {
        return 1;
    }
    return n*fact(n-1);
}

int fib(int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }
    return fib(n-1)+fib(n-2);
}

bool issorted(int a[],int n)
{
    if(n==1)
    {
        return 1;
    }
    return (a[0]<a[1] && issorted(a+1,n-1));
}

void decreasingorder(int n)
{
    if(n==0)
    {
        return;
    }
    cout<<n<<" ";
    decreasingorder(n-1);
}
int firstindex(int a[],int n,int i,int key)
{   
    if(i==n)
    {
        return -1;
    }
    if(a[i]==key)
    {
        return i;
    }
    return firstindex(a,n,i+1,key);
}

void reverse(string s)
{
    stack<char> st;
    int i=0;
    while(s[i]!='\0')
    {
        st.push(s[i]);
        i++;
    }
    while (!st.empty())
    {
        char m=st.top();
        st.pop();
        cout<<m;

    }
    cout<<endl;
}
void rreverse(string s)
{
    if(s.length()==0)
    {
        return;
    }
    rreverse(s.substr(1));
    cout<<s[0];
}
string strreverse(string s)
{
    if(s.length()==1)
    {
        return s;
    }
    return strreverse(s.substr(1))+s[0];
}
void replacePI(string s)
{
    if(s.length()==0)
    {
        return;
    }
    if(s[0]=='p' && s[1]=='i')
    {
        cout<<"3.14";
        replacePI(s.substr(2));  
    }
    else{
        cout<<s[0];
        replacePI(s.substr(1));
    }
}

string removeDUP(string s)
{
    if(s.length()==0)
    {
        return "";
    }

    char ch=s[0];
    string s1=removeDUP(s.substr(1));
    if(ch==s1[0])
    {
        return s1;
    }
    return (ch+s1);
}

string moveAllx(string s)
{
    //axxbdxcefxhix
    if(s.length()==0)
    {
        return "";
    }

    char ch=s[0];
    string ans=moveAllx(s.substr(1));
    if(ch=='x')
    {
        return ans+ch;
    }
    else{
        return ch+ans;
    }
}

void printAllsubsequences(string s,string ans)
{
    if(s.length()==0)
    {
        cout<<ans<<endl;
        return;
    }
    
    char ch=s[0];
    string ros=s.substr(1);
    printAllsubsequences(ros,ans);
    printAllsubsequences(ros,ans+ch);
}
void subsequence(string s,string ans)
{
    if(s.length()==0)
    {
        cout<<ans<<endl;
        return;
    }
    char ch=s[0];
    int ascii=s[0];
    string ros=s.substr(1);
    subsequence(ros,ans);
    subsequence(ros,ans+ch);
    subsequence(ros,ans+to_string(ascii));
}

int main()
{
    cout<<fact(4)<<endl;
    cout<<fib(4)<<endl;
    int a[]={1,2,3,4,559,2,59};
    cout<<issorted(a,6)<<endl;
    decreasingorder(9);
    cout<<endl<<firstindex(a,7,0,2)<<endl;
    rreverse("vishal");
    cout<<endl;
    cout<<strreverse("vishaldhole")<<endl;
    replacePI("pippppiiii");
    cout<<endl<<removeDUP("")<<endl;
    cout<<moveAllx("axxbdxcefxhix")<<endl;
    printAllsubsequences("ABC","");
    string name="vishall";
    transform(name.begin(),name.end(),name.begin(),::toupper);
    cout<<name<<endl;
    transform(name.begin(),name.end(),name.begin(),::tolower);
    cout<<name<<endl;
    subsequence("AB","");
}