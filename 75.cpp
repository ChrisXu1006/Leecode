#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void sortColors1(int A[], int n){
	
	if ( n == 0 )
		return;
	
	int red = 0, white = 0, blue = 0;
	
	for ( int i = 0; i < n; i++ ){
		
		if (A[i] == 0)
			red++;
		else if (A[i] == 1)
			white++;
		else
			blue++;
	}
	
	for ( int i = 0; i< n; i++ ){
		
		if ( red > 0 ){
			A[i] = 0;
			red--;
		}
		
		else if (white > 0){
			A[i] = 1;
			white--;
		}
		
		else{
			A[i] = 2;
		}
	}
	return;
}

void sortColors2(int A[], int n){
	
	int redindex = 0, blueindex = n - 1;
	
	for ( int i = 0; i < blueindex + 1;){
		
		if (A[i] == 0){
			swap(A[i], A[redindex]);
			redindex++;
			i++;
			continue;
		}
		
		else if ( A[i] == 2 ){
			swap(A[i], A[blueindex]);
			blueindex--;
		}
		else
			i++;
		
	}
	return;
}


int main(){
	int A[] = { 1, 2, 0};
	sortColors2(A, 3);
	for ( int i = 0; i < 3; i++ )
		cout << A[i] << " ";
	
}
