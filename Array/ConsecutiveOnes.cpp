#include<bits/stdc++.h>
using namespace std;
int ConsecutiveOnes(int arr[],int n){
	int res=0,c=0;
	for(int i=0;i<n;i++){
// if 0 then count begins from 0
		if(arr[i]==0){
			c=0;
		}else{
			c++;
			res=max(res,c);
		}
	}
}
int main(){
	int arr[]={0,1,1,0,1,0};
	int n=6;
	cout<<ConsecutiveOnes(arr,n);
	return 0;
}