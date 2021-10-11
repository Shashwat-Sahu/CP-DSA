#include<bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define vi vector<int>
#define ll long long
#define lb cout<<endl
#define cin(a) int i;for(auto &i:a)cin>>i
#define cout(a) int j;for(auto &j:a)cout<<j<<" "

int main()
{
    int n;cin >> n;
    vi a(n);
    cin(a);
    stack<pair<int,int> >st;
    vi ans;
    loop(i,0,n){
        int temp_second=1;
        while(!st.empty() && st.top().first<=a[i]){
            temp_second+=st.top().second;
            st.pop();
        }
        st.push({a[i],temp_second});
        ans.push_back(temp_second);
    }
    cout(ans);
    return 0;
}