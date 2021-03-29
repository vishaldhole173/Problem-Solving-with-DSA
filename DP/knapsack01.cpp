#include<iostream>
using namespace std;

int knapsack(int wt[],int val[],int w,int n)
{
    if(w==0 || n==0) return 0;
    if(w>=wt[n-1])
    {
        return max(val[n-1]+knapsack(wt,val,w-val[n-1],n-1), knapsack(wt,val,w,n-1));
    }
    else if(w<wt[n-1]){
        return knapsack(wt,val,w,n-1);
    }
}

int main()
{
    int wt[]={1,3,4,5};
    int val[]={1,4,5,7};
    int n=4;
    int w=7;
    cout<<knapsack(wt,val,w,n)<<endl;
}