/*
You are given an array arr[], you have to re-construct 
an array arr[].
The values in arr[] are obtained by doing Xor of 
consecutive elements in the array
At index 0, arr[0] xor arr[1] = 1
At index 1, arr[1] xor arr[2] = 10
At index 2, arr[2] xor arr[3] = 3
...
At index 4, No element is left So, it will remain as
it is.
New Array will be {1, 10, 3, 1, 3}.
*/

int *game_with_number(int arr[], int n)
{
    int i;

    i = 0;
    while (i < n - 1)
    {
        arr[i] = arr[i] ^ arr[i + 1];
        i++;
    }
    return (arr);
}