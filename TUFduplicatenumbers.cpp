#include<iostream>
#include<vector>
using namespace std;
int duplicate(vector<int> &nums)
{
    int slow=nums[0];
    int fast=nums[0];
    do{
        slow=nums[slow];
        fast=nums[nums[fast]];
    }while(slow!=fast);
    fast=nums[0];
    while (fast!=slow)
    {
       slow=nums[slow];
       fast=nums[fast];
    }
    return fast;

}
int main()
{
    vector<int> nums={2,5,9,6,9,3,8,9,7,1};
    cout<<duplicate(nums)<<endl;
}