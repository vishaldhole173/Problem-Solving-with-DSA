#include<iostream>
using namespace std;

bool issafe(int **arr,int x, int y,int n)
{
    if(x<n && y<n && arr[x][y]==1)
    {
        return true;
    }
    return false;
}

bool ratinmaze(int **arr,int **solArr,int x,int y,int n)
{
    if(x==n-1 && y==n-1)
    {
        solArr[x][y]=1;
        return true;
    }
    if(issafe(arr,x,y,n))
    {
        solArr[x][y]=1;
        if(ratinmaze(arr,solArr,x+1,y,n))   //ratinmaze(arr,solArr,0,0,n)
        {
            return true;
        }
        if(ratinmaze(arr,solArr,x,y+1,n))
        {
            return true;
        }
        solArr[x][y]=0;  //backtracking
        return false;
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
    int **solArr=new int*[n];
    for (int i = 0; i < n; i++)
    {
        solArr[i]=new int[n];
        for (int j = 0; j < n; j++)
        {
            solArr[i][j]=0;
        }
        
    }

    if (ratinmaze(arr,solArr,0,0,n))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout<<solArr[i][j]<<" ";
            }
            cout<<endl;
            
        }
        
    }
    
    
    
}