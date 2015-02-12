#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool isMatch(const char *s, const char *p){
	
	if ( *p == '\0' )
		return *s == '\0';
	
	if ( *(p+1) != '*' ){
		return ((*p == *s) || ( *p == '.' && *s != '\0')) && isMatch(s+1, p+1);
	}
	
	while ((*p == *s) || (*p == '.' && *s != '\0')){
		if ( isMatch(s,p+2) )
			return true;
		s++;
	}
	return isMatch(s, p+2);
}

int main(){
    string s = "aab";
	string p = "c*a*b";
	const char *s1 = s.c_str();
	const char *p1 = p.c_str();
	cout << isMatch(s1, p1);
}
