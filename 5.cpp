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

int main(){
	
	string s = "abba";
	cout << longestPalindrome(s);
	return 0;
}
