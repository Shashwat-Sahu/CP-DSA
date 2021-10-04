// https://practice.geeksforgeeks.org/viewSol.php?subId=58bdb4aa62394291d57f659e2c839932&pid=703402&user=tomarshiv51
// Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	    // Your code goes here
	    int n=s.size(),j=0; int a[n]; a[0]=0;
	    int i=1;
	    while(i<n){
	        if(s[i]==s[j]){
	            a[i]=j+1; j++; i++;
	        }
	        else{
	            if(j==0){
                a[i]=0; i++;
	            }
	            else{
	                j=a[j-1];
	            }
	        }
	    }
	    return a[n-1];
	    
	}
};

// { Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
     cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends
