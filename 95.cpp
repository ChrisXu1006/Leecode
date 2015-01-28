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

void traverse(TreeNode *root){
	if ( root == NULL )
		return;
	traverse(root->left);
	traverse(root->right);
	cout << root->val << " ";
	//cout << endl;
}

 vector<TreeNode *> gensubtree(int start, int end){
	vector<TreeNode *> result;
	
	if ( start > end )
		return result;
	
	if ( start == end ){
		TreeNode* root = new TreeNode(start);
		result.push_back(root);
		return result;
	}
	
	vector<TreeNode *> left;
	vector<TreeNode *> right;
	
	for ( int i = start; i <= end; i++ ){

		//TreeNode *root = new TreeNode(i);
		left  = gensubtree(start, i-1);
		right = gensubtree(i+1, end);
		
		if ( left.empty() ){
			for (int j = 0; j < right.size(); j++ ){
				TreeNode *root = new TreeNode(i);
				root->left = NULL;
				root->right = right[j];
				result.push_back(root);
			}
		}
		
		else if ( right.empty() ){
			for (int j = 0; j < left.size(); j++ ){
				TreeNode *root = new TreeNode(i);
				root->right = NULL;
				root->left = left[j];
				result.push_back(root);
			}
		}
		
		else{
			for ( int j = 0; j < left.size(); j++ )
				for ( int k = 0; k < right.size(); k++){
					TreeNode *root = new TreeNode(i);
					root->left = left[j];
					root->right = right[k];
					result.push_back(root);
				}	
		}
	}
	return result;
}

vector<TreeNode *> generateTrees(int n){
	vector<TreeNode *> result;
	
	if ( n < 1 ){
	    result.push_back(NULL);
		return result;
	}
	
	result = gensubtree(1, n);
	return result;
}
int main(){
	vector<TreeNode *> result = generateTrees(3);
	for ( int i = 0; i < result.size(); i++ ){
		traverse(result[i]);
		cout << endl;
	}
	return 0;
}
