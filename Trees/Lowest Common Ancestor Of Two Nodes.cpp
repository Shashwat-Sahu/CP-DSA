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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if (root == NULL || root == p || root == q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        //result
        if(left == NULL) {
            return right;
        }
        else if(right == NULL) {
            return left;
        }
        else { //both left and right are not null, we found our result
            return root;
        }
    }
    
int main(){
    struct TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    struct TreeNode *p=root->left->right=new TreeNode(4);
    struct TreeNode *q=root->right->left=new TreeNode(5);
    TreeNode* x=lowestCommonAncestor(root,p,q);
    cout<<x->val;
}
