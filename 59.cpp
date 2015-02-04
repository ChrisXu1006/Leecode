#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

vector<vector<int> > generateMatrix(int n){
	
    vector<vector<int> > res;
	for ( int i = 0; i < n; i++ ){
		vector<int> buf(n, 0);
		res.push_back(buf);
	}
    
    int len = res.size();
    if ( len == 0 )
   		return res;
	
   	int wid = res[0].size();
	
   	int counter = 1;
   	int urow = 0;
   	int drow = len-1;
   	int lcol = 0;
   	int rcol = wid - 1;
   	int currow = 0;
   	int curcol = 0;
   	int mod = 0;
	    
   	while ( counter <= len * wid ){
		
   		if ( mod == 0 ){
   			res[currow][curcol] = counter;
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
   			res[currow][curcol] = counter;
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
   			res[currow][curcol] = counter;
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
   			res[currow][curcol] = counter;
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
	
   	return  res;
}

int main(){
	vector<vector<int> > matrix;
	
	matrix = generateMatrix(4);
	for ( int i = 0; i < matrix.size(); i++ ){
		for ( int j = 0; j < matrix[0].size(); j++ )
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}
