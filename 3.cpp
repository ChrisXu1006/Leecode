#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int lengthOfLongestSubstring1(string s){
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

int lengthOfLongestSubstring2(string s){
	int len = s.length();
	if ( len == 0 )
		return 0;
	
	int exist[256];
	memset(exist, -1, sizeof(exist));
	int head = 0;
	int tail = 0;
	int max1 = 0;
	
	while(tail < len){
		int index = (int)s[tail];
		if (exist[index] == -1){
			exist[index] = tail;
			tail++;
		}
		else{
			cout << head << " " << tail << endl;
			max1 = max(tail-head, max1);
			cout << max1 << endl;
			head = max(head, exist[index] + 1);
			exist[index] = tail;
			tail++;
		}
	}
	cout << head << endl;
	return max(max1, len - head);
}

int main(){
	string s = "abba";
	cout << lengthOfLongestSubstring2(s);
}
