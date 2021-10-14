#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
}; 

void rightView(node* root){

    if(!root)return;

    queue<node*>q;
    q.push(root);

    while(!q.empty()){
        
        int n = q.size();
        for (int i=0; i<n; i++)
        {
            node* curr = q.front();
            q.pop();

            if(i == n-1)
            cout<<curr->data<<" ";

            if(curr->left)
            q.push(curr->left);

            if(curr->right)
            q.push(curr->right);                   
        }
               
    }

}

void leftView(node* root){

    if(!root)return;

    queue<node*>q;
    q.push(root);

    while(!q.empty()){
        
        int n = q.size();
        for (int i=0; i<n; i++)
        {
            node* curr = q.front();
            q.pop();

            if(i == 0)
            cout<<curr->data<<" ";

            if(curr->left)
            q.push(curr->left);

            if(curr->right)
            q.push(curr->right);                   
        }
               
    }

}

int main(){
 
    /*
            1             Right view: 1, 3, 7
           / \
          2   3           Left View: 1, 2, 4
         / \ / \
        4  5 6  7
*/
    node *root = new node(1);
    root->left = new node(2);    
    root->right = new node(3);  
    root->left->left = new node(4);  
    root->left->right = new node(5);
    root->right->left = new node(6);  
    root->right->right = new node(7);  

    rightView(root);
    cout<<endl;
    leftView(root);
 
    return 0;
}