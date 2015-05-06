#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int rangeBitwiseAnd(int m, int n) {
    if ( m == 0 )
        return 0;
        
    if ( m == 1 && n == 1 )
        return 1;
        
    if ( n > m )
        return 2*rangeBitwiseAnd(m/2, n/2);
}
	
int main(){
	cout << rangeBitwiseAnd(1,2) << endl;
	return 0;
}