#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
    // Function to find the trapped water between the blocks.
public:
    ll trappingWater(int arr[], int n)
    {
        int left[n], right[n];

        left[n - 1] = 0;
        int max = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] > max)
            {
                max = arr[i];
                left[i] = 0;
            }
            else
                left[i] = max - arr[i];
        }

        max = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > max)
            {
                max = arr[i];
                right[i] = 0;
            }
            else
                right[i] = max - arr[i];
        }

        ll res = 0;
        for (int i = 1; i < n - 1; i++)
            res += min(left[i], right[i]);

        return res;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];

        //adding elements to the array
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
    }

    return 0;
}