#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main()
{
    unordered_map<string,int> ourmap;
    ourmap["abc"]=1;
    ourmap["def"]=2;
    if (ourmap.count("abc")>0)
    {
        cout<<"abc is present"<<endl;
    }
    
}
