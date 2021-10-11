// https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1
// Love babbar DSA-450 Question-10
#include<iostream>
using namespace std;
typedef long long itn;

int minJumps(int arr[],int n){
    int i=0;
    int jumps=0;
    while(i<n-1){
        jumps++;
        int curJump=arr[i];
        if(curJump==0) return -1;
        int nextJump=i+1;
        for(int j=1;j<=arr[i];j++){
            if(nextJump<n && i+j+arr[i+j]>=nextJump+arr[nextJump]){
                nextJump=i+j;
            }
        }
        if(i+arr[i]>=n-1)   break;
        i=nextJump;
    }
    return jumps;
}

int main(){

    int n;
    cin>>n;
    int arr[n];
    for(auto &i:arr)    cin>>i;
    cout<<minJumps(arr,n);
    return 0;
}