#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>

using namespace std;

void rotate(vector<vector<int> > &matrix){
	
	int len = matrix.size();
	
	if ( len == 1 )
		return;
	
	for ( int i = 0; i < len/2; i++ ){
		int first = i;
		int last = len - 1 - i;
		for ( int j = 0; first < last;  first++, j++ ){
			int tmp = matrix[i][first];
			
			matrix[i][first] = matrix[last-j][i];
			matrix[last-j][i] = matrix[last][last-j];
			matrix[last][last-j] = matrix[first][last];
			matrix[first][last] = tmp;
		}
	}
	return;
}

int main(){
	int a[][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12 },
		{13, 14, 15, 16}
	};
	vector<vector<int> > matrix;
	vector<int> buf;
	for ( int i = 0; i < 4; i++ ){
		for ( int j = 0; j < 4; j++ )
			buf.push_back(a[i][j]);
		matrix.push_back(buf);
		buf.clear();
	}
	rotate(matrix);
	for ( int i = 0; i < 4; i++ ){
		for ( int j = 0; j < 4; j++ )
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	return 0;
}
