#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if ( node == NULL )
            return NULL;
        
        UndirectedGraphNode *cnode = new UndirectedGraphNode(node->label);
        stack<UndirectedGraphNode*> S;
        map<UndirectedGraphNode *, UndirectedGraphNode *> table;
        S.push(node);
        table[node] = cnode;
        
        while (!S.empty()){
            UndirectedGraphNode *cur = S.top();
            S.pop();
            for ( int i = 0; i < cur->neighbors.size(); i++ ){
                UndirectedGraphNode *curnode = cur->neighbors[i];
                if ( table.find(curnode) == table.end() ){
                    UndirectedGraphNode* newnode = new UndirectedGraphNode(curnode->label);
                    table[curnode] = newnode;
                    table[cur]->neighbors.push_back(newnode);
                    S.push(curnode);
                }
                else
                    table[cur]->neighbors.push_back(table[curnode]);
            }
        }
        return cnode;
    }
};
   
int main(){
	return 0;
}
