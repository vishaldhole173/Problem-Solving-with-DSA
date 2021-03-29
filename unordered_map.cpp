#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<set>
//practice questions
using namespace std;
int main()
{
    set<int,greater<int>> s1;
    set<int,greater<int>> s2;
    int a1[]={4,4};
    int a2[]={1,4,2,3,5,4};
    vector<int> out;
    for(int i=0;i<2;i++)
    {
        s1.insert(a1[i]);
    }
    for (int i = 0; i < 5; i++)
    {
         s2.insert(a2[i]);
    }
    for(int i=0;i<5;i++)
    {
        if ((s1.find(a2[i])!=s1.end()) && (s2.find(a2[i])!=s2.end()))
        {
            out.push_back(a2[i]);
        }
        
    }
    set<int,greater<int>>::iterator itr=s1.begin();
    for (itr = s1.begin(); 
         itr != s1.end(); ++itr) 
    {
        cout << ',' << *itr;
    }
    cout << endl;
    
    set<int,greater<int>>::iterator itr1=s2.begin();
    for (itr1 = s2.begin(); 
         itr1 != s2.end(); ++itr1) 
    {
        cout << ',' << *itr1;
    }
    cout << endl;
    

    for (int i = 0; i < out.size(); i++)
    {
        cout<<out[i]<<" ";
    }
    
    
}