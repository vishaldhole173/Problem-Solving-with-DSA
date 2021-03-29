#include<iostream>
#include <stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> v;
    vector<int> w;
    vector<int> ans;
    int x;
    while (cin>>x)
    {
        v.push_back(x);
    }
    cout<<"over"<<endl;
    int m;
    cin>>m;
    for (int i = 0; i <m; i++)
    {
        ans.push_back(v[i]);
    }
    
    cout<<"enter elements of second array"<<endl;
    while (cin>>x)
    {
        w.push_back(x);
    }
    int n;
    cin>>n;
    for (int i = 0; i <m; i++)
    {
        ans.push_back(w[i]);
    }
    
    int d=ans.size()/sizeof(ans[0]);
    sort(ans.begin(),ans.end());
    for(auto a : ans)
    {
        cout<<a<<" ";
    }
    return 0;
    
}