#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
//#include <unodered_map>

using namespace std;

int numDecodings(string s){
	
	if ( s.length() == 0 )
		return 0;
	
	if ( s.length() == 1 && s[0] != '0' ){
		return 1;
	}
	else if ( s.length() == 1 ){
		return 0;
	}
	
	if (s.length() == 2){
		if ( s[0] == '0' )
			return 0;
		else if ( s[0] <= '2' && s[1] == '0')
			return 1;
		else if ( s[0] <= '2' && s[1] <= '6')
			return 2;
	}
	
	int result = 0;
	int len = s.length();
	
	if (s[0] == '0')
		result = 0;
	
	else{
		if ( s[0] >= '1' && s[0] <= '9')
			result += 1*numDecodings(s.substr(1, len-1));
		
		if ( s[0] <= '2' && s[1] == '0')
			result += 1*numDecodings(s.substr(2, len-2));
		
		else if ( s[0] <= '2' && s[1] <= '6')
			result += 1*numDecodings(s.substr(2, len-2));
	}
	return result;
}

int main(){
	string s = "17";
	cout << numDecodings(s);
}
