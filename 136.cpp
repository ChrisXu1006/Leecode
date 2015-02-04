#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int singleNumber(int A[], int n){
	
	int left = A[0];
	
	for ( int i = 1; i < n; i++ )
		left = left ^ A[i];
	
	return left;
}

int main(){
	int A[] = { 5, 1, 2, 3, 2, 5, 1};
	cout << singleNumber(A, 7);
}
