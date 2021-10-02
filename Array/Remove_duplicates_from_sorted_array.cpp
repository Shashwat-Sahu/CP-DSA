//Given a sorted array, the task is to remove the duplicate elements from the array.
#include <bits/stdc++.h>
using namespace std;

// return the number of distinct elements in array
int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if(n == 0 ){return 0 ;}
    int x = nums[0];
    int j = 1;
    for(int i = 1 ; i < n ; i++){
        if( x != nums[i]){
            nums[j] = nums[i];
            x = nums[i];
            j += 1 ;
        }
    }
    return j;
}

int main(){
    int N; //size of array
    cin>>N;
    vector<int> arr(N);
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }
    
    int ans = removeDuplicates(arr);

    //prints the array after removing duplicates.
    for(int i=0;i<ans;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}  

//Time Complexity : O(n) 
