#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

bool existRecur(vector<vector<char> > &board, int **table, string word, int len, int i, int j){
	
	if ( len == word.length() )
		return true;
	
	if ( i - 1 >= 0 ){
		if ( board[i-1][j] == word[len] && !table[i-1][j] ){
			table[i-1][j] = 1;
			bool res = existRecur(board, table, word, len+1, i-1, j);
			if (res )
				return true;
			else
				table[i-1][j] = 0;
		}
	}
	
	if ( i + 1 < board.size() ){
		if ( board[i+1][j] == word[len] && !table[i+1][j] ){
			table[i+1][j] = 1;
			bool res = existRecur(board, table, word, len+1, i+1, j);
			if (res )
				return true;
			else
				table[i+1][j] = 0;
		}
	}
	
	if ( j - 1 >= 0 ){
		if ( board[i][j-1] == word[len] && !table[i][j-1] ){
			table[i][j-1] = 1;
			bool res = existRecur(board, table, word, len+1, i, j-1);
			if (res )
				return true;
			else
				table[i][j-1] = 0;
		}
	}
	
	if ( j + 1 < board[0].size() ){
		if ( board[i][j+1] == word[len] && !table[i][j+1] ){
			table[i][j+1] = 1;
			bool res = existRecur(board, table, word, len+1, i, j+1);
			if (res )
				return true;
			else
				table[i][j+1] = 0;
		}
	}
	
	return false;
	
}

bool exist(vector<vector<char > > &board, string word) {
	if ( word == "" )
		return false;
	
	int length = board.size();
	int width  = board[0].size();
	
	
	int **table;
	table = new int *[length];
	for (int i = 0; i < length; i++ )
		table[i] = new int[width];
	
	for ( int i = 0; i < length; i++ )
		for ( int j = 0; j < width; j++ )
			table[i][j] = 0;
	
	for (int i = 0; i < board.size(); i++)
		for (int j = 0; j < board[i].size(); j++){
			if ( board[i][j] == word[0]){
				table[i][j] = 1;
				bool res = existRecur(board, table, word, 1, i, j);
				if ( res )
					return true;
				else
					table[i][j] = 0;
			}
		}
	return false;
}


int main(){
	char A[3][2] = {
		//{'A','B','C','E'},
		//{'S','F','C','S'},
		//{'A','D','E','E'}
		{'a', 'a'},
		{'a', 'a'},
		{'a', 'a'}
	};
	vector<vector<char> > board;
	for ( int i = 0; i < 3; i++ ){
		vector<char> tmp;
		for ( int j = 0; j < 2; j++ )
			tmp.push_back(A[i][j]);
		board.push_back(tmp);
		tmp.clear();
	}
	
	for ( int i = 0; i < board.size(); i++ ){
		for ( int j = 0; j < board[i].size(); j++ )
			cout << board[i][j];
		cout << endl;
	}
	cout << exist(board, "aaaaaa");
}
