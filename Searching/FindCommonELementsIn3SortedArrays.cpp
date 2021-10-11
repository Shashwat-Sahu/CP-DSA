// https://practice.geeksforgeeks.org/problems/common-elements1132/1
// Love babbar DSA-450 Question-19
#include<iostream>
#include<vector>
#define null NULL
using namespace std;
typedef long long itn;
int max(int a,int b,int c){
    return max(a,max(b,c));
}
vector <int> commonElements (int a[], int b[], int c[], int n1, int n2, int n3){
    vector<int> cmmnElements;
    int i=0,j=0,k=0;
    while(i<n1&&j<n2&&k<n3){
        if(a[i]==max(a[i],b[j],c[k])){
            while(j<n2&&b[j]<a[i])  j++;
            while(k<n3&&c[k]<a[i])  k++;
        }
        else if(b[j]==max(a[i],b[j],c[k])){
            while(i<n1&&a[i]<b[j])  i++;
            while(k<n3&&c[k]<b[j])  k++;
        }
        else if(c[k]==max(a[i],b[j],c[k])){
            while(j<n2&&b[j]<c[k])  j++;
            while(i<n1&&a[i]<c[k])  i++;
        }

        if(i>=n1||j>=n2||k>=n3)    break;

        if(a[i]==b[j]&&b[j]==c[k]){
            if(cmmnElements.size()&&*(cmmnElements.end()-1)==a[i])  cmmnElements.pop_back();
            cmmnElements.push_back(a[i]);
            if(i==n1-1||j==n2-1||k==n3-1)   break;

            if(a[i+1]==max(a[i+1],b[j+1],c[k+1]))   i++;
            else if(b[j+1]==max(a[i+1],b[j+1],c[k+1]))   j++;
            else if(c[k+1]==max(a[i+1],b[j+1],c[k+1]))   k++;

        }  

    }
    return cmmnElements;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    int a[n1],b[n2],c[n3];
    for(auto &i:a)  cin>>i;
    for(auto &i:b)  cin>>i;
    for(auto &i:c)  cin>>i;
    
    vector<int> cmmn=commonElements(a,b,c,n1,n2,n3);
    for(auto i:cmmn)    cout<<i<<" ";
    
    return 0;
}