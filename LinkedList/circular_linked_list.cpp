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
        head->next=n;
        return;
    }
    
    node* temp =head;
    while (temp -> next != head)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    
}

void insertAtHead(node* &head,int val){
    node* n=new node(val);
    node* temp =head;
    while (temp -> next != head)
    {
        temp=temp->next;
    }
    n->next=head;
    head=n;
    temp->next=n;
}

void deletion(node* &head,int pos){
    node* temp=head;
    node* todelete;

    if (pos==1){
        while (temp->next!=head){
            temp=temp->next;
        }
        todelete=head;
        temp->next=head->next;
        head=head->next;
        delete todelete;
        return;
    }

    int count=1;
    while (count!=(pos-1) && temp->next!=head)
    {
        temp=temp->next;
        count++;
    }
    todelete=temp->next;
    
    
    temp->next=temp->next->next;
    delete todelete;
}

void display(node* head){
    node* temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    while(temp!=head);
    cout<<endl;
}

int main(){
    node* head=NULL;
    insertAtTail(head,2);
    insertAtTail(head,5);
    insertAtHead(head,7);
    insertAtHead(head,1);
    insertAtTail(head,9);
    insertAtTail(head,8);
    insertAtTail(head,21);
    display(head);

    deletion(head,7);
    display(head);
    deletion(head,1);
    display(head);
    
 return 0;
}
