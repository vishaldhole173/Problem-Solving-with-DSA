#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    char str[100];
    char ans[100];
    cout<<"enter a string";
    cin>>str;
    int l=strlen(str);
    for (int i = 0; i < l; i++)
    
    {
        if(str[i]>='A' && str[i]<='Z')
        {
           ans[i]= tolower(str[i]);

        }
        else
        {
            ans[i]=toupper(str[i]);
        }
        
    }
    for (int i = 0; i < l; i++)
    {
        cout<<ans[i];
    }
    
    return 0;
}