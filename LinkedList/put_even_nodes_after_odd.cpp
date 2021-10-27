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

void even_node_after_odd(node* &head){
    node* odd=head;
    node* evenhead=head->next;
    node* even=head->next;

    while (odd->next!=NULL && even->next!=NULL)
    {
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    odd->next=evenhead;
    
    // even->next=NULL;
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

int main(){
    node* head=NULL;
    insertAtTail(head,2);
    insertAtTail(head,5);
    insertAtTail(head,7);
    insertAtHead(head,9);
    insertAtHead(head,19);
    insertAtTail(head,5);
    insertAtTail(head,7);
    insertAtHead(head,1);
    insertAtHead(head,11);
    display(head);

    even_node_after_odd(head);
    display(head);

 return 0;
}
