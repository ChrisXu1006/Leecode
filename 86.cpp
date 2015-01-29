#include <iostream>
#include <cmath>
#include <algorithm>
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
	ListNode(int x) : val(x), next(NULL){}
};

void insert(ListNode* head, int x){
	ListNode* cur = head;
	while ( cur->next != NULL )
		cur = cur->next;
	
	ListNode* node = new ListNode(x);
	cur->next = node;
	return;
}

void traverse(ListNode* head){
	ListNode* cur = head;
	
	while(cur != NULL ){
		cout << cur->val << " ";
		cur = cur->next;
	}
}

ListNode *partition(ListNode *head, int x){
	if ( head == NULL || head->next == NULL )
		return head;
	
	ListNode* dummynode1 = new ListNode(0);
	dummynode1->next = head;
	ListNode* pre = dummynode1;
	ListNode* cur = head;
	ListNode* dummynode2 = new ListNode(0);
	ListNode* cur2 = dummynode2;
	
	while ( cur != NULL ){
		
		if ( cur->val >= x ){
			pre->next = cur->next;
			cur2->next = cur;
			cur2 = cur2->next;
			cur = cur->next;
			cur2->next = NULL;
		}
		else{
			pre = pre->next;
			cur = cur->next;
		}
	}
	pre->next = dummynode2->next;
	return dummynode1->next;
}

int main(){
	int a[] = {4, 3, 2, 5, 2};
	ListNode* head = new ListNode(1);
	for ( int i = 0; i < 5; i++ )
		insert(head, a[i]);
	traverse(head);
	cout << endl;
	traverse(partition(head,4));
}
