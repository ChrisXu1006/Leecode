#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;

int titleToNumber(string s) {
        int len = s.length();
        int sum = 0;
        int base = 1;
        
        for ( int i = len-1; i >= 0; i-- ){
            sum = sum + (s[i] - 'A' + 1)*base;
            base = base * 26;
        }
        return sum;
}
int main(){
	string s = "A";
	cout << titleToNumber(s) << endl;
	return 0;
}
