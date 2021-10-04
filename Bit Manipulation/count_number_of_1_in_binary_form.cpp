#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int temp=0;
    while (n)
    {
        n=(n&(n-1));
        temp++;
    }
    cout<<temp;
    return 0;
}
