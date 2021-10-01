#include "bits/stdc++.h"
using namespace std;
static int count = 0;
struct node
{
    int data;
    struct node *left;
    struct node *right;
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
// int calcHeight(node *root)
// {
//     if (root == NULL)
//         return 0;
//     int lHeight = calcHeight(root->left);
//     int rHeight = calcHeight(root->right);
//     return max(lHeight, rHeight) + 1;
// }
// int calDiameter(node *root)
// {
//     if (root == NULL)
//         return 0;
//     int lHeight = calcHeight(root->left);
//     int rHeight = calcHeight(root->right);
//     int currDiameter = lHeight + rHeight + 1;

//     int ldiameter = calDiameter(root->left);
//     int rdiameter = calDiameter(root->right);
//     return max((ldiameter, rdiameter), currDiameter);
// }
/*optimised code to calculate height by not calling the height function again and again rather
passing the height as a parameter*/
int caldiameter(node *root, int *height)
{
    if (root == NULL)
    {
        *height = 0;
        return 0;
    }
    int lheight = 0, rheight = 0;
    int ldiameter = caldiameter(root->left, &lheight);
    int rdiameter = caldiameter(root->right, &rheight);
    int currdiameter = lheight + rheight + 1;
    *height = max(lheight, rheight) + 1;
    return max(currdiameter, max(ldiameter, rdiameter));
}
int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    int height = 0;
    cout << "the diameter is " << caldiameter(root, &height);
    return 0;
}