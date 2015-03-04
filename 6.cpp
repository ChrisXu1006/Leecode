#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

string convert(string s, int nRows) {
	if ( nRows == 1 )
		return s;
        
    int iter = 2*nRows-2;
    string result = "";
    int len = s.length();
    for ( int i = 0; i < len; i = i + iter )
        result = result + s[i];
    for ( int i = 1; i < nRows-1; i++ ){
        for ( int j  = i; j < len; j = j + iter ){
            result = result + s[j];
            if ( j + iter - 2*i < len )
                result = result + s[j +iter - 2*i];
        }
    }
    for ( int i = nRows-1; i < len; i = i + iter )
        result = result + s[i];
    return result;
}

int main(){
	cout << convert("PAYPALISHIRING", 3);
	return 0;
}
