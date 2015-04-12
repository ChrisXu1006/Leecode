#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

string countAndSay(int n) {
       if ( n <= 0 )
           return "";
       
       string s = "1";
       string tmp;
       for ( int i = 1; i < n; i++ ){
           tmp = "";
           int counter = 1;
           for ( int j = 1; j < s.length(); j++){
               if ( s[j] == s[j-1] )
                   counter++;
               else{
                   tmp = tmp + char('0' + counter) + s[j-1];
                   counter=1;
               }
           }
           tmp = tmp + char('0' + counter) + s[s.length()-1];
           s = tmp;
       }
       return s;
   }
int main(){
	cout << countAndSay(4) << endl;
	return 0;
}