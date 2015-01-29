#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void insert(ListNode *head, int x){
	ListNode* cur = head;
	while (cur->next != NULL)
		cur = cur->next;
	ListNode* node = new ListNode(x);
	cur->next = node;
	return;
}

void traverse(ListNode *head){
	ListNode* cur = head;
	while (cur != NULL){
		cout << cur->val << " ";
		cur = cur->next;
	}
	return;
}

ListNode *reverseBetween(ListNode *head, int m, int n ){
	
	if ( head == NULL || m == n )
		return head;
	
	ListNode* dummyhead = new ListNode(0);
	dummyhead->next = head;
	head = dummyhead;
	int steps = 0;
	ListNode* pre = head;
	ListNode* cur = head->next;
	while ( steps != m -1 ){
		pre = pre->next;
		cur = cur->next;
		steps++;
	}
	
	ListNode* hd = cur;
	ListNode* tl = cur;
	cur = cur->next;
	for ( int i = 0; i < (n-m); i++ ){
		pre->next = cur;
		tl->next = cur->next;
		cur->next = hd;
		hd = cur;
		cur = tl->next;
	}
	
	return head->next;
	
}
int main(){
	int a[] = {2, 3, 4, 5};
	ListNode *head = new ListNode(1);
	for ( int i = 0; i < 4; i++ )
		insert(head, a[i]);
	traverse(head);
	ListNode *result = reverseBetween(head, 1, 2);
	cout << endl; 
	traverse(result);
	return 0;
}
