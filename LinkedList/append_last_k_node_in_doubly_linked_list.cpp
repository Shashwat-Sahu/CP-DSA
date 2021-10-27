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

void append_k_node(node* &head,int val){
    node* temp=head;
    int len=0;
    node* tail;
    while (temp!=NULL){
        len++;
        if (temp->next==NULL)
        {
            tail=temp;
        }
        
        temp=temp->next;
    }
    // val=val%len;
    cout<<len<<"  ";
    int x=len-val;
    temp=head;
    cout<<x<<"  ";
    while (x--)
    {
        temp=temp->next;
    }
    cout<<(temp->data)<<endl;
    temp->pre->next=NULL;
    tail->next=head;
    head->pre=tail;
    temp->pre=NULL;
    head=temp;

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
    append_k_node(head,5);
    display(head);
    
 return 0;
}
