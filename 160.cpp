#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA;
        ListNode *p2 = headB;

        if (p1 == NULL || p2 == NULL) return NULL;

        while (p1 != NULL && p2 != NULL && p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;

            if (p1 == p2) return p1;
        
            if (p1 == NULL) p1 = headB;
            if (p2 == NULL) p2 = headA;
        }

        return p1;
}

int findPeakElement(const vector<int> &num){
	int end = num.size()-1;
	return find(num, 0, end);
}

int main(){
	int a[] = {2, 1};
	vector<int> result;
	for ( int i = 0; i < 2; i++ )
		result.push_back(a[i]);
	cout << findPeakElement(result);
}
