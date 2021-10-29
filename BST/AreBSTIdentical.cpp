/*
Strategy:
1. If both empty, return true
2. If both non-empty, 
    a. Check that the data at nodes is equal.
    b. Check if left subtrees are same.
    c. Check if right subtrees are same.
3. If (a,b,c) are true, return true 
     else, return false
*/

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

bool isIdentical(node* root1, node* root2){

    if(!root1 && !root2)
        return true;

    else if(!root1 || !root2)
        return false;

    else{

        bool cond1 = root1->data == root2->data;
        bool cond2 = isIdentical(root1->left, root2->left);
        bool cond3 = isIdentical(root1->right, root2->right);

        if(cond1==true && cond2==true && cond3==true)
            return true;

        return false;
    }
}

int main(){
 
    node* root1 = new node(3);
    root1->left = new node(2);
    root1->right = new node(4);

    node* root2 = new node(3);
    root2->left = new node(2);
    root2->right = new node(5);
    

    if(isIdentical(root1, root1))
        cout<<"BSTs are identical"<<endl;
    else
        cout<<"BSTs are not identical"<<endl;


    if(isIdentical(root1, root2))
        cout<<"BSTs are identical"<<endl;
    else
        cout<<"BSTs are not identical"<<endl;


    return 0;
}
