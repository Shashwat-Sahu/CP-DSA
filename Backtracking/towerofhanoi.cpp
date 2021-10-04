#include <iostream>
using namespace std;
void TOH(int n, char src, char dest, char helper)
{
    if (n == 0)
        return;

    TOH(n - 1, src, helper, dest);
    cout<<"MOVE"<<" "<<n<<"FROM"<<" "<<src<<" "<<"TO"<<" "<<dest<<" "<<endl;
    TOH(n - 1, helper, dest, src);
}
int main()
{   int n;
    cout<<"Enter the no of disk:";
    cin>>n;
//     A=tower1(starting)   C=tower2  B=tower3(destination)
    TOH(n, 'A', 'C', 'B');
    return 0;
}
