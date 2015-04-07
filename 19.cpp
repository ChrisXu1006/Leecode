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

ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dhead = new ListNode(0);
        dhead->next = head;
        ListNode *fast = dhead;
        ListNode *slow = dhead;
        
        for ( int i = 0; i < n; i++ )
            fast = fast->next;
        
        while (fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dhead->next;
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
