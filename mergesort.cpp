#include<iostream>
#include<vector>
using namespace std;

vector<int> merge(vector<int> left,vector<int> right)
{   
    vector<int> ans(left.size()+right.size(),0);
    int i=0;
    int j=0;
    int k=0;
    while (i<=left.size() && j<right.size())
    {
        if(left[i]<=right[j])
        {
            ans[k++]=left[i++];
        }
        else
        {
            ans[k++]=right[j++];
        }
    }
    while (i<left.size())
    {
        ans[k++]=left[i++];
    }
    while (j<right.size())
    {
        ans[k++]=right[j++];
    }
    
    
    return ans;
}

vector<int> mergeSort(vector<int> v)
{   
    if (v.size()<=1)
    {
        return v;
    }
    
    int mid=v.size()/2;
    vector<int> left(v.begin(),v.begin()+mid);
    vector<int> right(v.begin()+mid,v.end());
    return merge(mergeSort(left),mergeSort(right));
}

int main()
{
    vector<int>v={8,4,2,1,455,67,56,87,8,673,2,23,4,4,234335,454,65,6,5};
    vector<int> ans=mergeSort(v);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    
}