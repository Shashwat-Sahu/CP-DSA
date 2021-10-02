#include<iostream>

using namespace std;


void BubbleSort(int array[],int length)
{
    for(int i=0;i<length-1;i++)
    {
        for(int j=0;j<length-1-i;j++)
        {
            if(array[j]>array[j+1])
            {
                std::swap(array[j],array[j+1]);
            }
        }
    }
}


int main()
{
    int length;
    cout<<"Enter lenght of array:";
    cin>>length;

    int array[length];

    cout<<"Enter elements of array:";
    for(int i=0;i<length;i++)
        cin>>array[i];

    BubbleSort(array,length);
    cout<<"Sorted array:";
    for(int i=0;i<length;i++)
        cout<<array[i]<<" ";

    return 0;
}

/*Example
Enter lenght of array:6
Enter elements of array:-9 7 0 44 5 17
Sorted array:-9 0 5 7 17 44
*/