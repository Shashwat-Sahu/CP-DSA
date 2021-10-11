// https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1
// Love babbar DSA-450 Question-6
#include<iostream>
using namespace std;
typedef long long itn;

class node{
public:
    int data;
    node *left,*right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

node* placeNode(node* &root,int val){
    if(root==NULL)  return new node(val);
    
    if(root->data==val) return root;

    else if(root->data<val)  root->right=placeNode(root->right,val);
    else root->left=placeNode(root->left,val);
    return root;
}

int sizeofBST(node *root){
    if(root==NULL)  return 0;
    return 1+sizeofBST(root->left)+sizeofBST(root->right);
}

int doUnion(int a[],int n,int b[],int m){
    node* root=NULL;
    for(int i=0;i<n;i++)    root=placeNode(root,a[i]);
    for(int i=0;i<m;i++)    root=placeNode(root,b[i]);
    return sizeofBST(root);
}

int main(){

    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for(auto &i:a)  cin>>i;
    for(auto &i:b)  cin>>i;

    cout<<doUnion(a,n,b,m);
    
    
    return 0;
}