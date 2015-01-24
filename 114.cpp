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

void flatten(TreeNode *root){
    TreeNode*now = root;
           while (now)
           {
               if(now->left)
               {
                   //Find current node's prenode that links to current node's right subtree
                   TreeNode* pre = now->left;
                   while(pre->right)
                   {
                       pre = pre->right;
                   }
                   pre->right = now->right;
                   //Use current node's left subtree to replace its right subtree(original right 
                   //subtree is already linked by current node's prenode
                   now->right = now->left;
                   now->left = NULL;
               }
               now = now->right;
           }
  
}

int main(){
	int a[] = {4, 9, 2, 5, 7, 10};
	TreeNode*root = new TreeNode(6);
	for ( int i = 0; i < 6; i++ )
		insert(root, a[i]);
	traverse(root);
	cout << endl;
	flatten(root);
	traverse(root);
	return 0;
}
