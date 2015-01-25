#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;

class BSTIterator {
public:
    stack<TreeNode*> buf;
    
    BSTIterator(TreeNode *root) {
        TreeNode* cur = root;
        while (cur != NULL ){
            buf.push(cur);
            cur = cur->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (!buf.empty());
    }

    /** @return the next smallest number */
    int next() {
        if ( buf.empty() )
            return  INT_MAX;
        
        TreeNode* node = buf.top();
        buf.pop();
        if ( node->right != NULL ){
            TreeNode* cur = node->right;
            while(cur != NULL){
                buf.push(cur);
                cur = cur->left;
            }
        }
        return node->val;
    }
};