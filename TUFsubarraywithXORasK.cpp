#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int subarrayAsK(vector<int> v,int k)
{
    int xorr=0;
    int count=0;
    unordered_map<int,int> m;
    for(auto i:v)
    {
        xorr=xorr^i;
        if(xorr==k)
        {
            count++;
        }
        if(m.find(xorr^k)!=m.end())
        {
            count+=m[xorr^k];
        }
        m[xorr]++;
    }
    return count;
}
int subarrayAsked(vector<int> v,int k)
{
    unordered_map<int,int> m;
    int count=0;
    int xorr=0;
    for (int i = 0; i < v.size(); i++)
    {
        xorr=xorr^v[i];
        if(xorr==k) count++;
        if(m.find(xorr^k)!=m.end())
        {
            count+=m[xorr^k];
        }
        m[xorr]++;
    }
    return count;
}
int main()
{
    vector<int> v={4,2,2,6,4};
    int k=6;
    cout<<subarrayAsK(v,k)<<endl;
    cout<<subarrayAsked(v,k)<<endl;
    return 0;
}