#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
};

void init(TreeLinkNode *root, int x){
	root->val = x;
	root->left  = NULL;
	root->right = NULL;
	root->next  = NULL;
}

void insert(TreeLinkNode *root, int x){
	
	if ( x <= root->val && root->left == NULL ){
		TreeLinkNode* node = new TreeLinkNode();
		node->val = x;
		node->left  = NULL;
		node->right = NULL;
		node->next  = NULL;
		root->left = node;
		return;
	}
	
	if ( x > root->val && root->right == NULL ){
		TreeLinkNode* node = new TreeLinkNode();
		node->val = x;
		node->left  = NULL;
		node->right = NULL;
		node->next  = NULL;
		root->right = node;
		return;
	}
	
	if ( x <= root->val )
		insert(root->left, x);
	else
		insert(root->right, x);
}

void traverse(TreeLinkNode *root){
	if ( root == NULL )
		return;
	traverse(root->left);
	cout << root->val << " ";
	traverse(root->right);
}

void dfs(TreeLinkNode *root){
	if ( root == NULL )
		return;
	
	if ( root->next == NULL){
		if ( root->right != NULL )
			root->right->next = NULL;
		if ( root->left  != NULL )
			root->left->next = root->right;
	}
	else{
		if ( root->right != NULL )
			root->right->next = root->next->left;
		if ( root->left )
			root->left->next = root->right;
	}
	
	dfs(root->right);
	dfs(root->left);
	return;
}

void connect(TreeLinkNode *root){
	if ( root == NULL )
		return;
	root->next = NULL;
	dfs(root);
	return;
}

int main(){
	int a[] = {4, 2, 6, 12, 10, 20};
	TreeLinkNode* root = new TreeLinkNode();
	init(root, 8);
	for ( int i = 0; i < 6; i++ )
		insert(root, a[i]);
	traverse(root);
	return 0;
}
