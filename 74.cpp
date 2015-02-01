#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

bool searchMatrix(vector<vector<int> > &matrix, int target){
 	
	int length = matrix.size();
	int width  = matrix[0].size();

	int mid;
	int left = 0;
	int right = length - 1;
	int cur = 0;
	
	while ( left + 1 < right ){
		
		mid = (left + right)/2;
		
		if ( matrix[mid][0] == target )
			return true;
		
		else if ( target < matrix[mid][0] )
			right = mid - 1;
		
		else
			left = mid;
	}
	
	if ( right - left == 1){
		if (matrix[left][width-1] == target)
			return true;
		
		else if (matrix[left][width-1] > target)
			cur = left;
		
		else
			cur = right;
	}
	else
		cur = left;
	
	left = 0;
	right = width - 1;
	
	while ( left <= right ){
		
		mid = (left + right)/2;
		
		if ( matrix[cur][mid] == target )
			return true;
		
		else if ( target < matrix[cur][mid] )
			right = mid - 1;
		
		else
			left = mid + 1;
	}
	return false;
}

int main(){
	int A[3][4] = {
		{1, 3, 5 ,7},
		{10, 11, 16, 20},
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
	cout << searchMatrix(matrix, 55);
}
