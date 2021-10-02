#include <iostream>
using namespace std;
//Adjust function to sort heap NON RECUSRSIVELY
void adjust(int a[], int n, int i)
{
    int item = a[i];
    int j = 2 * i + 1;
    while (j <= n - 1)
    {
        if (a[j + 1] > a[j])
            j = j + 1;
        if (item < a[j])
        {
            a[(j - 1) / 2] = a[j];
            j = 2 * j + 1;
        }
        else
            break;
    }
    a[(j - 1) / 2] = item;
}
//Heapify function Non recursively
void heapify_NonRecursively(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        adjust(arr, n, i);
}
//Heapsort Non recursively
void heapsort_NonRecusrion(int arr[], int n)
{
    heapify_NonRecursively(arr, n - 1);
    for (int i = n - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]);
        adjust(arr, i - 1, 0);
    }
}

//Max Heapify function using Recursion
void max_heapify(int arr[], int n, int i)
{
    int largest = i;
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;

    if (left_child < n && arr[left_child] > arr[largest])
        largest = left_child;
    if (right_child < n && arr[right_child] > arr[largest])
        largest = right_child;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        max_heapify(arr, n, largest);
    }
}
void Build_Max_Heap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        max_heapify(arr, n, i);
}
//Heap Sort using Recursion
void heapsort(int arr[], int n)
{
    Build_Max_Heap(arr, n);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        n = n - 1;
        max_heapify(arr, i, 0);
    }
}
int main()
{
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array : ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    heapsort_NonRecusrion(arr, n);
    // heapsort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}