#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

string getPermutation(int n, int k){
	
	string s = "";
	
	int base = 1;
	int cur = n - 1;
	vector<int> buf;
	for ( int i = 1; i <= n-1; i++ ){
		base *= i;
		buf.push_back(i);
	}
	buf.push_back(n);
	
	while ( cur > 0 ){
		int range = k / base;
		if ( k % base == 0 ){
			range--;
			k = base;
		}
		else
			k = k % base;
		s = s + (char)('0' + buf[range]);
		buf.erase(buf.begin()+range);
		base = base / cur;
		cur--;
	}
	
	s = s + (char)('0' + buf[0]);
	return s;
}

int main(){
	cout << getPermutation(1,1);
}
