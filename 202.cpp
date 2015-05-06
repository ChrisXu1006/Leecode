#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

unordered_map<int, bool> table;    
bool isHappy(int n) {
    if ( table.find(n) != table.end() )
        return false;
        
    int tmp = n;
    int res = 0;
    while ( tmp > 0 ){
        res = res + (int)(pow( tmp%10, 2) );
        tmp = tmp /10;
    }
        
    if ( res == 1 )
        return true;
    else{
        table[n] = false;
        return isHappy(res);
    }
}
	
int main(){
	cout << isHappy(100) << endl;
	return 0;
}