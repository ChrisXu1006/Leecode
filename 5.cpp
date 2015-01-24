#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

string preProcess(string s) {
  int n = s.length();
  if (n == 0) return "^$";
  string ret = "^";
  for (int i = 0; i < n; i++)
    ret += "#" + s.substr(i, 1);
 
  ret += "#$";
  return ret;
}

string longestPalindrome(string s){
	
	if ( s == "" )
		return "";
	
	if ( s.length() == 1)
		return s;
	
	// pre-processing
	string buf = "";
	buf = preProcess(s);
	int len = buf.length();
	int P[len];
	int C = 0, R = 0;
	for ( int i = 1; i < len - 1; i++ ){
		int i_mirror = C - ( i - C );
		
		P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;
		
		while (buf[i+1+P[i]] == buf[i-1-P[i]])
			P[i]++;
		
		if ( i + P[i] > R ){
			C = i;
			R = i + P[i];
		}
	}
    int maxLen = 0;
    int centerIndex = 0;
    for (int i = 1; i < len-1; i++) {
      if (P[i] > maxLen) {
        maxLen = P[i];
        centerIndex = i;
      }
    }
	//delete[] P;
  
	return s.substr((centerIndex - 1 - maxLen)/2, maxLen);
}

string longestPalindrome1(string s){
	
	if ( s == "" )
		return "";
	
	string buf = "";
	for ( int i = 0; i < s.length(); i ++ )
		buf = buf + "#" + s[i];
	buf = buf + "#";
	
	int len = buf.length();
	int maxIndex = 0;
	int max = 0;
	int P[len];

	for ( int i = 0; i < len; i++ ){
		int L = i-1;
		int R = i+1;
		
		
		if ( buf[i] == '#' ){
			int diff = min(i - 0, len - 1 - i);
			P[i] = 0;
			if ( diff*2 <= max)
				continue;
		}
		else{
			int diff = min(i - 0, len - 1 - i);
			P[i] = 1;
			if ( diff*2 + 1 <= max)
				continue;
		}
		
		while ( L >= 0 && R < len ){
			if ( buf[L] == buf[R] && buf[L] != '#'){
				P[i] += 2;
				L--;
				R++;
			}
			
			else if ( buf[L] != buf[R] )
				break;
			
			else{
				L--;
				R++;
			}
		}
		if ( P[i] > max ){
			max = P[i];
			maxIndex = i;
		}
	}
	
	if ( buf[maxIndex] == '#' )
		return s.substr((maxIndex/2 - max/2), max);
	else
		return s.substr((maxIndex/2 - (max+1)/2+1), max);
}

int main(){
	
	string s = "abb";
	cout << longestPalindrome1(s);
	return 0;
}
