#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int removeDuplicates(int A[], int n){
	
	if ( n <= 2 )
		return n;
	
	int pre = 0;
	int len = 1;
	int cur_num = A[0];
	int num = 1;
	
	for ( int cur = 1; cur < n; cur++ ){
		if ( A[cur] == A[cur-1] ){
			if ( num == 1){
				len++;
				A[pre+1] = A[cur];
				pre++;
			}
			num++;
		}
		
		else{
			cur_num = A[cur];
			num = 1;
			A[pre+1] = A[cur];
			pre++;
			len++;
		}	 
	}
	return len;
}

int main(){
	int A[] = {1, 1, 1, 2, 2, 2, 2, 5, 5, 5, 7, 8 ,9};
	int len = removeDuplicates(A, 13);
	for ( int i = 0; i < len; i++)
		cout << A[i] << " ";
}
