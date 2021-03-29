#include<iostream>
using namespace std;
//without stl
int main()
{
    string s="ABCDABKTP";
    string sub="AB";
    string a="";
    int flag=0;
   
    for (int i = 0; i < s.length(); i++)
    {
    for (int j = i; j < s.length(); j++)
        {
            a+=s[i];
        }
        if (a==sub)
        {
            cout<<"exists"<<endl;
            flag=1;
            break;
        }
        if (flag)
       {
           break;
       }
       a="";
    }
    
      if (flag==0)
      {
          cout<<"Not exists"<<endl;
      }
       
    
}