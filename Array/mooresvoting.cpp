#include <iostream>
using namespace std;

int majorityElement(int  arr[],int n)
 {
        int val=0;
        int count=0;
        for(int j=0;j<n;j++)
        {
            int i=arr[j];
            if(count==0)
            {
                val=i;
            }
            if(val==i)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return val;
}

int main()
{
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)cin>arr[i];

    cout<<"\nThe most occuring element is : "<<majorityElement(arr,n)<<endl;

    return 0;
}
    