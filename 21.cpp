#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
       
       if ( l1 == NULL )
           return l2;
       
       if ( l2 == NULL )
           return l1;
       
       ListNode *head = new ListNode(0);
       if ( l1->val <= l2->val ){
           head->val = l1->val;
           l1 = l1->next;
       }
       else{
           head->val = l2->val;
           l2 = l2->next;
       }
       ListNode *cur = head;
       
       while ( l1 != NULL && l2 != NULL ){
           if ( l1->val <= l2->val ){
               ListNode *node = new ListNode(l1->val);
               l1 = l1->next;
               cur->next = node;
           }
           else{
               ListNode *node = new ListNode(l2->val);
               l2 = l2->next;
               cur->next = node;
           }
           cur = cur->next;
       }
       
       if ( l1 != NULL )
           cur->next = l1;
       
       if ( l2 != NULL )
           cur->next = l2;
       
       return head;
   }