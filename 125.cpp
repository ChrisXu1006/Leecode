#include <iostream>
#include <vector>

using namespace std;
	
bool isPalindrome(string s) {
	int len = s.length();
    if ( len == 0 )
        return true;
       
    string S = "";
    for ( int i = 0; i < len; i++ ){
        if ( isalpha(s[i]) ){
            if ( s[i] >= 'A' )
                S += tolower(s[i]);
            else
                S += s[i];
        }
		if  (isdigit(s[i]))
			S += s[i];
    }
    
	cout << S << endl;
    for ( int i = 0; i < S.length()/2; i++ ){
        if ( S[i] != S[S.length()-1-i] )
            return false;
    }
    return true;
}

int main(){
	string s = "1a2";
	cout << isPalindrome(s);
	return 0;
}