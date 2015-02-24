#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};


void insert(TreeNode* root, int x){
	
	if ( x <= root->val ){
		if ( root->left == NULL ){
			TreeNode* node = new TreeNode(x);
			root->left = node;
			return;
		}
		else
			insert(root->left, x);
	}
	
	else{
		if ( root->right == NULL ){
			TreeNode* node = new TreeNode(x);
			root->right = node;
			return;
		}
		else
			insert(root->right, x);
	}
}

void traverse(TreeNode *root){
	if ( root == NULL )
		return;
	traverse(root->left);
	cout << root->val << " ";
	traverse(root->right);
}

int getmax(TreeNode *root, int & maxvar){
	if ( root == NULL )
		return 0;
	int left = getmax(root->left, maxvar);
	int right= getmax(root->right, maxvar);
	int cmax = root->val;
	if ( left > 0 )
		cmax+= left;
	if (right > 0 )
		cmax+= right;
	maxvar = max(maxvar, cmax);
	return max(root->val, max(root->val+left, root->val+right));
}

int maxPathSum(TreeNode *root){
	int maxvar = INT_MIN;
	int maxresult = getmax(root, maxvar);
	return max(maxvar, maxresult);
}

int main(){
	int a[] = {4, 9, 2, 5, 7, 10};
	TreeNode*root = new TreeNode(6);
	for ( int i = 0; i < 6; i++ )
		insert(root, a[i]);
	//traverse(root) 
	int result = maxPathSum(root);
	cout << result;
	return 0;
}
