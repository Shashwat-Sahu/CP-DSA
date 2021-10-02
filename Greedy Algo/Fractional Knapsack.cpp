// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool sortbydesc(const pair<double,int> &a,
                   const pair<double,int> &b)
{
       return a.first>b.first;
}
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        double ans=0.0;
        vector<pair<double,int>>v;
        for(int i=0;i<n;i++){
            v.push_back(make_pair(((double)arr[i].value/arr[i].weight),arr[i].weight));
        }
        sort(v.begin(),v.end(),sortbydesc);

        int s=0;
        int i=0;
        while(i<n){
            if(v[i].second+s<=W){
                ans+=(double)v[i].first*v[i].second;
                s+=v[i].second;
            }
            else
            {
                ans+=((W-s))*v[i].first;
                break;
            }
            i++;
        }
        return ans;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends
