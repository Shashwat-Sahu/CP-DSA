// https://leetcode.com/problems/merge-intervals/
// Love babbar DSA-450 Question-14
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long itn;

bool myCmp(vector<int>a,vector<int>b){
    if(a[0]==b[0])  return a[1]<b[1];
    return a[0]<b[0];
}

vector<vector<int>> merge(vector<vector<int>>& vec) {
    sort(vec.begin(),vec.end(),myCmp);
    queue<vector<int>> qu;
    qu.push(vec[0]);
    for(int i=1;i<vec.size();i++){
        if(qu.back()[1]>=vec[i][0]){
            qu.back()[1]=max(vec[i][1],qu.back()[1]);
        }
        else{
            qu.push(vec[i]);
        }
    }
    vector<vector<int>> ans;
    while(qu.size()){
        ans.push_back(qu.front());
        qu.pop();
    }

    return ans;
}

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int n;
    cin>>n;
    vector<vector<int>> vec(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>vec[i][0]>>vec[i][1];
    }
    vector<vector<int>> ans = merge(vec);
    for(auto i:vec){
        cout<<i[0]<<" "<<i[1]<<endl;
    }
    
    return 0;
}