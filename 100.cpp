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

bool isSameTree(TreeNode *p, TreeNode *q) {
       if ( p == NULL && q == NULL )
           return true;
       
       if ( p == NULL || q == NULL )
           return false;
       
       if ( p->val == q->val ){
           if ( isSameTree(p->left, q->left) )
               return isSameTree(p->right, q->right);
           else
               return false;
       }
       else
           return false;
   }

int main(){

}
