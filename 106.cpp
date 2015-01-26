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

TreeNode *build(vector<int> &inorder, vector<int> &postorder, int start1, int end1, int start2, int end2){
	if ( start1 > end1 )
		return NULL;
	
	if ( end1 - start1 == 0 ){
		TreeNode*root = new TreeNode(inorder[start1]);
		return root;
	}
	
	TreeNode*root = new TreeNode(postorder[end2]);
	int cur = start1;
	while ( cur <= end1 ){
		if ( inorder[cur] == postorder[end2] )
			break;
		cur++;
	}
	cout << cur << " " << start1 << " " << end1 << " " << start2 << " " << end2 << endl;
	root->left = build(inorder, postorder, start1, cur-1, start2, start2+(cur-1-start1));
	root->right= build(inorder, postorder, cur+1, end1, (end2-1)-(end1-cur-1), end2-1);
	return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder){
	
	if ( inorder.size() != postorder.size() )
		return NULL; 
	
	int cap = inorder.size();
	
	if ( cap == 0 )
		return NULL;
	
	TreeNode*root = build(inorder, postorder, 0, cap-1, 0, cap-1);
	return root;
}

int main(){
	int a[] = {1, 2, 3, 4, 5};
	int b[] = {4, 3, 5, 2, 1};
	vector<int> inorder, postorder;
	for( int i = 0; i < 5; i++ ){
		inorder.push_back(a[i]);
		postorder.push_back(b[i]);
	}
	TreeNode *root = buildTree(inorder, postorder);
	traverse(root);
	return 0;
}
