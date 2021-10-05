#include <bits/stdc++.h>

using namespace std;

int countSubarrWithEqualZeroAndOne(int arr[], int n)
{
    map<int, int> mp;
    int sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        // Replacing 0's in array with -1
        if (arr[i] == 0)
            arr[i] = -1;

        sum += arr[i];

        // If sum = 0, it implies number of 0's and 1's are
        // equal from arr[0]..arr[i]
        if (sum == 0)
            count++;

        //if mp[sum] exists then add "frequency-1" to count
        if (mp[sum])
            count += mp[sum];

        //if frequency of "sum" is zero then we initialize that frequency to 1
        //if its not 0, we increment it
        if (mp[sum] == 0)
            mp[sum] = 1;
        else
            mp[sum]++;
    }
    return count;
}

int main()
{
    int arr[] = {1, 0, 0, 1, 0, 1, 1};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "count="
         << countSubarrWithEqualZeroAndOne(arr, n);
}
