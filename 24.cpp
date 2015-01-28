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

ListNode *swapPairs(ListNode *head){
	
	// Start typing your C/C++ solution below
      // DO NOT write int main() function
      ListNode *p = new ListNode(0);
      p->next = head;
      head = p;
      while(true){
          if (p->next==NULL){break;}
          if (p->next->next==NULL){break;}
          ListNode* q1 = p->next;
          ListNode* q2 = q1->next;
          q1->next = q2->next;
          q2->next = q1;
          p->next = q2;
          p=q1;
      } 
      return head->next;
}

int main(){
	int a[] = {5};
	ListNode* head = new ListNode(1);
	for ( int i = 0; i < 1; i ++ )
		insert(head, a[i]);
	traverse(head);
	swapPairs(head);
	cout << endl;
	traverse(head);
	return 0;
}
