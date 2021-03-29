#include<iostream>
using namespace std;
int main()
{
    
    float f=10.2;
    float* ft=&f;
    cout<<sizeof(f)<<endl;
    cout<<&f<<endl<<*ft<<endl;
    
}