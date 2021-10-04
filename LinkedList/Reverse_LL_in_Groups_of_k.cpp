//program for reversing linked list in groups of k
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

//function for reversing in groups of k

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        
        if(head==NULL||head->next==NULL)
        return head;
        int count=0;
        struct node *curr=head;
        struct node *prev=NULL;
        struct node *next;
        while(curr!=NULL&&count<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        if(next!=NULL)
        head->next=reverse(next,k);
        
        return prev;
    }
};



int main()
{
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return 0;
}
