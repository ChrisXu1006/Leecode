#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int uni(vector<vector<int> > &Grid, int **table, int i, int j){
	
	if ( table[i][j] != -1 )
		return table[i][j];
	
	int len = Grid.size()-1;
	int wid = Grid[0].size()-1;
	
	int result = -1;
	
	if (Grid[i][j] == 1)
		result = 0;
		
	else{
		if ( i == len && j == wid )
			result = 1;
		
		else if ( i == len )
			result = uni(Grid, table, i, j+1);
		
		else if ( j == wid )
			result = uni(Grid, table, i+1, j);
		
		else
			result = uni(Grid, table, i+1, j) + uni(Grid, table, i, j+1);
	}
	
	table[i][j] = result;
	return result;
}

int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid){
	
	int len = obstacleGrid.size();
	int wid = obstacleGrid[0].size();
	
	int **table;
	table = new int*[len];
	for ( int i = 0; i < len; i++ )
		table[i] = new int[wid];
	
	for ( int i = 0; i < len; i++ )
		for ( int j = 0; j < wid; j++ )
			table[i][j] = -1;
	
	return uni(obstacleGrid, table, 0, 0);
}

int main(){
	int a[1][2] = {
		{0,0}
	};
	vector<vector<int> > grid;
	vector<int> buf;
	for ( int i = 0; i < 1; i++ ){
		for ( int j = 0; j < 2; j++ )
			buf.push_back(a[i][j]);
		grid.push_back(buf);
	}
	cout << uniquePathsWithObstacles(grid);
}
