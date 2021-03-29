#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int uniquePaths(int m,int n)
{
    int N=m+n-2;
    int r=m-1;
    double res=1;
    for(int i=1;i<=r;i++)
    {
        res=res*(N-r+i)/i;
    }
    return (int)res;
}
int uniquePathsRecursive(int i,int j,int m,int n)
{
    //Time = exponential because we try all possible combinations
    //Space = exponential because we use stack space in recursion
    if(i==(n-1) && j==(m-1)) return 1;
    else if(i>=n || j>=m) return 0;
    else return uniquePathsRecursive(i+1,j,m,n) + uniquePathsRecursive(i,j+1,m,n);

}
int dpApproach(int i,int j,int m,int n,vector<vector<int>> &dp)
{   
    //Time & Space = O(n*m)
    if(i==(n-1) && j==(m-1)) return 1;
    else if(i>=n || j>=m) return 0;
    else if (dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    else return uniquePathsRecursive(i+1,j,m,n) + uniquePathsRecursive(i,j+1,m,n);

}
int optimal(int m,int n)
{
    int N=m+n-2;
    int r=m-1;
    double res=1;
    for (int i = 1; i <= r; i++)
    {
        res=res*(N-r+i)/i;
    }
    return res;
}
int main()
{   
    vector<vector<int>> dp={{-1,-1,-1},{-1,-1,-1}};
    
    cout<<uniquePaths(3,2)<<endl<<uniquePathsRecursive(0,0,2,3)<<endl<<dpApproach(0,0,2,3,dp)<<endl<<optimal(3,2)<<endl;
}