#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int calculateMinimumHP(vector<vector<int> > &dungeon){
	int row = dungeon.size();
	if ( row == 0 )
		return 0;
	int col = dungeon[0].size();
	
	int **HP;
	HP = new int*[row];
	for ( int i = 0; i < row; i++ )
		HP[i] = new int[col];
	HP[row-1][col-1] = max(1, -dungeon[row-1][col-1]+1);
	
	for ( int j = row - 2; j >= 0; j-- )
		HP[j][col-1] = max(1, HP[j+1][col-1] - dungeon[j][col-1]); 
	
	for ( int j = col - 2; j >= 0; j-- )
		HP[row-1][j] = max(1, HP[row-1][j+1] - dungeon[row-1][j]);
	
	for ( int i = row - 2; i >= 0; i-- ){
		for ( int j = col - 2; j >= 0; j-- )
			HP[i][j] = max(1, min(HP[i+1][j], HP[i][j+1])-dungeon[i][j]);
	}
	return HP[0][0];
}
int main(){
	int A[][2] = {
		{2, 1},
		{1, -1}
	};
	vector<vector<int> > dungeon;
	for ( int i = 0; i < 2; i++ ){
		vector<int> row;
		for ( int j = 0; j < 2; j++ )
			row.push_back(A[i][j]);
		dungeon.push_back(row);
		row.clear();
	}
	cout << calculateMinimumHP(dungeon);
}
