#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;

int trailingZeroes(int n) {
     int sum = 0;
     long int base = 5;
     while ( base <= n ){
		 cout << base << endl;
         sum = sum + (n/base);
         base = base * 5;
     }
     return sum;
}
int main(){
	int n = 2147483647;
	cout << trailingZeroes(n) << endl;
	return 0;
}
