#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int hammingWeight(uint32_t n) {
       int counter = 0;
       for ( int i = 0; i < 32; i++ ){
           if ( n & 1 )
               counter++;
           n = n >> 1;
       }
       return counter;
   }

int main(){
	uint32_t n = 1;
	cout << hammingWeight(n) << endl;
	return 0;
}