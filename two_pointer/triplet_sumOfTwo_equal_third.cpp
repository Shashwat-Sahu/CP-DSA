#include <bits/stdc++.h>
using namespace std;

int countTriplet(int arr[], int n)
{
    int count=0;
    sort(arr,arr+n);
    for(int i=n-1;i>=0;i--)
    {
        int j=0;
        int k=i-1;
        while(j<k)
        {
            if(arr[j]+arr[k]==arr[i])
            {
                count++;
                j++;
                k--;
            }
            else if(arr[j]+arr[k]>arr[i])
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }
    return count;
}

int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

        cout <<countTriplet(arr, n) << "\n";

    }

    return 0;
}