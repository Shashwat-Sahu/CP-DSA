//Write a program to add one to a given number. You are allowed to use only bitwise operator

#include<bits/stdc++.h>
using namespace std;
    
int main(){
	int n;
	cin>>n;
    int m=1;
    
    while(n&m){ 
	  n=n^m;
      m<<=1;
    }
    n=n^m;
    
	cout<<n;
	return 0;
}
