#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <ctype.h>

using namespace std;

vector<int> findSubstring(string S, vector<string> &L){
	
	map<string, int> table1, table2;
	int size = L.size();
	int len = L[0].size();
	int counter = 0;
	vector<int> indices;
	for ( int k = 0; k < size; k++ ){
		if ( table1.find(L[k]) == table1.end() )
			table1[L[k]] = 1;
		else
			table1[L[k]]++;
	}
	
	for ( int i = 0; i <= (int)(S.length() - len * size); i++ ){
		
		int cur = i;
		counter = 0;
		for ( int k = 0; k < size; k++ )
			table2[L[k]] = table1[L[k]];
		
		while ( true ){
			
			if ( counter == size )
				break;
			
			string tmp = S.substr(cur, len);
			if ( table2.find(tmp) == table2.end() )
				break;
			
			if ( table2[tmp] <= 0 )
				break;
			
			if ( table2[tmp] > 0 ){
				counter++;
				cur += len;
				table2[tmp]-- ;
			}
		}
		
		if ( counter == size ){
			indices.push_back(i);
		}	
	}
	return indices;
}

int main(){
	string S = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
	string A[5] = {"fooo","barr","wing","ding","wing"};
	vector<string> L;
	for ( int i = 0; i < 5; i++ )
		L.push_back(A[i]);
	vector<int> ind = findSubstring(S, L);
	for ( int i = 0; i < ind.size(); i++ )
		cout << ind[i] << endl;
}
