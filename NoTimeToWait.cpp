#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int N; 
	int H;
	int x;
    cin>>N>>H>>x;
	int a[N];
    int flag=0;
	for(int i=0;i<N;i++)
	{
	    cin>>a[i];
	}
	for(int i=0;i<N;i++)
	{
	    if(x+a[i]>=H)
	    {
	        flag=1;
            break;
	    }
	}
    if(flag)
    {
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
	return 0;
}