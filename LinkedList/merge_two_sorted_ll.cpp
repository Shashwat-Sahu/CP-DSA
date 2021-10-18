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

node* merge_list(node* &head1,node* &head2){
    node* temp1=head1;
    node* temp2=head2;
    node* temp=new node(-1);

    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data < temp2->data){
            temp->next=temp1;
            temp1=temp1->next;
            temp = temp->next;
        }
        else{
            temp->next=temp2;
            temp2=temp2->next;
            temp = temp->next;
        }
    }
    while(temp1!=NULL){
        temp->next=temp1;
        temp1=temp1->next;
        temp=temp->next;
    }
    while(temp2!=NULL){
        temp->next=temp2;
        temp2=temp2->next;
        temp=temp->next;
    }
    
    return dummy->next;
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
    cout<<"hello"<<endl;
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

    node* newhead=merge_list(head1,head2);
    display(newhead);
 return 0;
}
