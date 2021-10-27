#include <bits/stdc++.h>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;


BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
vector<int>create(BinaryTreeNode<int> *root)
{
    vector<int>ans;
    if(root==NULL)
        return ans;
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    
    while(!q.empty())
    {
        BinaryTreeNode<int>* node=q.front();
        ans.push_back(node->data);
        q.pop();
        if(node->left!=NULL)
        {
            q.push(node->left);
        }
        if(node->right!=NULL)
        {
            q.push(node->right);
        }
    }
    return ans;
}
void pairSum(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
    
    if(root==NULL)
        return;
    vector<int>ans=create(root);
    
   sort(ans.begin(),ans.end());
    
    int i=0;
    int j=ans.size()-1;
    
    while(i<j)
    {
        if(ans[i]+ans[j]>sum)
        {
            j--;
        }
        else if(ans[i]+ans[j]<sum)
        {
            i++;
        }
        else{
            cout<<ans[i]<<" "<<ans[j]<<endl;
            i++;
            j--;
        }
    }
    
    
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int sum;
    cin >> sum;
    pairSum(root, sum);
    delete root;
}