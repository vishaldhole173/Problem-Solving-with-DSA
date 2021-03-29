#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

bool f(int x,int y)
{
    return x>y;
}

using namespace std;
int main()
{
    vector<int> A = {1,2,3,2,34,1,1,100};
    // cout<<A[1]<<endl;
    sort(A.begin(),A.end());

    vector<int>::iterator it3;
    for(it3=A.begin();it3!=A.end();it3++)
    {
        cout<<*it3<<"\t";

    }
    cout<<endl;
    bool present= binary_search(A.begin(), A.end(), 100);
    // cout<<present;
    A.push_back(69);
    vector<int>::iterator it1= lower_bound(A.begin(),A.end(),2);
    vector<int>::iterator it2= upper_bound(A.begin(),A.end(),2);
    //cout<<*it1<<endl;
    //cout<<*it2<<endl;
    vector<int>::iterator it4;
    sort(A.begin(),A.end(),f);
    for(it4=A.begin();it4!=A.end();it4++)
    {
        cout<<*it4<<"\t";
    }
    cout<<endl;
    vector<int> B = {1,22,1,1,22,1,34,2,1,56,778,30};
    sort(B.begin(),B.end());
    auto it=lower_bound(B.begin(),B.end(),22);
    auto t=upper_bound(B.begin(),B.end(),22);
    cout<<(t)-(it)<<endl;

    set<int> S={32,454,23,57,634,234,23,123,454};
    S.erase(1);
   
    for(int s : S)
    {
        cout<<s<<"\t";
    }
//     cout<<endl;
//    auto k=S.lower_bound(23);
//    auto p=S.upper_bound(23);

//     cout<<;


    return 0;
}