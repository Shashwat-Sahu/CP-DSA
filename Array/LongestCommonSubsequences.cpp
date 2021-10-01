// Longest consecutive subsequence
// Given an array of positive integers. 
// Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.
#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int n);
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  cout<<findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}


// arr[] : the input array
// N : size of the array arr[]

// return the length of the longest subsequene of consecutive integers
int findLongestConseqSubseq(int arr[], int N)
{
  //Your code here
    vector<int> v(100000+1);
    int maxval=0;
    for(int i=0;i<N;i++)
    {
        
            v[arr[i]]=1;
            maxval=max(maxval,arr[i]);
    }
    int res=v[0];
    for(int i=1;i<=maxval;i++)
    {
        if(v[i-1]!=0&&v[i]!=0)
        {
            v[i]+=v[i-1];

        }
    res=max(res,v[i]);
    }
    return res;
}