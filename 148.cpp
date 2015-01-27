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

ListNode* merge(ListNode* l1, ListNode* l2){
       ListNode* res = new ListNode(0);
       ListNode* current = res;
       while (true){
           if (!l1){
               current->next = l2;
               break;
           }
           if (!l2){
               current->next = l1;
               break;
           }
           if (l1->val < l2->val){
               current->next = l1;
               l1 = l1->next;
           }else{
               current->next = l2;
               l2 = l2->next;
           }
           current = current->next;
       }
       return res->next;
}
	
ListNode *sortList(ListNode *head){
	
	if ( head == NULL )
		return NULL;
	
	if ( head->next == NULL )
		return head;
	
	ListNode* slow = head;
	ListNode* fast = head;
	while ( slow->next != NULL && fast->next->next != NULL ){
		slow = slow->next;
		fast = fast->next->next;
		
		if (fast->next == NULL)
			break;
	}
	ListNode* head2 = slow->next;
	slow->next = NULL;
	ListNode* head1 = head;
	head1 = sortList(head1);
	head2 = sortList(head2);
	return merge(head1, head2);
}

int main(){
	int a[] = { 4, 3, 90, 14, 78, 34, 0};
	ListNode *head = new ListNode(9);
	for ( int i = 0; i < 7; i++ )
		insert(head, a[i]);
	traverse(head);
	cout << endl;
	traverse(sortList(head));
}
