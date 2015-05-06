#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
   
bool isIsomorphic(string s, string t) {
        map<char, char> table;
        vector<char> used(256, false);
        for ( int i = 0; i < t.length(); i++ ){
            int index1 = (int)t[i];
            int index2 = (int)s[i];
            if ( table.find(t[i]) == table.end() ){
                if ( used[index2] )
                    return false;
                else{
                    table[index1] = s[i];
                    used[index2] = true;
                }
            }
            else if ( table[t[i]] != s[i] )
                return false;
        }
        
        return true;
    }
	
int main(){
	string s = "aa";
	string t = "ab";
	cout << isIsomorphic(s, t) << endl;
	return 0;
}