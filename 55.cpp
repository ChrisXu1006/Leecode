#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

bool canJump(int A[], int n){
	int localstep = 0;
	int globalstep = 0;
	
	for ( int i = 0; i <= globalstep && i < n; i++ ){
		localstep = i + A[i];
		globalstep = max(globalstep, localstep);
	}
	
	return globalstep >= (n-1);
	
}

int main(){
	int A[] = { 3, 2, 1, 0, 2};
	cout << canJump(A, 5);
	
}
