#include<bits/stdc++.h> 
#define ll long long int
using namespace std;

struct TreeNode{
    ll val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(ll data){
        val=data;
        left=right=NULL;
    }
};

bool getPath(TreeNode *root, vector<ll> &arr, ll x) {
    // if root is NULL
    // there is no path
    if (!root)
        return false;
     
    arr.push_back(root->val);   
 
    if (root->val == x)   
        return true;
 
    if (getPath(root->left, arr, x) ||
        getPath(root->right, arr, x))
        return true;  
    arr.pop_back();
    return false;  
}
vector<ll> solve(TreeNode* A, ll B) {
    vector<ll> arr; 
    if(A == NULL) {
        return arr; 
    }
    getPath(A, arr, B);
    return arr; 
}
    
int main(){
    struct TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(5);
    vector<ll> v=solve(root,3);
    for(auto i:v)
        cout<<i<<" ";
}
