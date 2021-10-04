// Program to count set Bits in a Number.
// Time complexity = O(1) (Or it is equal to no. of set bits )
#include<bits\stdc++.h>
using namespace std;
int countsetbit(int n)
{
    int count=0;
    while(n>0)
    {
        n=n&(n-1);
        count++;
    }
    return count;
}
int main()
{
    int n;
    cout<<"Enter Number : ";
    cin>>n;
    cout<<"SET BITS : "<<countsetbit(n);
    return 0;
}
