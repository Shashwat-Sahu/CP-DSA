// https://leetcode.com/problems/next-permutation/
// Love babbar DSA-450 Question-15
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
typedef long long itn;

void nextPermutation(vector<int>& nums) {
    int n=nums.size();
    stack<int> st;
    st.push(n-1);
    int i;
    for(i=n-2;i>=0;i--){
        if(nums[st.top()]<nums[i]){
            st.push(i);
        }
        else if(nums[st.top()]>nums[i]){
            int mx=st.top();
            st.pop();
            while(st.size()&&nums[st.top()]>nums[i]){
                mx=st.top();
                st.pop();
            }
            swap(nums[mx],nums[i]);
            sort(nums.begin()+i+1,nums.end());
            return;
        }
    }
    reverse(nums.begin(),nums.end());
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int inp;
        cin>>inp;
        nums.push_back(inp);
    }   
    for(auto i:nums)    cout<<i<<" ";cout<<endl;
    nextPermutation(nums);
    for(auto i:nums)    cout<<i<<" ";
    
    return 0;
}