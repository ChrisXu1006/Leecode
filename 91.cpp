#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unodered_map>

using namespace std;

  int numDecodings1(unordered_map<string,int> &table, string s){
	
	if (table.find(s) != table.end())
		return table[s];
	
	int result = 0;
	int len = s.length();
	
	if ( len == 0 )
		return 0;
	
	if ( len == 1 && s[0] != '0' ){
		pair<string, int> element(s, 1);
		table.insert(element);
		return 1;
	}
	else if ( len == 1 ){
		pair<string, int> element(s, 0);
		table.insert(element);
		return 0;
	}
	
	if (len == 2){
		if ( s[0] == '0' ){
			result = 0;
			pair<string, int> element(s, 0);
			table.insert(element);
			return result;
		}
		else if ( s[0] <= '2' && s[1] == '0'){
			result = 1;
			pair<string, int> element(s, 1);
			table.insert(element);
			return result;
		}
		else if ( stoi(s) <= 26 ){
			result = 2;
			pair<string, int> element(s, 2);
			table.insert(element);
			return result;
		}
	}
	
	
	if (s[0] == '0'){
		result = 0;
		pair<string, int> element(s, 0);
		table.insert(element);
		return result;
	}
	
	else{
		if ( s[0] >= '1' && s[0] <= '9')
			result += 1*numDecodings1(table,s.substr(1, len-1));
		
		if ( s[0] <= '2' && s[1] == '0')
			result += 1*numDecodings1(table,s.substr(2, len-2));
		
		else if ( stoi(s.substr(0,2)) <= 26 )
			result += 1*numDecodings1(table,s.substr(2, len-2));
	}
	pair<string, int> element(s, result);
	table.insert(element);
	return result;
}

int numDecodings(string s){
	unordered_map<string, int> table;
	int result = numDecodings1(table, s);
	return result;
}
int main(){
	string s = "17";
	cout << numDecodings(s);
}
