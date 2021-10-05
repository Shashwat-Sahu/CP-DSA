#include<bits/stdc++.h>
#define ll long long int
using namespace std;

struct Node{
    ll data;
    struct Node *left;
    struct Node *right;
    Node(ll val){
        data=val;
        left=right=NULL;
    }
};

bool isSameTree(Node* p, Node* q) {
        if(!p) return !q;
        if(!q) return !p;
        return (p->data == q->data) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

int main(){
    struct Node *root1=new Node(1);
    root1->left=new Node(2);
    root1->right=new Node(3);
    root1->left->right=new Node(5);
    
    struct Node *root2=new Node(1);
    root2->left=new Node(2);
    root2->right=new Node(3);
    root2->left->right=new Node(5);
    
    ll x=isSameTree(root1,root2);
    cout<<x<<endl;
}
