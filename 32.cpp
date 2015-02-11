#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <ctype.h>

using namespace std;

int longestValidParentheses(string s){
	
	stack<int> buf;
	
	int len = s.length();
	int pre = -1;
	int global = 0;
	
	for ( int i = 0; i < len; i++ ){
		if ( s[i] == '(' )
			buf.push(i);
		else{
			if ( !buf.empty() ){
				buf.pop();
				if ( buf.empty() )
					global = max(i - pre, global);
				else
					global = max(i - buf.top(), global);
			}
			else
				pre = i;
		}
	}
	return global;	
			
}

int main(){
	string s = "())()()(()";
	cout << longestValidParentheses(s);
}
