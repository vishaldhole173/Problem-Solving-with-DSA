#include <bits/stdc++.h>
using namespace std;
 
//0 2 4
int number0f2s(int n)
{
    int count = 0;
    while (n > 0)
    {
        if (n % 10 == 2)
            count++;
 
        n = n / 10;
    }
    return count;
}
int number0f0s(int n)
{
    int count = 0;
    while (n > 0)
    {
        if (n % 10 == 0)
            count++;
 
        n = n / 10;
    }
    return count;
}
 
int number0f4s(int n)
{
    int count = 0;
    while (n > 0)
    {
        if (n % 10 == 4)
            count++;
 
        n = n / 10;
    }
    return count;
}
// Counts the number of '2' 
// digits between 0 and n 
int numberOf2sinRange(int n)
{
    // Initialize result
    int count2 = 0 ; 
    int count0 = 0 ; 
    int count4 = 0 ; 
 
    // Count 2's in every number
    // from 2 to n
    for (int i = 2; i <= n; i++)
        count2 += number0f2s(i);
    
    for (int i = 0; i <= n; i++)
        count0 += number0f0s(i);
    
    for (int i = 4; i <= n; i++)
        count4 += number0f4s(i);
 
    return count0 + count2 + count4+1;
}
 
// Driver Code
int main()
{   int n;
cin>>n;
    cout << numberOf2sinRange(n);
    
    return 0;
}
