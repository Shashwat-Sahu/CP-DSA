#include<stdio.h>
#include<limits.h>

//Merge procedure
void merge(int A[],int p,int q,int r)
{
    int n1 = q-p+1;
    int n2 = r-(q+1)+1;

    int L[n1+1] , R[n2+1];

    for (int i = 0; i < n1; i++)
    {
        L[i] = A[p+i];
    }
    
    for (int j = 0; j < n2; j++)
    {
        R[j] = A[q+1+j];
    }

    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    int i = 0;
    int j = 0;

    for (int k = p; k <= r; k++)
    {
        if(L[i]<=R[j])
        {
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
    }
    
    
}

//Merge Sort
void merge_sort(int A[],int p,int r)
{
    int q;
    if(p<r)
    {
        q = (p+r)/2;
        merge_sort(A,p,q);
        merge_sort(A,q+1,r);
        merge(A,p,q,r);
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
    
    merge_sort(A,0,n);

    printf("Element of array in sorted order: ");

    for(int i = 0; i < n; i++)
    {
        printf("%d ",A[i]);
    }

    return 0;
}

/*
Enter the size of array: 7
Enter the element of array: 0 -8 54 9 7 18 45
Element of array in sorted order: -8 0 7 9 18 54 456
*/