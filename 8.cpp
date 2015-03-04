#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int atoi(string str) {
        if (str == "")
            return 0;
            
        int cur = 0;
        while ( str[cur] == ' ' )
            cur++;
        
        int pos = 0;
        int neg = 0;
        while ( str[cur] == '+' || str[cur] == '-'){
            if ( str[cur] == '+')
                pos++;
            else
                neg++;
            cur++;
        }
        if( pos > 1 || neg > 1 || (pos > 0 && neg >0 ))
            return 0;
        
        long int result = 0;
        while (isdigit(str[cur])){
            result = result*10 + (str[cur]-'0');
            if ( result >= INT_MAX && neg == 0 )
                return INT_MAX;
            if ( result > INT_MAX && neg > 0 )
                return INT_MIN;
            cur++;
        }
        if (neg)
            result = 0 - result;
        return (int)result;
    }

int main(){
	cout << atoi("  +1");
	return 0;
}
