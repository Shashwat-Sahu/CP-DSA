#include "bits/stdc++.h"
using namespace std;
struct node
{
    int data;
    struct node *left, *right;
    node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};
bool balancedHeight(struct node *root, int *height)
{
    if (root == NULL)
        return true;
    int l = 0, r = 0;
    if (balancedHeight(root->left, &l) == false)
        return false;
    if (balancedHeight(root->right, &r) == false)
        return false;
    *height = max(l, r) + 1;
    if (abs(l - r) <= 1)
        return true;
    else
        return false;
}
int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);

    int height = 0;
    if (balancedHeight(root, &height) == true)
        cout << "balanced tree";
    else if (balancedHeight(root, &height) == false)
        cout << "not balanced";
    return 0;
}