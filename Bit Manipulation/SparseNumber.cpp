// Given a number N. The task is to
// check whether it is sparse or not

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    cout << (((n >> 1) & n) ? 0 : 1);
    return 0;
}
