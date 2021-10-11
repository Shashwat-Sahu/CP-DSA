// https://www.codechef.com/problems/XLSQUARE
#include <iostream>
using namespace std;

int main() {
    int t,a,n;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
      cin>>n>>a;
      int s=0;
      int j=3;
      int sq=1;
    while(sq<=n)
      {
       sq+=j;
       s++;
       j+=2;
      }
      cout<<a*s<<'\n';
    }
	return 0;
}
