#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    long long int t;
     cin>>t;
     for(long long int i=0;i<t;i++)
     {
         long long int n,p,k;
        long long int ans=0,flag=0;
         cin>>n>>p>>k;
         int x=p%k;
         x++;
         //cout<<x<<endl;
   
         int xx=(n-1)/k;
         int c=xx;
         c++;
         //cout<<c<<endl;
         xx*=k;
          
         int yy=n-xx;
         //cout<<yy<<endl;
         if(x>yy)
         {
            ans=yy*c+((x-yy-1)*(c-1));
         }
         else
         {
             ans=(x-1)*c;
         }
         //     cout<<ans<<endl;
         
         
         
        
             for(int b=x-1;b<n;b+=k)
             {
                 ans++;
                 if(b==p)
                 {
                     break;
                 }
                 
                 
             }
           
         cout<<ans<<'\n';
     }
	
	return 0;
}