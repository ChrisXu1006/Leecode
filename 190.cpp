#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

uint32_t reverseBits(uint32_t n) {
       uint32_t res = 0;
       for ( int i = 0; i < 31; i++ ){
           res += n & 1;
           res = res << 1;
           n = n >> 1;
       }
       res += n & 1;
       return res;
}

int main(){
	uint32_t n = 1;
	cout << reverseBits(n) << endl;
	return 0;
}