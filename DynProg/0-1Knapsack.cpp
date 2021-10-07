// Tabulation (Bottom Up) Approach
// Time complexity = O(n*w)
// Space complexity = O(n*w)


#include<bits/stdc++.h>
using namespace std;

int knapSack(int w, int wt[], int val[], int n) 
{ 
    int t[n+1][w+1];

    // Table initialisation
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < w+1; j++){
            if(i==0 || j==0)
                t[i][j] = 0;
        }
    }
    
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < w+1; j++){
            
            if(wt[i-1]<=j)
                t[i][j] = max(val[i-1]+t[i-1][j-wt[i-1]], t[i-1][j]);
                
            else
                t[i][j] = t[i-1][j];
        }
    }
    
    return t[n][w];
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, w;  // Input the size of array(n) and capacity(w)
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        for(int i=0;i<n;i++) cin>>val[i];    // input value array
        for(int i=0;i<n;i++) cin>>wt[i];     // input weight array
        
        cout<<knapSack(w, wt, val, n)<<endl;
    }

	return 0;
}