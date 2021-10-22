#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
  int n;
  cin>>n;
    string a[1000],b;
    for(int i=0;i<n;i++)
   {
      cin>>b;
      a[i]=b;
     }
    int q;
    cin>>q;
    string check;
    for(int i=0;i<q;i++)
    {int count=0;
     cin>>check;    
       for(int j=0;j<n;j++)
       {
          if(check.compare(a[j])==0)
              count++;
       }
     cout<<count<<endl;
    }
    return 0;
}
