#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool isMatch(string s, string p) {
        int cur1 = 0;
        int cur2 = 0;
        
        int pp = -1;
        int ss = -1;
        while(cur1 < s.length()){
            if( s[cur1] == p[cur2] || p[cur2] == '?' ){
                cur1++;
                cur2++;
                continue;
            }
            if(p[cur2] == '*'){
                pp = cur2;
                cur2++;
                ss = cur1;
                continue;
            }
            if (pp != -1){
                cur2 = pp+1;
                cur1 = ++ss;
                continue;
            }
			cout << cur1 << " " << cur2 << endl;
            return false;
        }
        while (cur2 < p.length() && p[cur2] == '*')
            cur2++;
        return (cur2 == p.length());
    }

int main(){
	string s = "aa";
	string p = "*";
	cout << isMatch(s, p) << endl;
}