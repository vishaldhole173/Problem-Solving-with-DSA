#include<bits/stdc++.h> 
#include<iostream>
using namespace std;
void rotateArray(int a[],int start,int end);
int main()
{
    int a[11]={1,2,3,4,5,7,5,3,4,32,44};  
    int size=11;
    int d=5;
    rotateArray(a,0,d-1);
    rotateArray(a,d,size-1);
    rotateArray(a,0,size-1);
    for (int i = 0; i < size; i++)
    {
        cout<<a[i]<<"\t";
    }
    
}

void rotateArray(int a[],int start,int end)  // Time O(n) Space O(1)
{   
    while (start<end)
    {
        int temp;
        temp=a[start];
        a[start]=a[end];
        a[end]=temp;
        start++;
        end--;
    }
    
}