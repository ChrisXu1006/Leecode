#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int maxSubArray(int A[], int n){
	
	if ( n == 0 )
		return 0;
	
	int local = 0;
	int global = INT_MIN;
	
	for ( int i = 0; i < n; i++ )
	{
		if ( local + A[i] < A[i])
			local = A[i];
		else 
			local = local + A[i];
		
		if ( local > global )
			global = local;
	}
	return global;
	
}

int main(){
	int A[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
	cout << maxSubArray(A, 9);
	
}
