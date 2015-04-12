#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int firstMissingPositive(int A[], int n) {
        if ( n <= 0 )
            return -1;
        
        for ( int i = 0; i < n; ){
			
            if ( A[i] <= 0 || A[i] > n || A[i] == i+1 )
                i++;
            else{
                int index = A[i]-1;
				if ( A[i] == A[index]){
					i++;
					continue;
				}
                int tmp = A[i];
                A[i] = A[index];
                A[index] = tmp;
            }
			for ( int k = 0; k < n; k++ )
				cout << A[k] << " ";
			cout << endl;
        }
        
		for ( int i = 0; i < n; i++ )
			cout << A[i] << " ";
		cout << endl;
		
        for ( int i = 0; i < n; i++ ){
            if ( A[i] != (i+1) )
                return (i+1);
        }
        return n+1;
    }
int main(){
	int A[] = {1,1};
	cout << firstMissingPositive(A,2) << endl;
	return 0;
}