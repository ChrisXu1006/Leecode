#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int> > &matrix){
	
    vector<int> buf;
    
    int len = matrix.size();
    if ( len == 0 )
   		return buf;
	
   	int wid = matrix[0].size();
	
   	int counter = 0;
   	int urow = 0;
   	int drow = len-1;
   	int lcol = 0;
   	int rcol = wid - 1;
   	int currow = 0;
   	int curcol = 0;
   	int mod = 0;
	    
   	while ( counter < len * wid ){
		
   		if ( mod == 0 ){
   			buf.push_back(matrix[currow][curcol]);
   			counter++;
   			if ( curcol == rcol ){
				currow++;
   				mod = 1;
   				urow++;
   				continue;
   			}
   			curcol++;
   		}
		
   		else if ( mod == 1 ){
   			buf.push_back(matrix[currow][curcol]);
   			counter++;
   			if ( currow == drow ){
				curcol--;
   				mod = 2;
   				rcol--;
				continue;
   			}
   			currow++;
   		}
		
   		else if ( mod == 2 ){
   			buf.push_back(matrix[currow][curcol]);
   			counter++;
   			if ( curcol == lcol ){
				currow--;
   				mod = 3;
   				drow--;
				continue;
   			}
   			curcol--;
   		}
		
   		else{
   			buf.push_back(matrix[currow][curcol]);
   			counter++;
   			if ( currow == urow ){
				curcol++;
   				mod = 0;
   				lcol++;
				continue;
   			}
   			currow--;
   		}
		
   	}
	
   	return  buf;
}

int main(){
	int a[3][2] = {
		{2, 5},
		{8, 4},
		{0, -1}
	};
	vector<vector<int> > matrix;
	vector<int> row;
	
	for ( int i = 0; i < 3; i++ ){
		for ( int j = 0; j < 2; j++ )
			row.push_back(a[i][j]);
		matrix.push_back(row);
		row.clear();
	}
	
	row = spiralOrder(matrix);
	for ( int i = 0; i < row.size(); i++ )
		cout << row[i] << " ";
}
