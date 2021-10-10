#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump [],int );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        cout<<tour(p,n)<<endl;
    }
}

int tour(petrolPump p[],int n)
{
   
   int total=0;
   int i=0;
   int sum=0;
   int start=0;
   while(i<n)
   {
       if(p[i].petrol-p[i].distance>=0)
       {
           total=0;
           start=i;
           sum=0;
           while(total<=n)
           {
               total++;
               
               if(start==n)
               {
                   start=0;
               }
               sum=sum+p[start].petrol-p[start].distance;
               if(sum<0)
               {
                   break;
               }
               start++;
           }
           if(total==n+1)
           {
               break;
           }
       }
       i++;
   }
   if(total==n+1)
   {
       return i;
   }
   else
   {
       return -1;
   }
}
