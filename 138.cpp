#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x): label(x), next(NULL), random(NULL) {}
};

RandomListNode *copyRandomList(RandomListNode *head){
	RandomListNode *cur = head;
	while ( cur != NULL ){
		RandomListNode *dumpnode = new RandomListNode(cur->label);
		dumpnode->next = cur->next;
		cur->next = dumpnode;
		cur = dumpnode->next;
	}
	
	cur = head;
	while ( cur != NULL ){
		RandomListNode *dump = cur->next;
		if ( cur->random != NULL )
			dump->random = cur->random->next;
		cur = dump->next;
	}
	
	cur = head;
    RandomListNode *nhead = head == NULL ? NULL : head->next;
   	RandomListNode *dump = head == NULL ? NULL : head->next;
   	while ( cur != NULL ){
   		    cur->next = dump->next;
   		    if ( dump->next != NULL )
   			    dump->next = dump->next->next;
   		    cur = cur->next;
   		    dump = dump->next;
   	}
}

int main(){
	int A[] = {1, 2, 3, 4, 5, 4, 3};
	vector<int> rates;
	for ( int i = 0; i < 7; i++ )
		rates.push_back(A[i]);
	cout << candy(rates);
}
