#include <iostream>
#include <math.h>
using namespace std;

#define K 10
#define M 10
#define DIF 2147483648



void counting_sort(int  arr[], int   n, int  p) {
    int  element = pow(10, p);
    int  divs = element / 10;
    int  count[M];
    for(int  i = 0; i < M; i++)
        count[i] = 0;
    for(int  i = 0; i < n; i++)
        count[(arr[i] % element) / divs] ++;
    for(int  i = 1; i < M; i++)
        count[i] += count[i-1];
    int  op[n];
    for(int  i = n-1; i >= 0; i--) {
        op[count[(arr[i] % element) / divs] - 1] = arr[i];
        count[(arr[i] % element) / divs] --;
    }
    
    for(int  i = 0; i < n; i++)
        arr[i] = op[i];
}

void radix_sort(int  arr[], int  n) {
 
    for(int  i = 1; i <= K; i++)
        counting_sort(arr, n, i);
}

int main() {    
    int  n;
    cout<<"Enter size of array: ";
    cin >> n;
    int  arr[n];
    cout<<"\nEnter the elements of array: ";
   
    for(int  i = 0; i < n; i++) {
        cin >> arr[i];
        
        arr[i]+=DIF;
    }
    
    radix_sort(arr, n);

    cout<<"\n Sorted array: "   
    for(int  i = 0; i < n; i++) {
        cout << arr[i]-DIF << ' ';
    }
    cout << '\n';
    return 0;
}