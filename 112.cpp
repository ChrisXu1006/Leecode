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

bool hasPathSum(TreeNode *root, int sum) {
        if ( root == NULL )
            return false;
        
        if ( sum == root->val && root->left == NULL && root->right == NULL )
            return true;
        
        if ( !hasPathSum(root->left, sum-root->val) )
            return hasPathSum(root->right, sum-root->val);
        else
            return true;
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
