#include "bits/stdc++.h"
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
void levelTraversal(struct node *root)
{
    if (!root)
        return;
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *front = q.front();
        q.pop();
        if (front != NULL)
        {
            cout << front->data << " ";
            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
        }
        else if (!q.empty())
            q.push(NULL);
    }
}
/*
            1
          /  \
         2    3
       / \  / \
      4  5 6   7
*/
int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    levelTraversal(root);
    return 0;
}