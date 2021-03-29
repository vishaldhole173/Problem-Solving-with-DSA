#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void maxarearectangle(vector<int> a)
{
    stack<int> s;
    int i=0;
    int area=0;
    a.push_back(0);
    while (i<a.size())
    {
        while (!s.empty() && a[s.top()]>a[i])   //2,1,5,6,2,3
        {
            int h=a[s.top()];
            s.pop();
            if (s.empty())
            {
                area=max(area,h*i);
            }
            else{
                int len=i-s.top()-1;
                area=max(area,h*len);
            }
            
        }
        s.push(i);
        i++;
    }
    cout<<area<<endl;
}
int main()
{
    vector<int> a={2,1,5,6,2,3};
    maxarearectangle(a);
}