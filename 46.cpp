#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>

using namespace std;

void permutegen(vector<vector<int> > &res, vector<int> &num, vector<int> &buf, int size){
	
	if ( num.empty() ){
		res.push_back(buf);
		return;
	}
	
	for ( int i = 0; i < num.size(); i++ ){
		int tmp = num[i];
		buf.push_back(num[i]);
		num.erase(num.begin()+i);
		permutegen(res, num, buf, size);
		buf.pop_back();
		num.insert(num.begin()+i, tmp);
	}
	return;
}

vector<vector<int> > permute(vector<int> &num){
	
	//sort(num.begin(), num.end());
	vector<vector<int> > res;
	vector<int> buf;
	
	int size = num.size();
	permutegen(res, num, buf, size);
	
	return res;
}

int main(){
	int A[] = {5, 4, 6, 2};
	vector<int> num;
	for ( int i = 0; i < 4; i++ )
		num.push_back(A[i]);
	vector<vector<int> > result = permute(num);
	for ( int i = 0; i < result.size(); i++ ){
		for ( int j = 0; j < result[i].size(); j++ )
			cout << result[i][j] << " ";
    	cout << endl;
    }
	return 0;
}
