#include<bits/stdc++.h>
using namespace std;
 
struct node{
    int data;
    node* left = NULL;
    node* right = NULL;
    
    node(int val){

        data = val;
        left = NULL;
        right = NULL;
    }
};

void zigzag(node* root){

    if(!root)
        return;

    stack<node*> currlevel;  // stores curr level nodes
    stack<node*> nextlevel;  // stores next level nodes

    bool leftToRight = true;
    
    currlevel.push(root);

    while(!currlevel.empty()){

        node* temp = currlevel.top();
        currlevel.pop();

        if(temp){
            cout<<temp->data<<" ";
        
        // Left to Right
        if(leftToRight){

            if(temp->left)
                nextlevel.push(temp->left);
            
            if(temp->right)
                nextlevel.push(temp->right);
        }

        // Right to Left
        else{

            if(temp->right)
                nextlevel.push(temp->right);
            
            if(temp->left)
                nextlevel.push(temp->left);
            }       
        }  

        // When a level ends
        if(currlevel.empty()){
            leftToRight = !leftToRight;
            swap(currlevel, nextlevel);
        }   
    }
}

int main(){
 
    /*
            12
           /  \
          9   15
         / \
        5  10 
    */

    node* root = new node(12);
    root->left = new node(9);
    root->right = new node(15);
    root->left->left = new node(5);
    root->left->right = new node(10);

    zigzag(root);
    cout<<endl;
 
    return 0;
}