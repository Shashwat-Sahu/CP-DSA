// https://www.codechef.com/START14C/problems/FIXFIX

#include <iostream>
using namespace std;

int main() {
    int t;
     cin>>t;
     for(int i=0;i<t;i++)
     {
         int n,k;
         cin>>n>>k;
         if((n-k)==1)
         {
             cout<<-1<<endl;
             
         }
         else if(k==0&&n==1)
         {
              cout<<-1<<endl;
         }
          else 
         {

             int xx;
              for(xx=1;xx<=k;xx++)
              {
                  cout<<xx<<" ";
              }
              int yy=xx;
              xx++;
              while(xx<=n)
              {
                  cout<<xx<<" ";
                  xx++;
              }
              if(k!=n)
              {
                  cout<<yy<<endl;
              }
              else
              {
                  cout<<endl;
              }
              
              
         }
         
         
     }
  
	return 0;
}
