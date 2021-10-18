#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX_COUNT 1000000000

bool checkDistanceValidity(ll d, ll c, ll arr[], ll n)
{

    ll placed_cows = 1;
    ll last = arr[0];

    for (ll i = 0; i < n; i++)
    {
        if (arr[i] - last >= d)
        {
            placed_cows+=1;
            if (placed_cows == c)
                return true;
            last = arr[i];
        }
    }

    return false;
}

void solve()
{
    ll n, c;
    cin >> n >> c;
    ll arr[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    ll low = 0, high = MAX_COUNT, pos = 0, mid;

    while (high >= low)
    {
        mid = (low + high) / 2;

        if (checkDistanceValidity(mid, c, arr, n))
        {
            pos = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << pos << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
