#include<bits/stdc++.h>
using namespace std;

int minjumps(int a[],int n)
{
    int step=a[0];
    int jumps=1;
    int maxReach=a[0];

    if(a[0]==0)
    {
        return -1;
    }   
    else if (n==1)
    {
        return 1;
    }
    else
    {
        for (int i = 1; i < n; i++)
        {
            if(i==n-1)
            {
                return jumps;
            }
            maxReach=max(maxReach,a[i]+i);
            step--;
            if(step==0)
            {
                jumps++;
                if(i>=maxReach)
                {
                    return -1;
                }
                step=maxReach-i;
            }
        }
        
    }
    
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cout<<minjumps(a,n);
}