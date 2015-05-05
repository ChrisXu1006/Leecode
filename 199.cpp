#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

void traverse(vector<vector<int>> &buf, TreeNode* root, int level){
        if ( root == NULL )
            return;
        
        if ( level >= buf.size() ){
            vector<int> levl;
            buf.push_back(levl);
        }
        buf[level].push_back(root->val);
        
        traverse(buf, root->left, level+1);
        traverse(buf, root->right, level+1);
            
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int> > buf;
        traverse(buf, root, 0);
        vector<int> res;
        for ( int i = 0; i < buf.size(); i++ )
            res.push_back(buf[i].back());
        return res;
}

int main(){
	cout << hammingWeight(n) << endl;
	return 0;
}