#include<stdio.h>

//Function for quick sort
void quick_sort(int A[],int p,int r);

//Function for partitionig the array
int partition(int A[],int p,int r);

//Fuction for swaping two element
void swap(int *a,int *b);

//Function for taking element of array from user
void get_array(int arr[],int size);

//Function to display element of array
void show_array(int arr[],int size);

int main()
{
    int size;

    printf("Enter size of array: ");
    scanf("%d",&size);

    int arr[size];

    printf("Enter element of array: ");
    get_array(arr,size);

    quick_sort(arr,0,size-1);

    printf("Element of array in sorted order: ");
    show_array(arr,size);

    return 0;
}

void get_array(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
}

void show_array(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}

void swap(int *a,int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

int partition(int A[],int p,int r)
{
    int x = A[p];
    int i = p+1;
    for(int j=p+1;j<=r;j++)
    {
        if(A[j]<x)
        {
            swap(&A[i],&A[j]);
            i += 1;
        }
    }
    swap(&A[i-1],&A[p]);
    return i-1;
}

//first element as pivot
void quick_sort(int A[],int p,int r)
{
    if(p<r)
    {
        int q = partition(A,p,r);
        quick_sort(A,p,q-1);
        quick_sort(A,q+1,r);
    }
}