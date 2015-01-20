#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct location{
	int i;
	int j;
};

void solve(vector<vector<char> > &board){
	
	int height = board.size();
	int length = board[0].size();
	bool flip[height][length];
	memset(flip,   true,  sizeof(flip));
	stack<location> buf;
	location cur ;
	location node;
	
	for ( int i = 0; i < length; i ++ ){
		if ( board[0][i] == 'O' ){
			cur.i = 0;
			cur.j = i;
			buf.push(cur);
			flip[0][i] = false;
		}
		
		if ( board[height-1][i] == 'O'){
			cur.i = height - 1;
			cur.j = i;
			buf.push(cur);
			flip[height-1][i] = false;
		}
	}
	
	for ( int i = 1; i < height-1; i ++ ){
		if ( board[i][0] == 'O'){
			cur.i = i;
			cur.j = 0;
			buf.push(cur);
			flip[i][0] = false;
		}
		
		if ( board[i][length-1] == 'O' ){
			cur.i = i;
			cur.j = length-1;
			buf.push(cur);
			flip[i][length-1] = false;
		}
	}
	
	while (!buf.empty()){
		cur = buf.top();
		buf.pop();
		//cout << cur.i << " " << cur.j << " " << endl; 
		
		if ( (cur.i - 1 > 0) && (board[cur.i-1][cur.j] == 'O') && flip[cur.i-1][cur.j]){
			node.i = cur.i - 1;
			node.j = cur.j;
			buf.push(node);
			flip[cur.i-1][cur.j] = false;
		}
		
		if ( (cur.i + 1 < height) && (board[cur.i+1][cur.j] == 'O') && flip[cur.i+1][cur.j]){
			node.i = cur.i + 1;
			node.j = cur.j;
			buf.push(node);
			flip[cur.i+1][cur.j] = false;
		}
		
		if ( (cur.j - 1 > 0) && (board[cur.i][cur.j-1] == 'O') && flip[cur.i][cur.j-1]){
			node.i = cur.i;
			node.j = cur.j - 1;
			buf.push(node);
			flip[cur.i][cur.j-1] = false;
		}
		
		if ( (cur.j + 1 < length) && (board[cur.i][cur.j+1] == 'O') && flip[cur.i][cur.j+1]){
			node.i = cur.i;
			node.j = cur.j + 1;
			buf.push(node);
			flip[cur.i][cur.j+1] = false;
		}
	}
	
	for (int i = 0; i < height; i++ )
		for ( int j = 0; j < length; j++ ){
			if ( board[i][j] == 'O' && flip[i][j] )
				board[i][j] = 'X';
		}
		
}

int main(){
	char a[4][4] = {
		{'X', 'X', 'X', 'X'},
		{'X', 'X', 'O', 'X'},
		{'O', 'X', 'O', 'X'},
		{'O', 'O', 'X', 'X'}
	};
	vector<vector<char> > board;
	vector<char> buf;
	for ( int i = 0; i < 4; i++ )
	{
		buf.clear();
		for ( int j = 0; j < 4; j++)
			buf.push_back(a[i][j]);
		board.push_back(buf);
	}
	solve(board);
	for (int i = 0; i < 4; i++ ){
		for ( int j = 0; j < 4; j++ ){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
