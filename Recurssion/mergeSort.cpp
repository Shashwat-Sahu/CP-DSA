#include <iostream>
using namespace std;
void mergeSortHelper(int input[],int l,int h){
    if(l>=h)
        return;
    int m=(l+h)/2;
    mergeSortHelper(input,l,m);
    mergeSortHelper(input,m+1,h);
    int output[h+1];
    int k = 0;
    int i = l, j = m+1;
    while(i <= m && j <= h) {
        if(input[i] <= input[j])
            output[k] = input[i++];
        else
            output[k] = input[j++];
        k++;
    }
    while(i<=m)
        output[k++] = input[i++];
    
    while(j<=h)
        output[k++] = input[j++];
    for(int i=0;i<k;i++)
        input[i+l]=output[i];
    return;
}
void mergeSort(int input[], int size){
	// Write your code here
    if(size<=1)
        return;
    int l =0;
    int h =size-1;
    mergeSortHelper(input,l,h);
}

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}