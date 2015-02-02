#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};

void insert(ListNode *head, int x){
	ListNode *cur = head;
	while (cur->next != NULL)
		cur = cur->next;
	ListNode *node = new ListNode(x);
	cur->next = node;
	return;
}

void traverse(ListNode *head){
	ListNode *cur = head;
	while ( cur != NULL ){
		cout << cur->val << " ";
		cur = cur->next;
	}
	return;
}

bool hasCycle(ListNode *head){
	
    if ( head == NULL )
 		return NULL;
	
 	ListNode* slow = head;
 	ListNode* fast = head;
	
 	while ( fast != NULL && fast->next != NULL ){
 		slow = slow->next;
 		fast = fast->next->next;
		
 		if ( slow == fast )
 			return true;
 	}
	
 	return false;
}


int main(){
	int a[] = { 2, 3, 3, 4, 4, 5};
	ListNode *head = new ListNode(1);
	for ( int i = 0; i < 6; i++ )
		insert(head, a[i]);
	traverse(head);
	cout << endl;
	traverse(deleteDuplicates(head));
}
