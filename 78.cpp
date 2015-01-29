#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

vector<vector<int> > subsets(vector<int> &S){
	
	sort(S.begin(), S.end());
	vector<vector<int> > result;
	vector<int> buf;
	result.push_back(buf);
	
	for ( int i = S.size() - 1; i >= 0; i-- ){
		int size = result.size();
		for ( int j = 0; j < size; j++ ){
			buf = result[j];
			buf.insert(buf.begin(), S[i]);
			result.push_back(buf);
			buf.clear();
		}
	}
	return result;
}

int main(){
	int a[] = {1, 2, 3};
	vector<int> num;
	for (int i = 0; i < 3; i++ )
		num.push_back(a[i]);
	vector<vector<int> > result = subsetWithDup(num);
	for ( int i = 0; i < result.size(); i++ ){
		for ( int j = 0; j < result[i].size(); j++ )
			cout << result[i][j] << " ";
		cout << endl;
	}
	return 0;
}
