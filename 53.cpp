#include <iostream>
#include <cmath>
#include <cfloat>
#include <limits>
#include <cstring>
#include <string>
#include <vector>

using namespace std;
	
double power(double x, int n){
	
	if ( n == 0 )
		return 1;
	
	double v = power(x, n/2);

	if (n % 2 == 0 )
		return v * v;
	
	else
		return v * v * x;
}

int main(){
	cout << power(2.0, 4);
	
}
