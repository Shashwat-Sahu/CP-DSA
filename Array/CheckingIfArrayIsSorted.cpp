#include <iostream>
using namespace std;

struct arr
{
    int A[20];
    int size{0};
    int length{0};
};
void display(struct arr a1)
{
    int i;
    cout << "Elements: ";
    for (i = 0; i < a1.length; i++)
    {
        cout << a1.A[i] << " ";
    }
    cout << endl;
}

int IfSorted(struct arr a)
{
    int l = a.length;
    int i = 0;
    while (i < l)
    {
        if (a.A[i] > a.A[i + 1])
        {
            return -1;
            i++;
        }
    }
    return 0;
}
int main()
{

    struct arr a
    {
        {2, 4, 6, 7, 9, 11, 13, 15}, 20, 8
    };

    int res = IfSorted(a);

    if (res == 0)
    {
        cout << "Sorted ";
    }
    else
    {
        cout << "Not Sorted ";
    }

    display(a);

    return 0;
}