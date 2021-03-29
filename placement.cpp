#include<iostream>
using namespace std;
int main()
{
    int n,k;
    cin>>n;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin>>array[i];
    }
    cin>>k;
    int left=0,right=n-1;
    while (left<=right)
    {
        if((array[left]+array[right])==k)
        {
            cout<<left<<" "<<right<<endl;
            break;
        }
        else if((array[left]+array[right])<k)
        {
            left++;
        }
        else if((array[left]+array[right])>k)
        {
            right--;
        }
    }
    
    return 0;
    
}