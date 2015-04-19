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

ListNode *deleteDuplicates(ListNode *head) {
      if ( head == NULL || head->next == NULL )
          return head;
      
      ListNode *pre = head;
      ListNode *cur = head->next;
      while ( cur != NULL ){
          if ( pre->val == cur->val )
              pre->next = cur->next;
          else
              pre = pre->next;
          cur = cur->next;
      }
      return head;
  }

int main(){
	int a[] = { 1};
	ListNode *head = new ListNode(1);
	for ( int i = 0; i < 1; i++ )
		insert(head, a[i]);
	traverse(head);
	cout << endl;
	traverse(deleteDuplicates(head));
}
