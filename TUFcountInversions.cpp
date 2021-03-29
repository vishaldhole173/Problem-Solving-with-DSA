#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int merge(int a[],int temp[],int left,int mid,int right)
{
    int i=left;
    int j=mid;
    int k=left;
    int inv_count=0;
    while (i<=(mid-1) && j<=(right))
    {
        if(a[i]<=a[j])
        {
            temp[k++]=a[i++];
        }
        else{
            temp[k++]=a[j++];
            inv_count+=(mid-i);
        }
    }
    while (i<=mid-1)
    {
        temp[k++]=a[i++];
    }
    while (j<=right)
    {
        temp[k++]=a[j++];
    }
    for (int i = 0; i <= right; i++)
    {
        a[i]=temp[i];
    }
    return inv_count;
    
}
int mergeSort(int a[],int temp[],int left,int right)
{
    int mid,inv_count=0;
    if(right>left)
    {
        mid=(left+right)/2;

        inv_count+=mergeSort(a,temp,left,mid);
        inv_count+=mergeSort(a,temp,mid+1,right);
        inv_count+=merge(a,temp,left,mid+1,right);
    }
    return inv_count;
}
int main()
{
    int a[]={8,4,2,1}; 
    int n=sizeof(a)/sizeof(a[0]);
    int temp[n];
    int ans=mergeSort(a,temp,0,n-1);
    cout<<ans<<endl;
}