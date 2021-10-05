// Given a rope of length n,we need to maximize number of peices of cut such that each cut length belongs to set{a,b,c}for given values of a,b,c.
// If no such cut is possible return -1.
#include<iostream>
using namespace std;
int max(int a, int b, int c)
{
    int m1,m2;
    m1=((a>b)?a:b);
    m2=((c>m1)?c:m1);
    return m2;
}
int maxpiece(int n, int a, int b, int c)
{
    int r;
    if (n == 0)
    {
       return 0;
    }
    if (n<0)
    {
        return -1;
    }
    r = max(maxpiece(n-a, a, b, c), maxpiece(n-b, a, b, c), maxpiece(n-c, a, b, c));
    if (r == -1)
    return -1;
    return r + 1;
}
int main()
{
    int lenth;
    cout << "Enter rope lenth: ";
    cin >> lenth;
    int p1, p2, p3;
    cout << endl<< "Enter values of a,b,c: ";
    cin>>p1>>p2>>p3;
    cout<<endl<<"MAX Peices = "<< maxpiece(lenth, p1, p2, p3);
    return 0;
}
