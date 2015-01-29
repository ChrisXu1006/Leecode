#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void buildgrayCode(vector<int> &result, int n){
	
	if ( n == 0 ){
		result.push_back(0);
		return;
	}
	
	buildgrayCode(result, n-1);
	int size = result.size();
	int tmp;
	
	for ( int i = size - 1; i >= 0; i-- ){
		tmp = (int)(pow(2.0, n-1)) + result[i];
		result.push_back(tmp);
	}
	return;
}
	
vector<int> grayCode(int n){
	
	vector<int> result;
	
	buildgrayCode(result, n);
	
	return result;
}

int main(){
	vector<int> result = grayCode(4);
	for ( int i = 0; i < result.size(); i++ )
		cout << result[i] << " ";
}
