#include<iostream>
#include<unordered_map>
using namespace std;
int doUnion(int a[], int n, int b[], int m){
    unordered_map<int,int> map;
    for (int i = 0; i < n; i++)
    {
        map[a[i]]++;
    }
    for (int i = 0; i < m; i++)
    {
        map[b[i]]++;
    }
    return map.size();
}
int doIntersection(int a[], int n, int b[], int m){
    unordered_map<int,int> map;
    for (int i = 0; i < n; i++)
    {
        map[a[i]]++;
    }
    for (int i = 0; i < m; i++)
    {
        map[b[i]]++;
    }
    int intersectionElements=0;
    for (int i = 0; i < map.size(); i++)
    {
        if(map[a[i]]>1)
        {
            intersectionElements++;
        }
    }
    return intersectionElements;
    
}

int main()
{
    int a[]={1,2,3,4,5};
    int b[]={1,2,3,8,4};
    cout<<doUnion(a,5,b,5)<<endl;
    cout<<doIntersection(a,5,b,5)<<endl;
}