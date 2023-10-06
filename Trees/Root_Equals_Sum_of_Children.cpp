struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    bool checkTree(TreeNode *root)
    {
        if (root == nullptr)
            return false;
        if (root->left && root->right && root->val == (root->left->val + root->right->val))
            return true;
        if (checkTree(root->left) || checkTree(root->right))
            return true;
        return false;
    }
};