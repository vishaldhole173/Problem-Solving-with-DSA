//second largest
#include<iostream>
#include<climits>
using namespace std;
int main()
{
    int a[10]={2,3,6,31,45,57,4,9,5,33};
    int max=INT_MIN;
    int secondlargest=INT_MIN;
    for (int i = 0; i < 10; i++)
    {
        if (a[i]>max)
        {
            secondlargest=max;
            max=a[i];
            
        }
        
    }
    cout<<secondlargest<<endl;
}