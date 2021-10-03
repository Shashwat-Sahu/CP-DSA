#include<bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define vi vector<int>
#define ll long long
#define lb cout<<endl
#define cin(a) int i;for(auto &i:a)cin>>i;
#define cout(a) int j;for(auto &j:a)cout<<j<<" ";

int rainwater_store(vi a){
    int n=a.size(),i=0,ans=0;
    // a.push_back(0);
    stack<int>st;
    while(i<n){
        while(!st.empty() && a[st.top()]<a[i]){
            int curr=st.top();
            st.pop();
            if(st.empty()){
                break;
            }
            int diff=i-st.top()-1;
            int h=min(a[st.top()],a[i])-a[curr];
            ans+=h*diff;

        }
        st.push(i);
        i++;
    }
    return ans;
}
int main()
{
    int n;cin >> n;
    vi a(n);
    cin(a);

    cout<<rainwater_store(a);
    return 0;
}