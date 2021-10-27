#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* pre;
    node(int val){
        data=val;
        next=NULL;
        pre=NULL;
    }
};

void insert_at_tail(node* &head,int val){
    node* x=new node(val);

    if (head==NULL)
    {
        head=x;
        return;
    }
    node* temp=head;
    while (temp->next!=NULL)
    temp=temp->next;
    temp->next=x;
    x->pre=temp;
    
}

void insert_at_head(node* &head,int val){
    node* x=new node(val);
    if (head==NULL)
    {
        head=x;
        return;
    }
    head->pre=x;
    x->next= head;
    head=x;

}

void deletion(node* &head,int pos){
    node* temp=head;
    int count=1;
    while (temp!=NULL && count!=pos)
    {
        temp=temp->next;
        count++;
    }
    if (temp==NULL)
        return;
    if (temp->next==NULL && temp->pre==NULL)
    {
        head=NULL;
        delete temp;
    }
    
    if (temp->next==NULL)
    {
        temp->pre->next=NULL;
        delete temp;
        return;
    }
    if (temp->pre==NULL)
    {
        temp->next->pre=NULL;
        head=temp->next;
        delete temp;
        return;
    }
    
    temp->pre->next=temp->next;
    temp->next->pre=temp->pre;

    delete temp;
}

void display(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    cout<<"hello"<<endl;
    node* head=NULL;
    insert_at_tail(head,5);
    insert_at_tail(head,2);
    insert_at_head(head,7);
    insert_at_head(head,12);
    insert_at_tail(head,4);
    insert_at_head(head,4);
    insert_at_tail(head,19);
    insert_at_head(head,9);

    display(head);
    deletion(head,3);
    display(head);
    deletion(head,1);
    display(head);
    
 return 0;
}
