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

bool isValidBST(TreeNode *root){
	
    if ( root == NULL )
   		return true;
		
   		if ( root->left == NULL && root->right == NULL )
   		    return true;
	
   	    if ( root->left != NULL ){
   		    if ( isValidBST(root->left) ){
   			    if ( root->left->val >= root->val )
   				    return false;
   		    }
   		    else
   			    return false;
   	    }
	
   	    if ( root->right != NULL ){
   		    if ( isValidBST(root->right) ){
   			    if ( root->right->val <= root->val )
   				    return false;
   		    }
   		    else
   			    return false;
   	    }
	    
   	    TreeNode* cur = root->left;
   	    if ( cur != NULL ){
   	        while ( cur->right != NULL )
   	            cur = cur->right;
   	        if ( cur->val >= root->val )
   	            return false;
   	    }
	   
   	    cur = root->right;
   	    if ( cur != NULL ){
   	        while ( cur->left != NULL )
   	            cur = cur->left;
   	        if ( cur->val <= root->val )
   	            return false;
   	    }
	    
   	    return true;
}

int main(){
	vector<string> result = generateParenthesis(3);
	for ( int i = 0; i < result.size(); i++ )
		cout << result[i] << endl;
	return 0;
}
