#include <iostream>
using namespace std;
 
// Link list node
class Node {
    int data;
    Node* next;
    Node(int data)
    {
        data = data;
        next = NULL;
    }
};
 
 LinkedList {
    Node* head;
    LinkedList()
    { 
     head = NULL; 
    }
 
    /* Function to reverse the linked list */
    void reverse()
    {
        // Initialize current, previous and
        // next pointers
        Node* current = head;
        Node *prev = NULL;
 
        while (current != NULL) {
            // Store next
            Node *next = current->next;
 
            // Reverse current node's pointer
            current->next = prev;
 
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
    }
 
    /* Function to print linked list */
    void print()
    {
         Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
 
    void push(int data)
    {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};
 
/* Driver code*/
int main()
{
    /* Start with the empty list */
    LinkedList ll;
 
 int size;
 cout<<"Enter Size of list : ";
 cin>>size;
 for(int i=0;i<size;i++)
 {
  int x;
  cin>>x;
 ll.push(x);
 }
  
    cout << "Given linked list\n";
    ll.print();
 
    ll.reverse();
 
    cout << "\nReversed Linked list \n";
    ll.print();
    return 0;
}
