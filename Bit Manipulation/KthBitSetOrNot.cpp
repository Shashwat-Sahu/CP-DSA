// Given a number N and a bit number K,
// check if Kth bit of N is set or not.

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    cout << ((1 & (n >> k)) == 1 ? "Yes" : "No");

    return 0;
}
