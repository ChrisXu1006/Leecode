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
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

void insert(TreeNode *root, int a){
	if (root->left == NULL ){
		TreeNode* node = new TreeNode(a);
		root->left = node;
		return;
	}
	
	else if ( root->right == NULL ){
		TreeNode* node = new TreeNode(a);
		root->right = node;
		return;
	}
	
	else
		insert(root->left, a);
}
void traverse_print(TreeNode *root){
	if ( root == NULL )
		return;
	traverse_print(root->left);
	traverse_print(root->right);
	cout << root->val << " ";
	//cout << endl;
}

void traverse(vector<int> &result, TreeNode *root){
   if ( root == NULL )
       return;
   
   result.push_back(root->val);
   traverse(result, root->left);
   traverse(result, root->right);
   
   return;
 }
 
vector<int> preorderTraversal(TreeNode *root) {
   vector<int> result;
   traverse(result, root);
   return result;
}

int main(){
	TreeNode*root = new TreeNode(5);
	int a[] = {3, 1, 2, 8, 6, 9 };
	for ( int i = 0; i < 6; i ++ )
		insert(root, a[i]);
	vector<int> result = preorderTraversal(root);
	for ( int i = 0; i < result.size(); i++ ){
		cout << result[i] << " ";
	}
	return 0;
}
