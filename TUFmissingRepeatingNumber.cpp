#include<iostream>
using namespace std;
void missingRepeating(int nums[],int size)
{
    int ans[size]={0};
    for (int i = 0; i < size; i++)
    {
        ans[nums[i]]+=1;
    }
    for (int i = 1; i < size; i++)
    {
        if(ans[nums[i]]==0) cout<<"missing: "<<nums[i]<<endl;
        else if(ans[nums[i]]>1) cout<<"repeating: "<<nums[i]<<endl;
    }
    
}
int missing(int arr[],int N)
{
    int xorr=0;
    int a=0;
    for (int i = 1; i <= N; i++)
    {
        xorr=xorr^i;
    }
    for (int i = 0; i < 4; i++)
    {
        a=a^arr[i];
    }
    return a^xorr;
}
int main()
{
    int nums[]={4,3,6,2,1,1};
    int size=sizeof(nums)/sizeof(nums[0]);
    missingRepeating(nums,size);
    int arr[]={3,2,5,1};
    cout<<"missed number in arr: "<<missing(arr,5)<<endl;
}