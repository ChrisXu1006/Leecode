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
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

void insert(TreeNode*root, int x){
	if ( x <= root->val ){
		if ( root->left == NULL ){
			TreeNode* lchild = new TreeNode(x);
			root->left = lchild;
			return;
		}
		else
			insert(root->left, x);
	}
	
	else{
		if ( root->right == NULL ){
			TreeNode* rchild = new TreeNode(x);
			root->right = rchild;
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
	return;
}

void zigzag(vector<vector<int> > &result, vector<TreeNode*> buf, int right ){
	if ( buf.size() == 0 )
		return;
	
	vector<int> tmp;
	vector<TreeNode*> nbuf;
	while ( !buf.empty() ){
		TreeNode*cur = buf.back();
		tmp.push_back(cur->val);
	
		if ( right ){
			cout << "enter" << endl;
			if ( cur->right != NULL )
				nbuf.push_back(cur->right);
			if ( cur->left != NULL)
				nbuf.push_back(cur->left);
		}
		
		else{
			if ( cur->left != NULL)
				nbuf.push_back(cur->left);
			if ( cur->right != NULL )
				nbuf.push_back(cur->right);
		}
		
		buf.pop_back();
	}
	if ( !tmp.empty() )
		result.push_back(tmp);
	if (right == 1)
		zigzag(result, nbuf, 0);
	else
		zigzag(result, nbuf, 1);
	return;
}

vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
	vector<vector<int> > result;
	if ( root == NULL )
		return result;
	
	vector<TreeNode*> buf;
	buf.push_back(root);
	zigzag(result, buf, 0);
	return result;
}

int main(){
	int a[] = { 6, 15, 2, 7, 12, 20};
	TreeNode* root = new TreeNode(9);
	for ( int i = 0; i < 6; i++ )
		insert(root, a[i]);
	//traverse(root);
	vector<vector<int> > result = zigzagLevelOrder(root);
	for ( int i = 0; i < result.size(); i++ ){
		for ( int j = 0; j < result[i].size(); j++ )
			cout << result[i][j] << " ";
		cout << endl;
	}
}
