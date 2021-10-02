#include <iostream>
using namespace std;

//function to caclulate GCD of two numbers
int gcd(int a, int b)
{
    //base case
    if (a == 0)
        return b;
    //recursive case
    else
        return gcd(b % a, a);
}


//Driver code
int main()
{
    int a = 10, b = 15;
    cout << "gcd(10,15) = " << gcd(a, b);
    return 0;
}