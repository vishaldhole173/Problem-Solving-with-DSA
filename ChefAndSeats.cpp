#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        int groups=0;
        for (int i = 0; i < s.size(); i++)
        {
            if(i==(s.size()-1))
            {
                if((s[i]=='1' && s[i-1]=='1') || (s[i]=='1' && s[i-1]=='0'))
                {
                    groups++;
                }
            }
            else if(s[i]=='1' && s[i+1]=='0' && i<(s.size()-1))
            {
                groups++;
            }
        }
        cout<<groups<<endl;
    }
    
    return 0;
}