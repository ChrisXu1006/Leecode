#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

void extend(vector<vector<char>>& grid, vector<vector<bool>>& table, int row, int col){
        table[row][col] = true;
        
        if (row > 0){
            if ( grid[row-1][col] == '1' && !table[row-1][col] )
                extend(grid, table, row-1, col);
        }
        
        if (row < grid.size()-1 ){
            if ( grid[row+1][col] == '1' && !table[row+1][col] )
                extend(grid, table, row+1, col);
        }
        
        if ( col > 0 ){
            if ( grid[row][col-1] == '1' && !table[row][col-1] )
                extend(grid, table, row, col-1);
        }
        
        if ( col < grid[0].size() -1 ){
            if ( grid[row][col+1] == '1' && !table[row][col+1] )
                extend(grid, table, row, col+1);
        }
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if ( m == 0 )
            return 0;
        int n = grid[0].size();
        vector<vector<bool> > table;
        
        for ( int i = 0; i < m; i++ ){
            vector<bool> row(n, false);
            table.push_back(row);
        }
        
        int counter = 0;
        for ( int i = 0; i < m; i++ ){
            for ( int j = 0; j < n; j++ ){
                if ( grid[i][j] == '1' && !table[i][j] ){
                    counter++;
                    extend(grid, table, i, j);
                }
            }
        }
        return counter;
    }
	
int main(){
	cout << hammingWeight(n) << endl;
	return 0;
}