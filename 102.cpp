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

vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > res;
        if ( root == NULL )
            return res;
        
        vector<TreeNode*> buf1;
        buf1.push_back(root);
        
        while (!buf1.empty()){
            int size = buf1.size();
            vector<int> row;
            int pos = 0;
            for ( int i = 0; i < size; i++  ){
                row.push_back(buf1[0]->val);
                if ( buf1[0]->left )
                    buf1.push_back(buf1[0]->left);
                if ( buf1[0]->right )
                    buf1.push_back(buf1[0]->right);
                buf1.erase(buf1.begin());
            }
            res.push_back(row);
        }
        return res;
    }
	
int main(){

}
