int z=7;
#include<iostream>
#include<vector>
int y=10;
using namespace std;
int x=10;
void bubblesort(vector<int> a)
{
    vector<int> v=a;
    //bubble sort
    int counter=v.size()-1;
    for (int i = 0; i <= counter; i++)
    {
        for(int j=0;j<v.size()-i-1;j++)
        {
            if(v[j]>v[j+1])
            {
                v[j]=v[j]^v[j+1];
                v[j+1]=v[j]^v[j+1];
                v[j]=v[j]^v[j+1];
            }
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }    
}

void selectionsort(vector<int> a)
{
    vector<int> v=a;
    
}

int unique(int a[],int n)
{
    int xorsum=0;                   
    for (int i = 0; i < n; i++)
    {
        xorsum=xorsum^a[i];
    }
    return xorsum;
}
int main()
{
    int a[]={1,2,3,4,1,2,3};
    cout<<unique(a,7)<<endl;
    vector<int> arr={324,45,6,56,67,8,7897,990,8,44545};
    bubblesort(arr);
}