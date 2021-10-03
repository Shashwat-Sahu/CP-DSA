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

    bool f(TreeNode *root1, TreeNode* root2) {
        if(!root1) return !root2;
        if(!root2) return !root1;
        return (root1->val == root2->val) && f(root1->left, root2->right) && f(root1->right, root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return f(root->left, root->right);
    }
    
int main(){
    struct TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(2);
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(5);
    ll x=isSymmetric(root);
    cout<<x<<endl;
}
