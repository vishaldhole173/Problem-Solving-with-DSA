#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[10]={1,2,3,4,5,6,7,9};
    unordered_map<int,bool> m;
    for (int i = 0; i < 10; i++)
    {
        m[a[i]]=false;
    }
    
    for (int i = 0; i <= 10; i++)
    {
        m[a[i]]=true;
    }
    for (int i = 0; i <= 10; i++)
    {
        if(m[a[i]]==false)
        {
            cout<<m[a[i]];
        }
    }
    
}