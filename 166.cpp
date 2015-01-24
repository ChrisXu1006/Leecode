#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;

 string fractionToDecimal(int numerator, int denominator){
	string s = "";
	
	if ( numerator == 0 )
		return "0";
	
	if ( denominator == 0 )
		return s;
	
	if ( (numerator < 0 && denominator > 0 ) || (numerator > 0 && denominator < 0 ) )
		s = "-";
	
    long long int num1 = numerator;
    long long int denominator1= denominator;
    num1 = abs(num1);
    denominator1 = abs(denominator1);
    
	long long int int_num = num1 / denominator1;
	s = s + to_string(int_num);
	long long int mod = num1 % denominator1;
	if ( mod == 0 )
		return s;
	
	string sub = "";

	map<int, int> table;
	while (mod){
        if ( table.find(mod) != table.end() ){
            sub.insert(sub.begin()+table[mod],'(');
            sub += ')';
            break;
        }
        table[mod] = sub.size();
        mod *= 10;
        sub += to_string(mod/denominator1);
        mod = mod%denominator1;
	}
	s = s + '.' + sub;
	return s;
}

int main(){
	fractionToDecimal(2, 1);
	return 0;
}
