#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int romanToInt(string s) {
       int len = s.length();
       if ( len == 0 )
           return 0;
       int value[7] = {1, 5, 10, 50, 100, 500, 1000};
       int count[7] = {0, 0, 0, 0, 0, 0, 0};
       
       for ( int i = len - 1; i >= 0; i-- ){
           if ( s[i] == 'I' ){
               if (count[1] > 0 || count [2] > 0)
                   count[0]--;
               else
                   count[0]++;
           }
           
           else if ( s[i] == 'V' )
               count[1]++;
               
           else if ( s[i] == 'X' ){
               if (count[3] > 0 || count [4] > 0)
                   count[2]--;
               else
                   count[2]++;
           }
           
           else if ( s[i] == 'L' )
               count[3]++;
               
           else if ( s[i] == 'C' ){
               if (count[5] > 0 || count [6] > 0)
                   count[4]--;
               else
                   count[4]++;
           }
           
           else if ( s[i] == 'D' )
               count[5]++;
           
           else
               count[6]++;
       }
       
       int result = 0;
       for ( int i = 0; i < 7; i++ )
           result = result + value[i]*count[i];
       return result;
   }
   
int main(){
	cout << romanToInt("X");
}
