#include<bits/stdc++.h>
//#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }

};

void insertAtTail(node* &head, int val){
    node* n=new node(val);

    if (head==NULL)
    {
        head=n;
        return;
    }
    
    node* temp =head;
    while (temp -> next != NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    
}

void insertAtHead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    head=n;
}

void display(node* head){
    node* temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
node* rev_k_nodes(node* &head, int k){
    int temp=k;
    node* curr=head;
    node* pre=NULL;
    node* nxt;
    while((curr!=NULL) && (temp>0)){
        nxt=curr->next;
        curr->next=pre;

        pre=curr; 
        curr=nxt;
        temp--;
    }
    if(nxt!=NULL){
        head->next = rev_k_nodes(nxt,k);
    }

    return pre;
}

int main(){
    node* head=NULL;
    insertAtTail(head,2);
    insertAtTail(head,5);
    insertAtTail(head,7);
    insertAtHead(head,9);
    insertAtHead(head,5);
    insertAtHead(head,1);
    insertAtTail(head,7);
    insertAtTail(head,2);
    display(head);
    
    display(rev_k_nodes(head,3));
 return 0;
}
