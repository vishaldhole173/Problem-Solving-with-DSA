#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
int main()
{
    int num;
    int b=0;
    int out=0;
    int max=0;
    vector<int> v;
    cout<<"enter the array of binary numbers";
    while (cin>>num)
    {
        v.push_back(num);
    }
    
   
    while (v.size()>b)
    
    {
        
        if(v[b]==1)
        {
            out++;
            max=out;
        }
        else
        {
            out=0;
        }
        b++;

    }
    cout<<max<<endl;
    return 0;
    
}