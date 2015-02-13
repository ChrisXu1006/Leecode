#include <iostream>
#include <cstring>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int jump(int A[], int n){
	
	int ret = 0; 
	int last = 0;
	int curr = 0;
	for ( int i = 0; i <n; i++ ){
		if ( i > last ){
			last = curr;
			++ret;
		}
		curr = max(curr, i+A[i]);
	}
	return ret;
}

int main(){
	int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	cout <<  trap(A, 12);
	
	return 0;
}
