#include <iostream>
using namespace std;

int josephus(int n, int k)
{
    if (n == 1)
        return 0;
    else
        return (josephus(n - 1, k) + k) % n;
}
int main()
{
    int n, k;
    cout << "Input the value for n and k : ";
    cin >> n >> k;
    cout << "Safe Position is " << josephus(n, k);
    return 0;
}
