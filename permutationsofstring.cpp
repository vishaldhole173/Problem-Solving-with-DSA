#include<iostream>
using namespace std;

void permutations(string s,string ans)
{
    if(s.length()==0)
    {
        cout<<ans<<endl;
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        char ch=s[i];
        string ros=s.substr(0,i)+s.substr(i+1);
        permutations(ros,ans+ch);
    }
    
}

int countpath(int s,int e)
{
    if(s==e)
    {
        return 1;
    }
    if(s>e)
    {
        return 0;
    }
    int count=0;
    for(int i=1;i<=6;i++)
    {
        count+=countpath(s+i,e);
    }
    return count;
}
int countpathmaze(int n,int i,int j)
{
    if(i==n-1 && j==n-1)
    {
        return 1;
    }
    if(i>=n || j>=n)
    {
        return 0;
    }
    return countpathmaze(n,i+1,j)+countpathmaze(n,i,j+1);
}
//given a board of 2*n tiles & size of tiles 2*1, count the number of ways to tile the given board using these tiles
int tilingWays(int n)
{
    // if(n==0)           // or if(n<=2) return n;
    // {
    //     return 0;
    // }
    // if(n==1)
    // {
    //     return 1;
    // }
    // if(n==2)
    // {
    //     return 2;
    // }
    if(n<=2) return n;
    return tilingWays(n-1)+tilingWays(n-2);
}
int tilingDP(int n)
{
    int cnt[n+1];
    cnt[0]=0;
    cnt[1]=1;
    cnt[2]=2;
    for (int i = 3; i <= n; i++)         //O(n)
    {
        cnt[i]=cnt[i-1]+cnt[i-2];
    }
    return cnt[n];

}

int friendsPairing(int n)
{
    if(n==0 || n==1 || n==2)
    {
        return n;
    }
    return friendsPairing(n-1)+friendsPairing(n-2)*(n-1);
}

int Knapstack(int value[],int wt[],int items,int capacity)
{
    if(items==0 || capacity==0)
    {
        return 0;
    }
    if(wt[items-1]>capacity)
    {
        return Knapstack(value,wt,items-1,capacity);
    }
    return max(Knapstack(value,wt,items-1,capacity-wt[items-1])+value[items-1],Knapstack(value,wt,items-1,capacity));
}

int main()
{
    string s;
    cin>>s;
    permutations(s,"");
    cout<<countpath(0,3)<<endl;
    cout<<countpathmaze(3,0,0)<<endl;
    cout<<tilingWays(4)<<endl;
    cout<<tilingDP(4)<<endl;
    cout<<friendsPairing(4)<<endl;
    int wt[]={10,20,30};
    int value[]={100,50,150};
    int capacity=50;
    cout<<Knapstack(value,wt,3,capacity)<<endl;
}