#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

bool find(int A[], int start, int end, int target, int rotated){
	
	if ( start > end )
		return false;
	
	if ( start == end ){
		if ( A[start] == target )
			return true;
		else
			return false;
	}
	
	int mid = (start + end)/2;
	if ( A[mid] == target )
		return true;
	
	bool index = false;
	if ( rotated == 0 ){
		if ( target > A[mid] )
			index = find(A, mid+1, end, target, 0);
		else
			index = find(A, start, mid-1, target, 0);
	}
	
	else {
		
		if ( A[start] < A[mid]){
			if ( target >= A[start] && target < A[mid] )
				index = find ( A, start, mid-1, target, 0 );
			else
				index = find ( A, mid+1, end, target, 1);
			if ( index )
				return index;
		}
		
		else if ( A[mid] < A[end] )
		{
			if ( target > A[mid] && target <= A[end] )
				index = find ( A, mid+1, end, target, 0);
			else
				index = find ( A, start, mid-1, target, 1 );
			if ( index )
				return index;
		}
		
		else if ( A[start] == A[mid] && start != mid ){
			index = find(A, start, mid-1, target, 1);
			if ( index  )
				return index;
			index = find(A, mid+1, end, target, 1);
		}
		
		else if ( A[mid] == A[end] && mid != end ){
			index = find ( A, mid+1, end, target, 1);
			if ( index )
				return index;
			index = find(A, start, mid-1, target, 1);
		}
		
		else if ( mid == start )
			index = find( A, mid+1, end, target, 1);
		
		else if ( mid == end)
			index = find( A, start, mid-1, target, 1); 
	}
	return index;
}

bool search(int A[], int n, int target) {
	
	if ( n == 0 )
		return -1;
	
	bool result = find(A, 0, n-1, target, 1);
	return result;
}

int main(){
	int A[] = {1, 1, 7, 1};
	cout << search(A, 4, 2);
}
