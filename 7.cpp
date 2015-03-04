#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int reverse(int x) {
        long int a, b;
        a = x;
        b = 0;
        while ( a != 0 ){
            b = b*10 + (a%10);
            a /= 10;
        }
        if ( b > INT_MAX )
            return 0;
        else if ( b < INT_MIN )
            return 0;
        else
            return b;
    }

int main(){
	cout << reverse(-123);
	return 0;
}
