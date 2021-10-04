// Find the position of first set bit found from the right side in the binary representation of the number.

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;

    unsigned int fsetbit = n & ~(n-1); //This will set the first bit and rest bits to 0
    int bitpos = log2(fsetbit) + 1;

    cout<<"First Set Bit Position: "<<bitpos;

    return 0;
}