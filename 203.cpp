#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

unordered_map<int, bool> table;    
ListNode* removeElements(ListNode* head, int val) {
       ListNode* dnode = new ListNode(0);
       dnode->next = head;
       ListNode* pre = dnode;
       ListNode* cur = head;
       
       while ( cur != NULL ){
           if ( cur->val == val ){
               pre->next = cur->next;
               delete cur;
               cur = pre->next;
           }
           else{
               pre = pre->next;
               cur = cur->next;
           }
       }
       return dnode->next;
   }
	
int main(){
	return 0;
}