#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};

void insert(ListNode* head, int x){
	ListNode* cur = head;
	while ( cur->next != NULL )
		cur = cur->next;
	ListNode *node = new ListNode(x);
	cur->next = node;
	return;
}

void traverse(ListNode* head){
	ListNode* cur = head;
	while ( cur != NULL ){
		cout << cur->val << " ";
		cur = cur->next;
	}
	return;
}

ListNode* reverse(ListNode* start, ListNode* end){
	ListNode* dnode = new ListNode(0);
	dnode->next = start;
	start = start->next;
	dnode->next->next = end;
	
	while ( start != end ){
		ListNode *tmp = start;
		start = start->next;
		tmp->next = dnode->next;
		dnode->next = tmp;
	}
	return dnode->next;
}

ListNode* reverseKGroup(ListNode *head, int k){
	
	if ( k == 0 || k == 1 || head == NULL )
		return head;
	ListNode* dnode = new ListNode(0);
	dnode->next = head;
	ListNode* slow = head;
	ListNode* fast = head;
	ListNode* pre1 = dnode;
	//ListNode* pre2 = dnode;
	
	while ( true ){
		
		int counter = 0;
		while ( fast != NULL && counter != k ){
			if ( counter != k -1 )
				pre1 = pre1->next;
			fast = fast->next;
			counter++;
		}
		
	
		if ( counter == k ){
			ListNode *start = reverse(slow, fast);
			if ( slow == head )
				dnode->next = start;
			else
				pre1->next = start;
			slow = fast;
			pre1 = start;
		}
		else
			break;
	}
	return dnode->next;
}

int main(){
	int a[] = {2, 3, 4, 5, 6, 7};
	ListNode* head = new ListNode(1);
	for ( int i = 0; i < 6; i ++ )
		insert(head, a[i]);
	traverse(head);
	ListNode* result = reverseKGroup(head, 4);
	cout << endl;
	traverse(result);
	return 0;
}
