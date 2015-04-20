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

bool isS(TreeNode* left, TreeNode* right){
       if (left == NULL && right == NULL)
           return true;
       
       if ( left == NULL || right == NULL )
           return false;
       
       if (left->val != right->val)
           return false;
       
       if ( isS(left->left, right->right) )
           return isS(left->right, right->left);
       else
           return false;
   }
   
   bool isSymmetric(TreeNode *root) {
       if ( root == NULL )
           return true;
       
       return isS(root->left, root->right);
   }
int main(){

}
