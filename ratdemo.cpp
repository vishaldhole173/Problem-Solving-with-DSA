#define pi 3.14;
#include<iostream>
using namespace std;

bool issafe(int **arr,int **solarr,int x,int y,int n)
{
    if(arr[x][y]==1 && x<n && y<n)
    {   
        return true;
    }
    return false;
}
bool ratinmaze(int **arr,int **solarr,int x,int y,int n)
{
    if(x==n-1 && y==n-1)
    {   
        solarr[x][y]=1;
        return true;
    }
    if(issafe(arr,solarr,x,y,n))
    {   
        solarr[x][y]=1;
        if(ratinmaze(arr,solarr,x+1,y,n))
        {
            return true;
        }
        if (ratinmaze(arr,solarr,x,y+1,n))
        {
            return true;
        }
        solarr[x][y]=0; //backtracking
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    int **arr=new int*[n];
    for (int i = 0; i < n; i++)
    {
        arr[i]=new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>arr[i][j];
        }
        
    }
    int **solarr=new int*[n];
    for(int i=0;i<n;i++)
    {
        solarr[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            solarr[i][j]=0;
        }
    }

    if (ratinmaze(arr,solarr,0,0,n))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout<<solarr[i][j]<<" ";
            }
            cout<<endl;
        }
        
    }
    
    

}