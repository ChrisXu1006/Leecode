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

ListNode* reverse(ListNode *head){
	ListNode* dhead = new ListNode(0);
	dhead->next = head;
	
	ListNode* cur = head->next;
	ListNode* tmp;
	head->next = NULL;
	while ( cur != NULL ){
		tmp = cur;
		dhead->next = tmp;
		cur = cur->next;
		tmp->next = head;
		head = dhead->next;
	}
	return dhead->next;
}

void merge(ListNode* head1, ListNode* head2){
	ListNode* cur1 = head1;
	ListNode* cur2 = head2;
	ListNode* tmp1;
	ListNode* tmp2;
	
	while ( cur2 != NULL ){
		tmp1 = cur1;
		tmp2 = cur2;
		
		cur1 = cur1->next;
		cur2 = cur2->next;
		
		tmp2->next = tmp1->next;
		tmp1->next = tmp2;
	}
	
}

void reorderList(ListNode *head){
	
	if ( head == NULL || head->next == NULL )
		return;
	
	ListNode*slow = head;
	ListNode*fast = head;
	
	while ( fast->next->next != NULL ){
		fast = fast->next->next;
		slow = slow->next;
		if ( fast->next == NULL )
			break;
	}
	
	ListNode *lhead = slow->next;
	slow->next = NULL;
	
	lhead = reverse(lhead);
	merge(head, lhead);
	return;
}

int main(){
	int a[] = { 2, 3 ,4 };
	ListNode *head = new ListNode(1);
	for ( int i = 0; i < 3; i++ )
		insert(head, a[i]);
	traverse(head);
	cout << endl;
	reorderList(head);
	traverse((head));
}
