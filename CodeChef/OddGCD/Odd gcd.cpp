#include <bits/stdc++.h>
using namespace std;

int main()
{
   int t,n;
   
   cin>>t;
   while(t--)
   {
       cin>>n;
       int arr[n],ar[n];
       for(int i=0;i<n;i++)
       {
           cin>>arr[i];
           int c=arr[i];
           int a=arr[i];
            while(a>0)
            {
                a=a&a-1;
                break;
            }
            ar[i]=c-a;
       }
       sort(ar,ar+n);
       int count=0;
       while(ar[0]>1)
       {
           ar[0]/=2;
           count++;
       }
       cout<<count<<endl;
   }
   
   return 0;
}