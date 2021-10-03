//Program to construct Binary Search Tree from Preorder traversal.

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//Code to construct BST fom preorder traversal, where 'pre' is the preorder traversal
TreeNode *bstFromPreorder(vector<int> &pre)
{
    stack<TreeNode *> st;
    TreeNode *root = new TreeNode(pre[0]);
    st.push(root);
    int i;
    TreeNode *temp;

    for (int i = 1; i < pre.size(); i++)
    {
        temp = nullptr;
        while (st.size() && pre[i] > st.top()->val)
        {
            temp = st.top();
            st.pop();
        }
        if (temp)
        {
            temp->right = new TreeNode(pre[i]);
            st.push(temp->right);
        }
        else
        {
            (st.top())->left = new TreeNode(pre[i]);
            st.push((st.top())->left);
        }
    }
    return root;
}