#include<bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define vi vector<int>
#define pi pair<int,int>
#define que queue<int>
#define sta stack<int>
#define ll long long
#define lb cout<<endl
#define mod 1000000007
#define cin(a) int i;for(auto &i:a)cin>>i
#define cout(a) int j;for(auto &j:a)cout<<j

map<int ,vi>mp;
struct node {
    int data;
    node *left,*right;
    node(int val){
        data = val;
        left=NULL;
        right=NULL;
    }
};

void vertical_traversal(node *root,int hd){
    if(root == NULL)
    return; 
    
    mp[hd].push_back(root->data);
    vertical_traversal(root->left,hd-1);
    vertical_traversal(root->right,hd+1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    node *root=new node(10);
    root->left=new node(7);
    root->left->left=new node(3);
    root->left->right=new node(11);
    root->right=new node(4);
    root->right->left=new node(14);
    root->right->right=new node(16);
    
    vertical_traversal(root,0);

    map<int,vi>::iterator it;
    for(it=mp.begin();it!=mp.end();it++){
        cout<<it->first<<" ";
        int i=0;
        while(i<it->second.size()){
            cout<<it->second[i]<<" ";
            i++;
        }
        lb;
    }

    return 0;
}