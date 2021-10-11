#include <bits/stdc++.h>
using namespace std;

int minJumps(int arr[], int n)
{
    if (n <= 1)
        return 0;

    // not possible condition
    if (arr[0] == 0)
        return -1;

    int maxPos = arr[0];

    int step = arr[0];
    int jump = 1;

    for (int i = 1; i < n; i++)
    {
        if (i == n - 1)
            return jump;

        maxPos = max(maxPos, i + arr[i]);

        step--;

        if (step == 0)
        {
            jump++;

            if (i >= maxPos)
                return -1;

            step = maxPos - i;
        }
    }
    return -1;
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
        cout << minJumps(arr, n) << "\n";
    }
    return 0;
}