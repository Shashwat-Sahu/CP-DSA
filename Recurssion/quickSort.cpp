#include<iostream>
using namespace std;

int partition(int input[],int si,int ei){
    int pivot=input[si];
    int count=0;
    for (int i=si+1;i<=ei;i++)
    {
        if(input[i]<=pivot)
            count=count+1;
    }
    count =count+si;
    int temp=input[count];
    input[count]=input[si];
    input[si]=temp;
    int i=si;int j=ei;
    while(i<=count && j>count)
    {
        while(input[i]<=pivot)
        	i++;
    	while(input[j]>pivot)
        	j--;
    	if(i<count && j>count)
    	{
        	int temp = input[i];
        	input[i]=input[j];
        	input[j]=temp;
        	i++;
        	j--;
    	}
    }
    return count;
}
void quickSort(int input[],int si,int ei){
    if(si>=ei)
        return;
    int c=partition(input,si,ei);
    quickSort(input,si,c-1);
    quickSort(input,c+1,ei);
}
void quickSort(int input[], int size) {
	quickSort(input,0,size-1);
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}