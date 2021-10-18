// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Love babbar DSA-450 Question-17
#include<iostream>
#include<vector>
#define null NULL
using namespace std;
typedef long long itn;

int maxProfit(vector<int>& prices) {
    int n=prices.size();
    int maxx=prices[n-1];
    int maxPr=0;
    for(int i=n-2;i>-1;i--){
        maxx=max(maxx,prices[i]);
        maxPr=max(maxPr,maxx-prices[i]);
    }
    return maxPr;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n;
    cin>>n;
    vector<int> prices(n);
    for(auto &i:prices) cin>>i;
    cout<<maxProfit(prices);
    return 0;
}
