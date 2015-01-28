#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

vector<string> isValid(string s){
	
	vector<string> result;
	
	if ( s.length() < 4 && stoi(s) < 255 ){
		result.push_back(s);
		return;
	}
	
	string tmp = "";
	string tmp_res = "";
	vec<int> res;
	
	for ( int i = 0; i < 3; i++ ){
		tmp = tmp + s.substr(0, i+1);
		
		if ( i == 1 && tmp[0] == '0' && tmp[1] != 0 )
			continue;
		
		if ( i == 2 && tmp[0] == '0' && (tmp[1] != '0' || tmp[2] != '0'))
			continue;
		
		if ( i == 2 && stoi(tmp) > 255 )
			continue;
		
		res = restoreIpAddress(s.substr(i+1,s.length()-i-1));
		for ( int j = 0; j < res; j++ ){
			tmp_res = tmp + '.' + res[j];
			result.push_back(tmp_res);
		}
	}
	return result;
}

vector<string> restoreIpAddresses(string s){
	
	vector<string> result;
	
	if ( s.length() > 12 || s.length() < 4 )
		return result;
	
	result = isValid(s);
	return result;
}

int main(){
	string s = "25525511135";
	vector<string> result = restoreIpAddresses(string s);
	for ( int i = 0; i < result.size(); i++ )
		cout << result[i] << endl;
	return 0;
}
