#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;

string convertToTitle(int n) {
        if ( n <= 0 )
            return 0;
        
        string res = "";
        while ( n > 0 ){
            int tmp = n % 26;
            if ( tmp != 0 ){
                res = (char)(tmp - 1 + 'A') + res;
                n = n/26;
            }
            else{
                res = 'Z' + res;
                n = n/26 - 1;
            }
        }
        return res;
    }

int main(){
	cout << convertToTitle(26) << endl;
	return 0;
}
