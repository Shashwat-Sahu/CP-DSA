#include<stdio.h>

void insertion_sort(int A[],int n)
{
    int key;

    for (int j = 0; j < n; j++)
    {
        key = A[j];

        int i = j-1;
        
        while (i>-1 && A[i]>key)
        {
            A[i+1] = A[i];
            i = i - 1;
        }
        
        A[i+1] = key;
    }
    
    
}

int main()
{
    int n;
    
    printf("Enter the size of array: ");
    scanf("%d",&n);

    int A[n];

    printf("Enter the element of array: ");

    for(int i = 0; i < n; i++)
    {
        scanf("%d",&A[i]);
    }
    
    insertion_sort(A,n);

    printf("Element of array in sorted order: ");

    for(int i = 0; i < n; i++)
    {
        printf("%d ",A[i]);
    }

    return 0;
}