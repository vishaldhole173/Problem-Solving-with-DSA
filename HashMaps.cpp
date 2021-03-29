#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

vector<int> freq(vector<int> v,int size)
{
    unordered_map<int,bool> map;
    vector<int> a;
    for (int i = 0; i < size; i++)
    {
        if (map.count(v[i])>0)
        {
            continue;
        }
        map[v[i]]=true;
        a.push_back(v[i]);
    }
    return a;
}
int main()
{
    vector<int> v={1,2,2,2,2,3,4,5,3,4,5,3,2,1,4};
    vector<int> out=freq(v,15);
    
    for (int i = 0; i < out.size(); i++)
    {
        cout<<out[i]<<" ";
    }
    cout<<endl;
    for(auto it:out)
    {
        cout<<(it)<<" ";
    }
    cout<<endl;
    vector<int>::iterator it=out.begin();
    while(it!=out.end())
    {
        cout<<*it<<" ";
        it++;
    }
    cout<<endl;
    unordered_map<string,bool> map1;
    map1["abc"]=true;
    map1["def"]=false;
    map1["ghi"]=true;
    unordered_map<string,bool>::iterator i=map1.begin();
    while (i!=map1.end())
    {
        cout<<" Key: "<<i->first<<" Value: "<<i->second;
        i++;
    }
    unordered_map<string,bool>::iterator i1=map1.find("ghi");
    map1.erase(i1);
    unordered_map<string,bool>::iterator i3=map1.begin();
    cout<<endl;
    while (i3!=map1.end())
    {
        cout<<i3->first<<" "<<i3->second<<endl;
        i3++;
    }
    return 0;
}