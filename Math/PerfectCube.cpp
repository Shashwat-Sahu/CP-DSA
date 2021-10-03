#include <bits/stdc++.h>
using namespace std;
bool Perfect_Cube(int x)
{
    float temp = pow(x, 1 / 3.0);
    return (ceil(temp) == floor(temp)) ? true : false;
}

int main()
{
    int x;
    cin >> x;
    if (Perfect_Cube(x))
    {
        cout << "PerfectCube" << endl;
    }
    else
    {
        cout << "Not perfectCube" << endl;
    }
    // cout << Perfect_Cube(x) << endl;
    return 0;
}