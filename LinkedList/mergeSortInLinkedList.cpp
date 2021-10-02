#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

void findMiddle(Node *p, Node **first, Node **second){
    Node *fast, *slow;
    slow = p;
    fast = p->next;
    
    while(fast != NULL){
        fast = fast->next;
        if(fast){
            slow = slow->next;
            fast = fast->next;
        }
    }
    
    *first = p;
    *second = slow->next;
    slow->next = NULL;
}

Node* merge(Node *first, Node *second){
    Node* ans = NULL;
    
    // If anyone of them becomes null(empty)
    // then simply return it.
    if(!first){
        return second;
    }else if(!second){
        return first;
    }
    
    if(first->data <= second->data){
        ans = first;
        ans->next = merge(first->next, second);
    }else{
        ans = second;
        ans->next = merge(first, second->next);
    }
    
    return ans;
}

Node* mergeS(Node *head){
    Node *p = head;
    Node *first, *second;
    
    if(!p || !p->next)
        return p;
        
    findMiddle(p, &first, &second);
    
    first = mergeS(first);
    second = mergeS(second);
    return merge(first, second);
}

Node* mergeSort(Node* head) {
    return mergeS(head);
}

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
		freopen("outputf.txt", "w", stdout);
	#endif
	
	struct Node* a = NULL;
    long n, tmp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        push(&a, tmp);
    }
    
    mergeSort(a);
    printList(a);
	
	return 0;
}

