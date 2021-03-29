// circular sum 
#include<iostream>
#include<climits>
using namespace std;

int kadane(int array[],int n)
{
    int maxsum=INT_MIN;
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum+=array[i];
        if(sum<0)
        {
            sum=0;
        }
        maxsum=max(maxsum,sum);
    }
    return maxsum;
}
int main()
{
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }

    int nonwrapsum=kadane(array,n);
    int totalsum=0;
    for (int i = 0; i < n; i++)
    {
        totalsum+=array[i];
        array[i]=-array[i];
    }
    int wrapsum=totalsum+kadane(array,n);
    cout<<max(wrapsum,nonwrapsum)<<endl;
}