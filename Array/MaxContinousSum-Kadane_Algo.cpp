//Question -- Given an array ,find the contigious subarray having maximum sum and return the sum
//Time Complexity -- O(n)
#include<bits\stdc++.h>
using namespace std;
long long maxSubarraySum(int arr[], int n)
{
    long long sum=0;
    long long max= INT_MIN;
    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i];
        if(max<sum)
        max=sum;
        if(sum<0)
        sum=0;
    }
    return max;
}
int main()
{
    int n;
    cout<<"Enter No. of Elements in Array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter Array Elements : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Max Subarray Sum : "<<maxSubarraySum(arr,n);
    return 0;
}
