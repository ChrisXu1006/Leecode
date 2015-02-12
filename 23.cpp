#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>

using namespace std;

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
      
      if ( l1 == NULL && l2 == NULL )
          return NULL;
      
      else if ( l1 == NULL )
          return l2;
      
      else if ( l2 == NULL)
          return l1;
      
      ListNode *cur1, *cur2, *cur;
      ListNode *res;
      cur1 = l1;
      cur2 = l2;
      if ( cur1->val <= cur2->val ){
          res = cur1;
          cur1 = cur1->next;
      }
      else{
          res = cur2;
          cur2 = cur2->next;
      }
      cur = res;
      
      while ( cur1 != NULL || cur2 != NULL ){
          if ( cur1 == NULL ){
              cur->next = cur2;
              cur2 = cur2->next;
          }
          
          else if ( cur2 == NULL ){
              cur->next = cur1;
              cur1 = cur1->next;
          }
          
          else if ( cur1->val <= cur2->val ){
              cur->next = cur1;
              cur1 = cur1->next;
          }
          
          else{
              cur->next = cur2;
              cur2 = cur2->next;
          }
          
          cur = cur->next;
      }
      return res;
  }
  
  ListNode *merge(vector<ListNode *> &lists, int left, int right){
      
      
      if ( right == left )
          return lists[left];
      
      if ( right < left )
          return NULL;
          
      int mid = (left + right)/2;
      
      return mergeTwoLists(merge(lists, left, mid), merge(lists, mid+1, right));
      
  }
  ListNode *mergeKLists(vector<ListNode *> &lists) {
      
      if ( lists.size() == 0 )
          return NULL;

      return merge(lists, 0, lists.size() - 1);        
  }

int main(){
    string s = "aab";
	string p = "c*a*b";
	const char *s1 = s.c_str();
	const char *p1 = p.c_str();
	cout << isMatch(s1, p1);
}
