#include <bits/stdc++.h>
using namespace std;

bool checkValidity(int pg, int arr[], int n, int m)
{
    int num = 1;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > pg)
            return false;

        if (sum + arr[i] > pg)
        {
            num++;
            sum = arr[i];

            if (num > m)
                return false;
        }
        else
            sum += arr[i];
    }

    return true;
}

int findPages(int arr[], int n, int m)
{
    if (m > n)
        return -1;

    int low = 0, high = 0;
    for (int i = 0; i < n; i++)
        high += arr[i];

    int ans = INT_MAX;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (checkValidity(mid, arr, n, m))
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return ans;
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
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int m;
        cin >> m;
        cout << findPages(arr, n, m) << endl;
    }
    return 0;
}