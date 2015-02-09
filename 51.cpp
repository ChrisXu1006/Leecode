#include <iostream>
#include <cstring>
#include <string>
#include <stack>
#include <vector>

using namespace std;

string genboard(int len, int col){
	string row = "";
	for ( int i = 0; i < len; i++ ){
		if ( i == col )
			row += 'Q';
		else
			row += '.';
	}
	return row;
}

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

void gensol(vector<vector<string> > &sol, vector<int> &buf, int n){
	
	if ( buf.size() == n ){
		vector<string> element;
		for ( int i = 0; i < buf.size(); i++ ){
			string s = genboard(n, buf[i]);
			element.push_back(s);
		}
		sol.push_back(element);
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

vector<vector<string> > solveNQueens(int n){
	
	vector<int> buf;
	vector<vector<string> > sol;
	
	gensol(sol, buf, n);
	return sol;
	
}

int main(){
	vector<vector<string> > sol = solveNQueens(1);
	for ( int i = 0; i < sol.size(); i++ ){
		cout << '[' << endl;
		for ( int j = 0; j < sol[i].size(); j++ )
			cout << sol[i][j] << endl;
		cout << ']' << endl;
	}
	return 0;
}
