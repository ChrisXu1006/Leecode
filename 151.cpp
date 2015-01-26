#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void reverseWords(string &s){
	int start = 0;
	string result = "";
	while ( s[start] == ' ' )
		start++;
	
	int hd = start;
	int tl = start;
	for ( int i = start; i < s.length(); i++ ){
		
		if ( i == s.length() - 1 && s[i] != ' '){
			tl++;
			if ( result.length () > 0 )
				result = s.substr(hd, tl-hd+1) + " " + result;
			else
				result = s.substr(hd, tl-hd+1);
			continue;
		}
		
		if ( s[i] == ' ' && s[i-1] != ' ' && i > start ){
			if ( result.length () > 0 )
				result = s.substr(hd, tl-hd+1) + " " + result;
			else
				result = s.substr(hd, tl-hd+1);
			hd = i;
		}
		
		else if ( s[i] != ' ' && s[i-1] == ' ' && i > start ){
			hd = i;
			tl = i;
		}
		
		else if ( s[i] != ' ' && s[i-1] != ' ' && i > start )
			tl++;

	}
	s = result;
}


int main(){
	string s = "a";
	reverseWords(s);
	cout << s;
	return 0;
}
