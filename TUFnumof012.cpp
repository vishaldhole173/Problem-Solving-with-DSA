#include<iostream>
#include<algorithm>
using namespace std;
void sortarray(int a[],int size)
{
    int zeros=0,ones=0,twos=0;
    for (int i = 0; i < size; i++)
    {
        if(a[i]==0) zeros++;
        else if(a[i]==1) ones++;
        else twos++;
    }
    int i=0;
    while (i<size)
    {
       while(i<zeros)
       {
           a[i++]=0;
       }
       while(i<(ones+zeros))
       {
           a[i++]=1;
       }
       while(i<(twos+ones+zeros))
       {
           a[i++]=2;
       }
        
    }
    
}
void optimal(int a[],int size)
{
    int low=0,mid=0,high=size-1;
    while (mid<=high)
    {
        switch (a[mid])
        {
        case 0:
            swap(a[low++],a[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(a[mid],a[high--]);
            break;
        default:
            break;
        }
    }
    
}
void optimall(int a[],int size)
{
    int low=0,mid=0,high=size-1;
    while(mid<=high)
    {
        if(a[mid]==0)
        {
            swap(a[mid++],a[low++]);
        }
        else if (a[mid]==1)
        {
            mid++;
        }
        else if (a[mid]==2)
        {
            swap(a[mid],a[high--]);
        }
        
    }
}
int main()
{
    int a[]={0,1,1,0,1,2,1,2,0,0,0,1};
    //sortarray(a,12);
    optimal(a,12);
    for (int i = 0; i < 12; i++)
    {
        cout<<a[i]<<"\t";
    }
    
}