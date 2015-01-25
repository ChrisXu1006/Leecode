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

void pathCal(vector<vector<int> > &result, vector<int> &buf, TreeNode *root, int sum){
	if (root->left == NULL && root->right == NULL ){
		if ( root->val == sum ){
			buf.push_back(root->val);
			result.push_back(buf);
			buf.pop_back();
			return;
		}
		else
			return;
	}
	
	else if ( root->right == NULL ){
		buf.push_back(root->val);
		pathCal(result, buf, root->left, sum-root->val);
		buf.pop_back();
		return;
	}
	
	else if ( root->left == NULL ){
		buf.push_back(root->val);
		pathCal(result, buf, root->right, sum-root->val);
		buf.pop_back();
		return;
	}
	
	else{
		buf.push_back(root->val);
		pathCal(result, buf, root->left, sum-root->val);
		pathCal(result, buf, root->right, sum-root->val);
		buf.pop_back();
		return;
	}
}

vector<vector<int> > pathSum(TreeNode *root, int sum){
	vector<vector<int> > result;
	
	if ( root == NULL )
		return result;
	
	vector<int> buf;
	pathCal(result, buf, root, sum);
	return result;
}

int main(){
	int a[] = {4, 9, 2, 5, 7, 10};
	TreeNode*root = new TreeNode(6);
	for ( int i = 0; i < 6; i++ )
		insert(root, a[i]);
	//traverse(root);
	vector<vector<int> > result;
	result = pathSum(root, 12);
	for ( int i = 0; i < result.size(); i++ ){
		cout << "[";
		for ( int j = 0; j < result[i].size(); j++ )
			cout << result[i][j] << ",";
		cout << "]";
	}
	return 0;
}
