#include <bits/stdc++.h>
using namespace std;

int main() {
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    if(n<2)
	    {
	        if(n==0)
	        {
	            cout<<1<<endl;
	        }
	        else
	        {
	            cout<<2<<endl;
	        }
	    }
	    else
	    {
	        int x=log2(n);
	        int y=pow(2,x);
	        if(n==(y*2)-1)
	        {
	            cout<<n+1<<endl;
	        }
	        else
	        {
	            cout<<y<<endl;
	        }
	    }                           
	}
	return 0;
}