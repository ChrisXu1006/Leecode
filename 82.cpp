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

ListNode *deleteDuplicates(ListNode *head){
	
	if ( head == NULL || head->next == NULL )
		return head;
	
	ListNode* dummynode = new ListNode(0);
	dummynode->next = head;
	ListNode* pre = dummynode;
	
	int cur_num = head->val;
	int num = 1;
	
	ListNode* mid = head;
	ListNode* cur = head->next;
	while ( cur != NULL ){
		//cout << num << endl;
		if ( cur->val == cur_num ){
			num++;
			cur = cur->next;
		}
		
		else if ( cur->val != cur_num){
			pre->next = mid;
			cur_num = cur->val;
			cur = cur->next;
			if ( num == 1){
				pre = pre->next;
			}
			num = 1;
		}
		mid = mid->next;
	}
	if ( num > 1 )
		pre->next = NULL;
	if ( num == 1)
		pre->next = mid;
	
	return dummynode->next;
	
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
