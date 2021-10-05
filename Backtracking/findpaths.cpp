#include <iostream>
using namespace std;
void findpaths(int i, int j, string s,int m,int n)
{
    if (i >= m || j >= n)
        return;

    if (i == m-1 && j == n-1)
    {
        cout << s << endl;
        return;
    }

    s = s + 'D';
    findpaths(i + 1, j, s,m,n);
    s.pop_back();

    s = s + 'R';
    findpaths(i, j + 1, s,m,n);
    s.pop_back();
}
int main()
{   cout<<"Enter starting point:";
    int sx,sy;
    cin>>sx>>sy;
    cout<<"Enter destination point:";
    int dx,dy;
    cin>>dx>>dy;
    findpaths(sx,sy,"",dx,dy);
    return 0;
}
