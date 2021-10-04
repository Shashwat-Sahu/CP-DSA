#include<bits/stdc++.h>
using namespace std;

int closestToZero(int arr[], int n)
{
    sort(arr,arr+n);
    int i=0;
    int j=n-1;
    //int min=abs(arr[i]+arr[j]);
    int ans=arr[i]+arr[j];
    while(i<j)
    {
        if(abs(arr[i]+arr[j])<abs(ans))
        {
            ans=arr[i]+arr[j];
        }
        else if(abs(arr[i]+arr[j])==abs(ans)&&arr[i]+arr[j]>ans)
        {
            ans=arr[i]+arr[j];
        }
        
        if(arr[i]+arr[j]<0)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return ans;
}

int main ()
{
    int t; 
    cin >> t;
    while (t--)
    {
        int n; 
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout <<closestToZero(arr, n) << endl;
    }
} 