#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(pair<int,int> p1,pair<int,int> p2)
{
    return p1.first<p2.first;
}
int main()
{
    int a[]={10,16,7,14,5,3,12,9};
    vector <pair<int,int>> v;
    for(int i=0;i<(sizeof(a)/sizeof(a[0]));i++)
    {
        v.push_back(make_pair(a[i],i));
    }
    sort(v.begin(),v.end(),compare);
    //0-> 3,5
    for (int i = 0; i < v.size(); i++)
    {
        a[v[i].second]=i;
    }
    
    for (int i = 0; i < v.size(); i++)
    {
        cout<<a[i]<<" ";
    }
    

    return 0;
}