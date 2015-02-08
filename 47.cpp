#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>

using namespace std;

void permuteRecur(vector<vector<int> > &permute, vector<int> &buf, vector<int> &num){
	if ( num.empty() ){
		permute.push_back(buf);
		return;
	}
	
	for ( int i = 0; i < num.size(); i++ ){
		
		if ( i > 0 && num[i] == num[i-1])
			continue;
		
		int tmp = num[i];
		buf.push_back(tmp);
		num.erase(num.begin()+i);
		permuteRecur(permute, buf, num);
		buf.pop_back();
		num.insert(num.begin()+i, tmp);
	}
	
	return;
	
}

vector<vector<int> > permuteUnique(vector<int> &num){
	
	vector<vector<int> > permute;
	vector<int> buf;
	
	sort(num.begin(), num.end());
	permuteRecur(permute, buf, num);
	
	return permute;
	
}

int main(){
	int A[] = {-1, -1, 3, -1};
	vector<int> num;
	for ( int i = 0; i < 4; i++ )
		num.push_back(A[i]);
	vector<vector<int> > comb = permuteUnique(num);
	for ( int i = 0; i < comb.size(); i++ ){
		for ( int j = 0; j < comb[i].size(); j++ )
			cout << comb[i][j] << " ";
		cout << endl;
	}
	return 0;
}
