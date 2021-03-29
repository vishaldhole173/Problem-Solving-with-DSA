#include<iostream>
using namespace std;

bool isSafe(int x,int y,int n,int **arr)
{
    if(x<n && y<n && arr[x][y]==1)
    {
        return true;
    }
}

bool ratmaze(int x,int y,int n,int **arr,int **solArr)
{   
    if(x==n-1 && y==n-1)
    {
        solArr[x][y]=1;
        return true;
    }

    if(isSafe(x,y,n,arr))
    {
        solArr[x][y]=1;
        if(ratmaze(x+1,y,n,arr,solArr))
        {
            return true;
        }
        if(ratmaze(x,y+1,n,arr,solArr))
        {
            return true;
        }
        solArr[x][y]=0;  //backtrack
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

    if(ratmaze(0,0,n,arr,solArr))
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