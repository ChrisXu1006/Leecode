#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int find(int A[], int start, int end, int target, int rotated){
	
	if ( start > end )
		return -1;
	
	if ( start == end ){
		if ( A[start] == target )
			return start;
		else
			return -1;
	}
	
	int mid = (start + end)/2;
	if ( A[mid] == target )
		return mid;
	
	int index;
	if ( rotated == 0 ){
		if ( target > A[mid] )
			index = find(A, mid+1, end, target, 0);
		else
			index = find(A, start, mid-1, target, 0);
	}
	
	else{
		if ( A[start] < A[mid]){
			if ( target >= A[start] && target < A[mid] )
				index = find ( A, start, mid-1, target, 0 );
			else
				index = find ( A, mid+1, end, target, 1);
		}
		else if ( A[mid] < A[end] )
		{
			if ( target > A[mid] && target <= A[end] )
				index = find ( A, mid+1, end, target, 0);
			else
				index = find ( A, start, mid-1, target, 1 );
		}
		else
			index = find ( A, mid+1, end, target, 0);;
	}
	return index;
	
}

int search(int A[], int n, int target) {
	
	if ( n == 0 )
		return -1;
	
	int result = find(A, 0, n-1, target, 1);
	return result;
}

int main(){
	int A[] = {7, 5};
	cout << search(A, 2, 5);
}
