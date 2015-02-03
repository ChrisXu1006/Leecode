#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int uni(int **table, int m, int n ){
    
    if ( table[m-1][n-1] != INT_MIN ){
		 return table[m-1][n-1];
	 }
	  
    int result = 0;

    if ( m == 1 && n == 1 )
		result = 1;

    else if ( m == 1 )
		result = uni(table, m, n-1);

    else if ( n == 1 )
	    result = uni(table, m-1, n);

    else
	    result = uni(table, m, n-1) + uni(table, m-1, n);

    table[m-1][n-1] = result;
	
    return result;    
  }
  
int uniquePaths(int m, int n) {
    int **table;
    table = new int*[m];
    for ( int i = 0; i < m; i++ )
	    table[i] = new int[n];

    for ( int i = 0; i < m; i++ )
	    for ( int j = 0; j < n; j++ )
		    table[i][j] = INT_MIN;
	
	//cout << table[0][1] << endl;
	return uni(table, m, n);
  }

int main(){
	cout << uniquePaths(2,2);
}
