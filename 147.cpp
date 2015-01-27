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

ListNode *insertionSortLists(ListNode *head){
	
	if ( head == NULL )
		return 	NULL;
	
	if ( head->next == NULL )
		return head;
	
	ListNode *node1 = new ListNode(-1);
	ListNode *node2 = new ListNode(head->val);
	node1->next = node2;
	ListNode *cur = head->next;
	ListNode *pre = node1;
	ListNode *ncur = node1->next;
	
	while ( cur != NULL ){
		
		while ( ncur != NULL ){
			if ( ncur->val > cur->val )
				break;
			pre = pre->next;
			ncur = ncur->next;
		}
		ListNode *node = new ListNode(cur->val);
		pre->next = node;
		node->next = ncur;
		
		pre = node1;
		ncur = node1->next;
		
		cur = cur->next;
	}
	return node1->next;
}

int main(){
	int a[] = { 4, 10, 8, 22, 100, 11, 12, 10};
	ListNode *head = new ListNode(9);
	for ( int i = 0; i < 8; i++ )
		insert(head, a[i]);
	traverse(head);
	cout << endl;
	traverse(insertionSortLists(head));
}
