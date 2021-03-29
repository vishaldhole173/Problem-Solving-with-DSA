#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void sieveprime(int n)
{
    int prime[100]={0};
    for (int i = 2; i <=n; i++)
    {
        if(prime[i]==0)
        {
            for(int k=i*i;k<=n;k+=i)
            {
                prime[k]=1;
            }
        }
    }
    for (int i = 2; i <=n; i++)
    {
        if(prime[i]==0)
        {
            cout<<i<<" ";
        }
    }
    cout<<endl;
}
int gcd(int a,int b)
{   
    while(b!=0)
    {
        int rem=a%b;
         a=b;
         b=rem;
    }
    return a;
}
int main()

{
    int n;
    cin>>n;
    sieveprime(n);
    cout<<gcd(18,12);
    cout<<endl<<__gcd(18,12)<<endl;
    
}