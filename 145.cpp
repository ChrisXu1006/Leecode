#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};

void insert(ListNode *head, int x){
	ListNode *cur = head;
	while (cur->next != NULL)
		cur = cur->next;
	ListNode *node = new ListNode(x);
	cur->next = node;
	return;
}

void traverse(ListNode *head){
	ListNode *cur = head;
	while ( cur != NULL ){
		cout << cur->val << " ";
		cur = cur->next;
	}
	return;
}

vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> S;
        
        TreeNode* cur = root;
        while ( cur != NULL ){
            S.push(cur);
            cur = cur->left;
        }
        
        while ( !S.empty() ){
            cur = S.top();
            if ( cur->right == NULL ){
                res.push_back(cur->val);
                S.pop();
            }
            else{
                TreeNode* tmp = cur->right;
                while ( tmp != NULL ){
                    S.push(tmp);
                    tmp = tmp->left;
                }
                cur->right = NULL;
            }
        }
        return res;
    }
int main(){
	int a[] = { 4, 10, 8, 22, 100, 11, 12, 10};
	ListNode *head1 = new ListNode(3);
	for ( int i = 0; i < 2; i++ )
		insert(head, a[i]);
	traverse(head);
	vector<int> res = postorderTraversal(root);
	return 0;
}
