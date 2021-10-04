//program for reversing a linked list
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
    public:
    //function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // code here
        Node* prev=NULL;
        Node* curr=head;
        Node* NEXT;
        if(head==NULL||head->next==NULL)
        return head;
        while(curr!=NULL){
            NEXT=curr->next;
            curr->next=prev;
            prev=curr;
            curr=NEXT;
        }
        // return head of reversed list
        return prev;
    }
    
};
    
//function to traverse over the linked list and print it

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
       printf("%d ", temp->data);
       temp  = temp->next;
    }
}

int main()
{
        struct Node *head = NULL,  *tail = NULL;

     
        head = new Node(1);
        head->next=new Node(2);
        head->next=new Node(3);
        head->next=new Node(4);
        head->next=new Node(5);
        head->next=new Node(6);
        Solution ob;
        head = ob. reverseList(head);
        
        printList(head);
  // 6 5 4 3 2 1
        cout << endl;
    }
    return 0;
}
