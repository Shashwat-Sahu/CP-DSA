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

void merge_ll(node* head1,node* head2,int pos){
    node* temp1=head1;
    node* temp2=head2;
    pos--;
    while (pos--)
    {
        temp1=temp1->next;
    }
    while (temp2->next!=NULL)
    {
        temp2=temp2->next;
    }
    temp2->next=temp1;
}

int length(node* head){
    int count=0;
    while (head!=NULL)
    {
        head=head->next;
        count++;
    }
    return count;
}

int intersection(node* &head1,node* &head2){
    int l1=length(head1),l2=length(head2);
    node* temp1=head1;
    node* temp2=head2;
    if(l1>l2){
        int x=(l1-l2);
        while (x--)
        temp1=temp1->next;
    }
    if(l2>l1){
        int y=(l2-l1);
        while (y--)
        temp2=temp2->next;
    }
    while (temp1!=NULL && temp2!=NULL)
    {
        if (temp1==temp2)
        {
            return temp1->data;
        }
        
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return -1;
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
    node* head1=NULL;
    insertAtTail(head1,2);
    insertAtTail(head1,5);
    insertAtTail(head1,7);
    insertAtTail(head1,11);
    insertAtTail(head1,16);
    insertAtTail(head1,21);
    display(head1);
    
    node* head2=NULL;
    insertAtTail(head2,3);
    insertAtTail(head2,4);
    insertAtTail(head2,8);
    insertAtTail(head2,13);
    insertAtTail(head2,14);
    display(head2);
    
    merge_ll(head1,head2,3);
  
    cout<<intersection(head1,head2);
 return 0;
}
