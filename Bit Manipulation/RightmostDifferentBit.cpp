// Given two numbers M and N.
// The task is to find the position of the rightmost
// different bit in the binary representation of numbers.

#include<bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    int x = m^n;
    cout << log2(x - (x & (x-1))) + 1;

    return 0;
}