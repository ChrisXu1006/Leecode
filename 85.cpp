#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <ctype.h>

using namespace std;

int maximalRectangle(vector<vector<char> > &matrix){
	
	int len = matrix.size();
	if ( len == 0 )
		return 0;
	int wid = matrix[0].size();
	
	cout << len << wid << endl;
	int** ones = new int*[len];
	for ( int i = 0; i < len; i++ )
		ones[i] = new int[wid];
	
	for ( int i = 0; i < len; i++ ){
		for ( int j = 0; j < wid; j++ ){
			if ( j == 0 ){
				ones[i][j] = matrix[i][j] - '0';
			}
			else{
				if ( matrix[i][j] == '0' )
					ones[i][j] = 0;
				else
					ones[i][j] = ones[i][j-1] + 1;
			}
		}
	}
	//cout << ones[4][4] << endl;
	
	int maxarea = 0;
	
	for ( int i = len-1; i >= 0; i-- ){
		for ( int j = wid-1; j >= 0; j-- ){
			if ( maxarea >= (i+1)*(j+1) )
				continue;
			if ( ones[i][j] == 0 )
				continue;
			int tmp = ones[i][j];
			int min = ones[i][j];
			int row = i;
			while ( row >= 0 ){
				if ( tmp > maxarea )
					maxarea = tmp;
				row--;
				if ( row < 0 )
					break;
				if ( ones[row][j] == 0 )
					break;
				if ( ones[row][j] < min )
					min = ones[row][j];
				tmp = min * (i-row+1);
			}
		}
	}
	return maxarea;
}

int main(){
	char A[][5] = {
		{'1', '1', '1', '1', '1'},
		{'1', '1', '1', '1', '1'},
		{'1', '1', '0', '1', '1'},
		{'1', '1', '1', '0', '1'},
		{'1', '1', '1', '1', '1'}
	};
	vector<vector<char> > matrix;
	vector<char> row;
	row.push_back('0');
	matrix.push_back(row);
	/*for ( int i = 0; i < 5; i++ ){
		vector<char> row;
		for ( int j = 0; j < 5; j++ )
			row.push_back(A[i][j]);
		matrix.push_back(row);
	}*/
	cout << maximalRectangle(matrix);
	return 0;
}
