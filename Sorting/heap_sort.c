#include<stdio.h>

//Function for taking element of array from user
void get_array(int arr[],int size);

//Function to display element of array
void show_array(int arr[],int size);

//Swap two integer
void swap(int *first,int *second)
{
    int temp = *second;
    *second = *first;
    *first = temp;
}

//Index of parent
int indexOfParent(int i)
{
    return (i-1)/2;
}

//Index of left chlid
int indexOfLeftChild(int i)
{
    return 2*i+1;
}

//Index of right chlid
int indexOfRightChild(int i)
{
    return 2*i+2;
}

//maxHeapify
void maxHeapify(int *arr, int size,int i)
{
    int l = indexOfLeftChild(i);
    int r = indexOfRightChild(i);
    int largest = i;
    if(l<size && arr[l]>arr[largest])
        largest = l;
    if(r<size && arr[r]>arr[largest])
        largest = r;
    if(largest != i)
    {
        swap(&arr[i],&arr[largest]);
        maxHeapify(arr,size,largest);
    }
}

//Build max Heap from array
void buildHeap(int *arr, int size)
{
    for(int i=size/2-1;i>=0;i--)
    {
        maxHeapify(arr,size,i);
    }
}

//Heap sort
void heap_sort(int *arr, int size)
{
    buildHeap(arr,size);
    for(int i = size-1;i>0;i--)
    {
        swap(&arr[0],&arr[i]);
        maxHeapify(arr,i,0);
    }
    
}


//Driver Code

int main()
{
    int size;
    printf("Enter size of array:");
    scanf("%d",&size);

    int arr[size];

    printf("Enter array: ");
    get_array(arr,size);

    heap_sort(arr,size);

    printf("Sorted array: ");
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

/*Example
Enter size of array:5
Enter array: -8 55 1 0 4
Sorted array: -8 0 1 4 55
*/
