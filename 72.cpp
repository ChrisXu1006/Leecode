#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <ctype.h>

using namespace std;

map<string, int> table;

int minDistance(string word1, string word2){
	
	int len1 = word1.length();
	int len2 = word2.length();
	
	int **dp = new int*[len1+1];
	for ( int i = 0; i <= len1; i++ )
		dp[i] = new int[len2+1];
	
	for ( int i = 0; i <= len1; i++ )
		dp[i][0] = i;
	
	for ( int j = 0; j <= len2; j++ )
		dp[0][j] = j;
	
	for ( int i = 0; i < len1; i++ ){
		char c1 = word1[i];
		for ( int j = 0; j < len2; j++ ){
			char c2 = word2[j];
			if ( c1 == c2 )
				dp[i+1][j+1] = dp[i][j];
			else{
				int replace = dp[i][j] + 1;
				int insert = dp[i][j+1] + 1;
				int delet = dp[i+1][j] + 1;
				
				dp[i+1][j+1] = min(min(replace, insert), delet);
			}
		}
	}
	return dp[len1][len2];
	
}

int main(){
	string s1 = "abd";
	string s2 = "abc";
	cout << minDistance(s1, s2);
}
