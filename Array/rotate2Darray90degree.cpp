#include<bits/stdc++.h>
using namespace std;

//function to rotate the array
void rotate(vector<vector<int> > &A) {
    int n=A.size();
    reverse(A.begin(),A.end());
   for(int i=0;i<A.size();i++)
   {
       for(int j=i+1;j<A[i].size();j++)
       {
           swap(A[i][j],A[j][i]);
       }
   }
}

int main()
{
    int n;
    cin>>n;
    //2D array 
    vector<vector<int>>v;
    int x;
    for(int i=0;i<n;i++)
    {
        vector<int>temp;
        for(int j=0;j<n;j++)
        {
            cin>>x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }
    rotate(v);
}
