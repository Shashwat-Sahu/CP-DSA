#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n,t,ans=0;
    cin>>t;
   for(int i=1;i<=t;i++)
    {
        cin>>n;
        int a=floor(log2(n));
        int b=pow(2,a);
        int c=pow(2,(a-1));
        if((n-b+1)>=(b-c))
        {
            ans=n-b+1;
        }
        else
        {
            ans=b-c;
        }
        cout<<ans<<endl;

    }
    return 0;
}