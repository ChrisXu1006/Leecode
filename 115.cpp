#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;

int numDistinct(string S, string T){
	
	int len1 = S.length();
	int len2 = T.length();
	
	int **dp;
	dp = new int*[len2+1];
	for ( int i = 0; i <= len2; i++ )
		dp[i] = new int[len1+1];
	
	for ( int i = 0; i <= len1; i++ )
		dp[0][i] = 1;
	
	for ( int i = 1; i <= len2; i++ ){
		dp[i][0] = 0;
	}
	
	for ( int i = 1; i <= len2; i++ )
		for ( int j = 1; j <= len1; j++ ){
			if ( T[i-1] != S[j-1] )
				dp[i][j] = dp[i][j-1];
			else
				dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
	}
	return dp[len2][len1];
}

int main(){
	string S = "b";
	string T = "a";
	cout << numDistinct(S,T);
	return 0;
}
