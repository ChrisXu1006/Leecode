#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int divide(int dividend, int divisor){
// dividend=INt_MAX，-dividend overflow, use long long
      long long a = dividend >= 0 ? dividend : -(long long)dividend;
      // divisor=INt_MAX，-divisor overflow,use long long
      long long b = divisor >= 0 ? divisor : -(long long)divisor;
      long long result = 0;
      while(a >= b){
          long long c = b;
          for(int i = 0;a >= c;++i,c <<= 1){
              a -= c;
              result += 1 << i;
          }//for
      }//while
      if((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)){
          result = -result;
      }//if
      // If it is overflow, return MAX_INT.
      if (result > INT_MAX || result < INT_MIN){
          result = INT_MAX;
      }
      return static_cast<int>(result);	
}

int main(){
	cout << divide(-2147483648, 1);
}
