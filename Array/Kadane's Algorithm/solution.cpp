/* -------------------------------- Algorithm ------------------------------- */
/*
     Initialize : 
     max_so_far = 0 
     max_ending_here = 0 
     Loop over the elements of the array : 
     At index i, of the array 
      max_ending_here = max_ending_here+arr[i] 
      if(max_ending_here < 0) 
        max_ending_here = 0 
      if(max_ending_here > max_so_far) 
        max_so_far = max_ending_here 
     return max_so_far
     
*/
#include <iostream>
using namespace std;
int kadanes(int array[], int length)
{
    int highestMax = 0;
    int currentElementMax = 0;
    for (int i = 0; i < length; i++)
    {
        currentElementMax = max(array[i], currentElementMax + array[i]);
        highestMax = max(highestMax, currentElementMax);
    }
    return highestMax;
}
int main()
{
    cout << "Enter the array length: ";
    int l;
    cin >> l;
    int arr[l];
    cout << "Enter the elements of array: ";
    for (int i = 0; i < l; i++)
    {
        cin >> arr[i];
    }
    cout << "The Maximum Sum is: " << kadanes(arr, l) << endl;
    return 0;
}