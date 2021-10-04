#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void  permute(vector<int> &arr,int idx){
    if (idx==arr.size())
    {
        ans.push_back(arr);
        return;
    }
    for (int i = idx; i < arr.size(); i++)
    {
        swap(arr[i],arr[idx]);
        if((i != idx) && (arr[i]==arr[idx])){
            continue;
        }
        permute(arr,idx+1);
        swap(arr[i],arr[idx]);

        while ((arr[i]==arr[i+1]) && ((i+1)<arr.size()))
        {
            i++;
        }

    }
    return;
    
}
int main(){
    // array with distinct integer
    int n;
    cin>>n;
    vector<int> arr(n);
    for (auto &i :arr){
        cin>>i;
    }
    sort(arr.begin(),arr.end());

    permute(arr,0);

  //build in function
//     do 
//     {
//         ans.push_back(arr);
//     } while (next_permutation(arr.begin(),arr.end()));
    

    cout<<endl;
    for(auto v:ans){
        for (auto i: v)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    
 return 0;
}
