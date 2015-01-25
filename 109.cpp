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
	ListNode(int x): val(x), next(NULL) {}
};

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void insert(ListNode *head, int x){
	ListNode *cur = head;
	while(cur->next != NULL)
		cur = cur->next;
	ListNode *node = new ListNode(x);
	cur->next = node;
}
void traverse(TreeNode*root){
	if (root == NULL )
		return;
	traverse(root->left);
	cout << root->val << " ";
	traverse(root->right);
	return;
}

TreeNode *sortedListToBST(ListNode *head){
	
	if ( head == NULL )
		return NULL;
	
	if ( head->next == NULL ){
		TreeNode* root = new TreeNode(head->val);
		return root;
	}
	
	if ( head->next->next == NULL){
		TreeNode* root = new TreeNode(head->next->val);
		TreeNode* lchild = new TreeNode(head->val);
		root->left =lchild;
		return root;
	}
	
	int len = 0;
	ListNode *pre = head;
	ListNode *slow = head;
	ListNode *fast = head;
	while ( fast->next != NULL ){
		fast = fast->next->next;
		if ( fast == NULL ){
			len++;
			break;
		}
		len += 2;
		if( slow != head )
			pre = pre->next;
		slow = slow->next;
	}
	TreeNode* root = new TreeNode(slow->val);
	ListNode* n_right = slow->next;
	root->right = sortedListToBST(n_right);
	pre->next = NULL;
	root->left = sortedListToBST(head);
	return root;
}

int main(){
	int a[] = {2, 3, 4, 5};
	ListNode *head = new ListNode(1);
	for( int i = 0; i < 4; i++ )
		insert(head, a[i]);
	TreeNode *root = sortedListToBST(head);
	traverse(root);
	return 0;
}
