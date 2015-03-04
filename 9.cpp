#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

bool isPalindrome(int x) {
        if ( x < 0 )
            return false;
        if ( x < 10 )
            return true;
        
        int bit = 0;
        int y = x;
        while ( y > 0 ){
            bit++;
            y /= 10;
        }
        for ( int i = 0; i < bit/2; i++ ){
            y = y*10 + (x%10);
            x /= 10;
        }
        if ( bit % 2 == 1 )
            x /= 10;
        
        if ( x == y )
            return true;
        else
            return false;
    }

int main(){
	cout << isPalindrome(121);
	return 0;
}
