#include<bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define vi vector<int>
#define ll long long
#define lb cout<<endl
#define cin(a) int i;for(auto &i:a)cin>>i
#define cout(a) int j;for(auto &j:a)cout<<j

int main()
{
    string s;cin >> s;
    vi a(256,-1);
    int maxLen=0,start=-1;
    
    loop(i,0,s.size()){
        if(a[s[i]]>start)
        start=a[s[i]];

        a[s[i]]=i;
        maxLen=max(maxLen,i-start);
    }
    cout<<maxLen;
    return 0;
}