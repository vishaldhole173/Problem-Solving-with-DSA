#include<iostream>
using namespace std;
int main()
{
    int a[3][3]={{10,0,0},{20,30,0},{40,50,60}};
    int flag=0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = i+1; j < 3; j++)                //optimizing
        {
            if((j>i) && a[i][j]!=0)
            {
                flag=1;
                break;
            }
        }
       if(flag==1)
       {
           break;
       } 
    }
    if(flag==0)
    {
        cout<<"lower traingular"<<endl;
    }
    else{
        cout<<"Not lower traingular"<<endl;
    }
    

}