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
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void traverse(TreeNode*root){
	if (root == NULL )
		return;
	traverse(root->left);
	cout << root->val << " ";
	traverse(root->right);
	return;
}

void buildBST(vector<int> &num, TreeNode* root, int start, int mid, int end){
	
	if ( mid == start )
		root->left = NULL;
	else{
		int mid_left = (start + mid -1)/2;
		TreeNode* node = new TreeNode(num[mid_left]);
		root->left = node;
		buildBST(num, root->left, start, mid_left, mid-1);
	}
	
	if ( mid == end )
		root->right = NULL;
	else{
		int mid_right = ( mid + 1 + end )/2;
		TreeNode* node = new TreeNode(num[mid_right]);
		root->right = node;
		buildBST(num, root->right, mid+1, mid_right, end);
	}
	return;
	
}

TreeNode *sortedArrayToBST(vector<int> &num){
	
	int len = num.size();
	if ( len == 0 )
		return NULL;
	
	int mid = (0 + len - 1)/2;
	TreeNode* root = new TreeNode(num[mid]);
	buildBST(num, root, 0, mid, len-1);
	return root;
}

int main(){
	int a[] = {};
	vector<int> num;
	for( int i = 0; i < 0; i++ )
		num.push_back(a[i]);
	TreeNode *root = sortedArrayToBST(num);
	traverse(root);
	return 0;
}
