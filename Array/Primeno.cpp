// Printing Prime numbers from 1-100
#include <stdio.h>

int main()
{

    int i, k;
    int primenum[50];
    int count = 0;

    for (k = 1; k <= 100; k++)
    {
        int flag = 0;
        for (i = 2; i < k; i++)
        {
            if (k % i == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            primenum[count] = k;
            count++;
        }
    }

    printf("Prime numbers between 1 to 100 are: \n");
    int j = 0;
    for (j = 0; j < count; j++)
    {
        printf("%d", primenum[j]);
        printf("\n");
    }

    return 0;
}