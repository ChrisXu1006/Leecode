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

ListNode *rotateRight(ListNode *head, int k){
	
	if ( head == NULL || head->next == NULL )
		return head;
	
	ListNode* dhead = new ListNode(0);
	dhead->next = head;
	
	int counter = 0;
	ListNode* fast = head;
	
	while ( counter < k ){
		fast = fast->next;
		if ( fast == NULL )
			fast = head;
		counter++;
	}
	
	if ( fast == head )
		return head;
	
	ListNode* slow = head;
	while ( fast->next != NULL ){
		fast = fast->next;
		slow = slow->next;
	}
	
	ListNode* nhead = slow->next;
	slow->next = NULL;
	dhead->next = nhead;
	fast->next = head;
	
	return dhead->next;
}

int main(){
	int a[] = { 2, 3, 4, 5};
	ListNode *head = new ListNode(1);
	for ( int i = 0; i < 4; i++ )
		insert(head, a[i]);
	traverse(head);
	cout << endl;
	traverse(rotateRight(head, 6));
}
