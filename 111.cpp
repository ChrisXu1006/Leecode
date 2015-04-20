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

int minDepth(TreeNode *root) {
       if ( root == NULL )
           return 0;
       
       if ( root->left == NULL && root->right == NULL )
           return 1;
       else if ( root->left == NULL )
           return 1+minDepth(root->right);
       else if ( root->right == NULL )
           return 1+minDepth(root->left);
       else
           return 1+min(minDepth(root->left), minDepth(root->right));
   }

int main(){
	int a[] = {2, 3, 4, 5};
	ListNode *head = new ListNode(1);
	for( int i = 0; i < 4; i++ )
		insert(head, a[i]);
	TreeNode *root = isBalanced(head);
	traverse(root);
	return 0;
}
