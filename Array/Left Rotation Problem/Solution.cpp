#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,d;
    cin>>n>>d;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=d;i<n;i++){
        cout<<a[i]<<" ";
    }
    for(int i=0;i<d;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
