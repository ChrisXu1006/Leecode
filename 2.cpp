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
};

void init(ListNode *head, int x){
	head->val = x;
	head->next = NULL;
}

void insert(ListNode *head, int x){
	ListNode* cur = head;
	while (cur->next != NULL)
		cur = cur->next;
	ListNode* newnode = new ListNode();
	newnode->val = x;
	newnode->next = NULL;
	cur->next = newnode;
}

void traverse(ListNode *head){
	ListNode *cur = head;
	while ( cur != NULL ){
		cout << cur->val << " ";
		cur = cur->next;
	}
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){
	
	int carry = 0;
	
	if ( l1 == NULL && l2 == NULL )
		return NULL;
	
	if ( l1 == NULL )
		return l2;
	
	if ( l2 == NULL )
		return l1;
	
	ListNode *cur1 = l1;
	ListNode *cur2 = l2;
	
	ListNode *res = new ListNode();
	res->val = 0;
	res->next = NULL;
	ListNode *cur = res;
	
	
	while ( cur1 != NULL && cur2 != NULL ){
		int digit = cur1->val + cur2->val + carry;
		ListNode *node = new ListNode();
		node->next = NULL;
		
		if ( cur1->val + cur2->val + carry >= 10 ){
			carry = 1;
			node->val = digit - 10;
		}
		
		else{
			carry = 0;
			node->val = digit;
		}
		
		cur->next = node;
		cur = cur->next;
		cur1= cur1->next;
		cur2= cur2->next;
	}
	
	if ( cur1 == NULL ){
		while ( cur2!= NULL ){
			int digit = cur2->val + carry;
			ListNode *node = new ListNode();
			node->next = NULL;
			
			if ( digit == 10 ){
				carry = 1;
				node->val = 0;
			}
			
			else{
				carry = 0;
				node->val = digit;
			}
			cur->next = node;
			cur = cur->next;
			cur2= cur2->next;
		}
	}
	
	else{
		while ( cur1!= NULL ){
			int digit = cur1->val + carry;
			ListNode *node = new ListNode();
			node->next = NULL;
			
			if ( digit == 10 ){
				carry = 1;
				node->val = 0;
			}
			
			else{
				carry = 0;
				node->val = digit;
			}
			cur->next = node;
			cur = cur->next;
			cur1= cur1->next;
		}
	}
	
	if ( carry == 1 ){
		ListNode *node = new ListNode();
		node->val = 1;
		node->next = NULL;
		cur->next = node;
	}
	
	return res->next;
}

int main(){
	ListNode *head1 = new ListNode();
	ListNode *head2 = new ListNode();
	int a[] = {4, 3};
	int b[] = {6, 4};
	init(head1, 2);
	init(head2, 5);
	for ( int i = 0 ; i < 2; i ++){
		insert(head1, a[i]);
		insert(head2, b[i]);
	}
	traverse(addTwoNumbers(head1, head2));
	return 0;
}
