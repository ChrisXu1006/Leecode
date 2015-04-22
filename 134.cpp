#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
      int size = gas.size();
      int counter = 0;
      int start = 0;
      int end = 0;
      int sum = 0;
      
      while (counter != size){
		  cout << start << " " << end << endl;
          if ( sum + gas[end] - cost[end] >= 0 ){
               sum = sum + gas[end] - cost[end];
               end++;
               counter++;
               if ( end == size )
                   end = 0;
               continue;
           }
          
           start--;
           if ( start == - 1 )
               start = size - 1;
           sum = sum + gas[start] - cost[start];
           counter++;
      }
      if ( sum >= 0 )
          return start;
      else
           return -1;
   }
   
int main(){
	int A[] = {1, 2};
	int B[] = {2, 1};
	vector<int> gas;
	vector<int> cost;
	for ( int i = 0; i < 2; i++ ){
		gas.push_back(A[i]);
		cost.push_back(B[i]);
	}
	cout << canCompleteCircuit(gas, cost) << endl;
	return 0;
}
