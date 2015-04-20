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

int maxDepth(TreeNode *root) {
	if ( root == NULL )
    	return 0;
	return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
	
int main(){

}
