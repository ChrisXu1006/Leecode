#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int lengthOfLongestSubstring(string s){
	if ( s == "" )
		return 0;
	
	if ( s.length() == 1 )
		return 1;
	
	int curlen = 1;
	int maxlen = 1;
	int a[256];
	memset(a, -1, sizeof(a));
	int cur = 1;
	a[(int)s[0]] = 0;
	while ( cur < s.length() ){
		if ( a[(int)s[cur]] == -1 ){
			curlen++;
			a[(int)s[cur]] = cur;
			cur++;
		}
		
		else{
			if ( curlen > maxlen )
				maxlen = curlen;
			cur = a[(int)s[cur]]+1;
			curlen = 0;
			memset(a, -1, sizeof(a));
		}
	}
	if( curlen > maxlen )
		maxlen = curlen;
	return maxlen;
}

int main(){
	string s = "aabcedefg";
	cout << lengthOfLongestSubstring(s);
}
