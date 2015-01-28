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
      
      traverse(result, root->left);
      result.push_back(root->val);
      traverse(result, root->right);
      
      return;
  }
  
vector<int> inorderTraversal1(TreeNode *root) {
      vector<int> result;
      traverse(result, root);
      return result;
}


int main(){
	TreeNode*root = new TreeNode(2);
	int a[] = { 1, 3};
	for ( int i = 0; i < 2; i ++ )
		insert(root, a[i]);
	vector<int> result = inorderTraversal1(root);
	for ( int i = 0; i < result.size(); i++ ){
		cout << result[i] << " " << endl;
	}
	return 0;
}
