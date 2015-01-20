#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

bool isValid(string &s, int start, int end){
	while ( start < end ){
		if ( s[start] != s[end] )
			return false;
		start++;
		end--;
	}
	return true;
}

void recur(string &s, int start, vector<string> &buf, vector<vector<string> > &res){
	if ( start >= s.length() )
		res.push_back(buf);
	else{
		for (int i = start; i < s.length(); i++ ){
			if ( isValid(s, start, i) ){
				buf.push_back(s.substr(start, i-start+1));
				recur(s, i+1, buf, res);
				buf.pop_back();
			}
		}
	}
}

vector<vector<string> > partition(string s){
	vector<vector<string> > res;
	vector<string> cur;
	recur (s, 0, cur, res);
	return res;
}

int main(){
	vector<vector<string> > result;
	string s = "aab";
	result = partition(s);
	for ( int i = 0; i < result.size(); i++ ){
		cout << "[";
		for ( int j = 0; j < result[i].size(); j++ )
			cout << result[i][j] << ",";
		cout << "]" << endl;
	}
}
