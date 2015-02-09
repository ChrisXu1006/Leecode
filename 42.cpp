#include <iostream>
#include <cstring>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int trap(int A[], int n){
	
	int contain = 0;
	
	if ( n == 0 )
		return 0;
	
	int maxleft[n];
	int maxright[n];
	
	int max = A[0];
	
	for ( int i = 1; i < n; i++ ){
		maxleft[i] = max;
		if ( A[i] > max )
			max = A[i];
	}
	
	max = A[n-1];
	for ( int i = n - 2; i >= 0; i-- ){
		maxright[i] = max;
		if ( A[i] > max )
			max = A[i];
	}
	
	for ( int i = 0; i < n - 1; i++ ){
		int trap = min(maxleft[i], maxright[i]) - A[i];
		if ( trap > 0 )
			contain += trap;
	}
	return contain;
}

int main(){
	int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	cout <<  trap(A, 12);
	
	return 0;
}
