#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> twosum(vector<int> &nums,int target)
{
    
    vector<int> ans;
    unordered_map<int,int> m;

    for (int i = 0; i < nums.size(); i++)
    {
        if(m.find(target-nums[i])!=m.end())
        {
            
            ans.push_back(m[target-nums[i]]);
            ans.push_back(i);
            return ans;
        }
        m[nums[i]]=i;
    }
    
   
   
    return ans;
}

int main()
{
    vector<int> nums={3,2,4};
    vector<int> result=twosum(nums,6);
    for(auto i:result)
    {
        cout<<i<<" ";
    }
}