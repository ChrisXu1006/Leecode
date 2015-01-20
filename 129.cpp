#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
};

TreeNode *root = new TreeNode();

void init(int x){
	root->val  	= x;
	root->left  = NULL;
	root->right = NULL;
}

void insert(TreeNode *root, int x){
	
	if ( x <= root->val && root->left != NULL )
		insert(root->left, x);
	
	else if ( x <= root->val ){
		TreeNode *node = new TreeNode();
		node->val = x;
		node->left = NULL;
		node->right = NULL;
		root->left = node;
		return;
	}
	
	else if ( x > root->val && root->right != NULL )
		insert(root->right, x);
	
	else{
		TreeNode *node = new TreeNode();
		node->val = x;
		node->left = NULL;
		node->right = NULL;
		root->right = node;
		return;
	}
	
	return;
}

void traverse(TreeNode *root){
	if ( root == NULL )
		return;
	traverse(root->left);
	cout << root->val << " ";
	traverse(root->right);
	return;
}

void DFS(vector<string> &buf, string s, TreeNode* root){
	
	s = s + (char)('0' + root->val);
	
	if ( root->left == NULL && root->right == NULL ){
		buf.push_back(s);
		return;
	}
	
	else if ( root->left == NULL )
		DFS(buf, s, root->right);
	
	else if ( root->right == NULL)
		DFS(buf, s, root->left);
	
	else{
		DFS(buf, s, root->left);
		DFS(buf, s, root->right);
	}
	
	return;
}

int sumNumbers(TreeNode *root){
	
	if ( root == NULL )
		return 0;
	
	vector<string> buf;
	string s = "";
	DFS(buf, s, root);
	
	long long int res = 0;
	while ( !buf.empty() ){
		res = res + stoi(buf.back());
		buf.pop_back();
		if ( res > INT_MAX )
			return INT_MAX;
	}
	return res;
}

int main(){
	init(1);
	insert(root, 2);
	insert(root, 3);
	//insert(root, 3);
	//insert(root, 6);
	traverse(root);
	cout << endl;
	cout << sumNumbers(root);
	return 0;
}
