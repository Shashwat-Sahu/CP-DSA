// ----------------------------------------in O(n) ------------------------

#include<bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define vi vector<int>
#define ll long long
#define lb cout<<endl

int get_area(vi a){
    int n=a.size(),i=0,ans=0;

    a.push_back(0);
    stack<int>st;
    while(i<n){
        while(!st.empty() && a[st.top()]>a[i]){
            int t=st.top();
            int h=a[t];
            st.pop();

            if(st.empty()){
                ans=max(ans,h*i);
            }
            else{
                int len=i-st.top()-1;//-1 because we already poped top element of stack
                ans=max(ans,h*len);
            }
        }
        st.push(i);
        i=i+1;
    }
    return ans;
}
int main()
{
    int n,i;cin>>n;
    vi a(n);
    for(auto &i:a)cin>>i;
    cout<<get_area(a)<<endl;
    return 0;
}

