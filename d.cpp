#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
int main()
{    
	int num;

	cout<<"enter number of ele in array"<<endl;
	
	cin>>num;
	int v[num];
	int longestpeak=0;
	cout<<"enter elements of array"<<endl;
	for(int i=0;i<num;i++)
	{
		cin>>v[i];
	}
	int i=1;
	while(i<(num-1))
	{
		if(!(v[i-1]<v[i] && v[i]>v[i+1] ))
		{
			i+=1;
            continue;
		}
		int leftptr=i-2;
		while(leftptr>=0 && v[leftptr]<v[leftptr+1])
		{
			leftptr--;
		}
		int rightptr=i+2;
		while(rightptr<num && v[rightptr]<v[rightptr-1])
		{
			rightptr++;
		}
		int len=rightptr - leftptr - 1;
		int currpeak=len;
		if(currpeak>longestpeak)
		{
			longestpeak=currpeak;
		}
		i=rightptr;
		
	}
	cout<<"output :"<<longestpeak<<endl;
	return 0;
}