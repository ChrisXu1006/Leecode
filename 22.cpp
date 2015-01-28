#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void generatestring(vector<string> &result, int left, int right, string s){
	if ( right < left || left < 0 )
		return;
	
	if ( left == 0 && right == 0 ){
		result.push_back(s);
		return;
	}
	else{
		string snew;
		if ( left > 0 ){
			snew = s + '(';
			generatestring(result, left-1, right, snew);
		}
		if ( right > left ){
			snew = s + ')';
			generatestring(result, left, right-1, snew);
		}
	}
}

vector<string> generateParenthesis(int n){
	vector<string> result;
	
	if (n <= 0)
		return result;
	
	string s = "";
	generatestring(result, n, n, s);
	return result;
}

int main(){
	vector<string> result = generateParenthesis(3);
	for ( int i = 0; i < result.size(); i++ )
		cout << result[i] << endl;
	return 0;
}
