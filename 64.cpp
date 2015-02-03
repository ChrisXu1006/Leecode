#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int minSum(vector<vector<int> > &grid, int **table, int i, int j){
	
	if (table[i][j] != INT_MIN)
		return table[i][j];
	
	int result = 0;
	
	if ( i == grid.size()-1 && j == grid[0].size()-1 )
		result = 0;
	
	else if ( i == grid.size()-1 )
		result = minSum(grid, table, i, j+1);
	
	else if ( j == grid[0].size() - 1 )
		result = minSum(grid, table, i+1, j);
	
	else
		result = min(minSum(grid, table, i, j+1), minSum(grid, table, i+1, j));
	
	table[i][j] = result + grid[i][j];
	return table[i][j];
}

int minPathSum(vector<vector<int> > &grid){
	
	int len = grid.size();
	int wid = grid[0].size();
	
	int **table;
	table = new int*[len];
	for ( int i = 0; i < len; i++ )
		table[i] = new int[wid];
	
	for ( int i = 0; i < len; i++ )
		for ( int j = 0; j < wid; j++ )
			table[i][j] = INT_MIN;
	
	return minSum(grid, table, 0, 0);
}

int main(){
	cout << intToRoman(1800);
}
