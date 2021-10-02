//Program to find the lowest common ancestor of two nodes in a binary tree

#include<iostream>
using namespace std;

//Definition for node of a binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//Recursive program to find the lowest common ancestor of Node p & Node q where root is the root of binary tree
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode *left, *right;

    if(!root)
        return root;

    if(root == p || root == q)
        return root;

    left = lowestCommonAncestor(root->left, p, q);
    right = lowestCommonAncestor(root->right, p, q);

    if(left && right)
        return root;

    return left?left:right;
}
