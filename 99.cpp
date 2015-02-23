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

void recoverTree(TreeNode *root){
	TreeNode *f1 = NULL, *f2 = NULL;
	TreeNode *current, *pre, *parent = NULL;
	
	if ( root == NULL )
		return;
	
	bool found = false;
	current = root;
	while ( current != NULL ){
		if ( current->left == NULL ){
			if ( parent && parent->val > current->val ){
				if (!found){
					f1 = parent;
					found = true;
				}
				f2 = current;
			}
			parent = current;
			current = current->right;
		}
		
		else{
			pre = current->left;
			while(pre->right != NULL && pre->right != current)
				pre = pre->right;
			
			if (pre->right == NULL){
				pre->right = current;
				current = current->left;
			}
			
			else{
				pre->right = NULL;
				if (parent->val > current->val){
					if (!found){
						f1 = parent;
						found = true;
					}
					f2 = current;
				}
				parent = current;
				current = current->right;
			}
		}
	}
	
	if ( f1 && f2 )
		swap(f1->val,f2->val);
	return;
  
}

int main(){
	vector<string> result = generateParenthesis(3);
	for ( int i = 0; i < result.size(); i++ )
		cout << result[i] << endl;
	return 0;
}
