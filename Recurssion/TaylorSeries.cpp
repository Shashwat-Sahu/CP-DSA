#include <iostream>
using namespace std;

double fac(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return fac(n - 1) * n;
    }
}

double power2(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n % 2 == 0)
    {

        return power2(m * m, n / 2);
    }
    else
    {
        return m * power2(m * m, (n - 1) / 2);
    }
}

double taylor(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return (taylor(x, n - 1)) + power2(x, n) / fac(n);
        ;
    }
}

int main()
{
    std::cout << taylor(3, 10) << std::endl;
    return 0;
}