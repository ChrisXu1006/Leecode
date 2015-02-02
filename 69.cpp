#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int sqrt(int x){
	
	if ( x < 0 )
		return -1;
	
	int left = 0; 
	int right = x;
	right = x/2 < 46340? x/2+1: 46340;
	int mid;
	
	while ( left < right ){
		
		mid = (left + right)/2;
		
		int tmp = mid * mid;
		
		if (  tmp == x )
			return mid;
		
		else if ( tmp > x )
			right = mid - 1;
		
		else{
			
			int midr = mid + 1;
			int tmp1 = midr * midr;
			
			if ( tmp1 == x )
				return midr;
			else if ( tmp1 > x )
				return mid;
			else
				left = mid+1;
		}
	}
	return left;
}

int main(){
	cout << (int)sqrt(INT_MAX) << endl;
	cout << sqrt1(0);
}
