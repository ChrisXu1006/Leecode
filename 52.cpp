#include <iostream>
#include <cstring>
#include <string>
#include <stack>
#include <vector>

using namespace std;

bool isVal(vector<int> &buf, int col){
	
	int nrows = buf.size();
	
	for ( int i = 0; i < nrows; i++ ){
		
		if ( col == buf[i] )
			return false;
		
		if ( nrows - i == col - buf[i] )
			return false;
		
		if ( nrows + col == i + buf[i] )
			return false;
	}
	
	return true;
}

void gensol(int &sol, vector<int> &buf, int n){
	
	if ( buf.size() == n ){
		sol++;
		return;
	}
	
	for ( int i = 0; i < n; i++ ){
		
		if ( isVal(buf, i) ){
			buf.push_back(i);
			gensol(sol, buf, n);
			buf.pop_back();
		}
	}
	
	return;
}

int solveNQueens(int n){
	
	vector<int> buf;
	int sol = 0;
	
	gensol(sol, buf, n);
	return sol;
	
}

int main(){
	cout <<  solveNQueens(4);
	
	return 0;
}
