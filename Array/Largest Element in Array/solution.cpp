// C++ program to find maximum
// in arr[] of size n
#include <bits/stdc++.h>
using namespace std;
 
int largest(int arr[], int n)
{
    // Initialize maximum element
    int max = INT_MIN;
 
    // Traverse array elements
    // from second and compare
    // every element with current max
    for (int i = 0; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
 
    return max;
}
 
// Driver Code
int main()
{
    int arr[] = {10, 324, 45, 90, 9808};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Largest in given array is "
         << largest(arr, n);
    return 0;
}
 
