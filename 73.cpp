#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void setZeroes(vector<vector<int> > &matrix){
	
	int len = matrix.size();
	int wid = matrix[0].size();
	
	int row[len];
	int column[wid];
	
	memset(row, 0,  sizeof(row));
	memset(column, 0, sizeof(column));
	
	for ( int i = 0; i < len; i++ )
		for ( int j = 0; j < wid; j++ ){
			if ( matrix[i][j] == 0 ){
				row[i] = 1;
				column[j] = 1;
			}
		}
	
	for ( int i = 0; i < len; i++ )
		for ( int j = 0; j < wid; j++ ){
			if ( row[i] || column[j] )
				matrix[i][j] = 0;
		}
	return;
}

int main(){
	int A[3][4] = {
		{1, 3, 5 ,7},
		{10, 0, 16, 20},
		{23, 30, 34, 50}
	};
	vector<vector<int> > matrix;
	vector<int> row;
	for ( int i = 0; i < 3; i++ ){
		row.clear();
		for ( int j = 0; j < 4; j++ )
			row.push_back(A[i][j]);
		matrix.push_back(row);
	}
	
	setZeroes(matrix);
	
	for ( int i = 0; i < matrix.size(); i++ ){
		for ( int j = 0; j < matrix[i].size(); j ++ )
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}
