// https://leetcode.com/problems/find-the-duplicate-number/
// Love babbar DSA-450 Question-11
#include<iostream>
#include<vector>
using namespace std;
typedef long long itn;

int findDuplicate(vector<int>& nums) {
    int sum=0;
    for(auto i:nums)    sum+=i;
    int n=nums.size()-1;
    return sum-(n*(n+1))/2;
}

int main(){

    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &i:nums)    cin>>i;
    cout<<findDuplicate(nums);
    
    return 0;
}