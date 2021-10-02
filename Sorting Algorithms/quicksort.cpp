//Hoare quick sort
#include <stdio.h>
void quicksort(int arr[], int n1, int n2);
int partition(int arr[], int lb, int ub);
int main()
{
    int n;
    printf("Enter the number of elements in the array-->");
    scanf("%d", &n);
    int arr[n];
    if (n > 0)
    {
        printf("Enter the array-->");
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        quicksort(arr, 0, n - 1); // Calling the quicksort function
        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
    }
    else
        printf("Empty array");
    return 0;
}
void quicksort(int arr[], int lb, int ub)
{
    int loc;
    if (lb < ub)
    {
        loc = partition(arr, lb, ub);
        //Using divide and conquer method for left and right partitions and performing quick sort
        quicksort(arr, lb, loc - 1);
        quicksort(arr, loc + 1, ub);
    }
}
int partition(int arr[], int lb, int ub) // Function to find the partition element
{
    int pivot, start, end;
    pivot = arr[lb];
    start = lb;
    end = ub;
    while (start < end)
    {
        while (arr[start] <= pivot)
            start++;
        while (arr[end] > pivot)
            end--;
        if (start < end)
        {
            //Swappig the start and end elements of the arrays when start <end
            int temp;
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
    int temp2;
    temp2 = arr[lb];
    arr[lb] = arr[end];
    arr[end] = temp2;

    return end;
}