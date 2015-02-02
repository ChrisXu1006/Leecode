#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int searchInsert(int A[], int n, int target){
	
	if ( n == 0 )
		return 0;
	
	int left = 0;
	int right = n - 1;
	int mid;
	
	while ( left <= right ){
		mid = (left + right)/2;
		
		if ( A[mid] == target )
			return mid;
		
		else if ( A[mid] > target )
			right = mid - 1;
		
		else{
			if ( mid+1 < n ){
				if ( A[mid+1] > target )
					return mid+1;
			}
			left = mid + 1;
			
		}	
	}
	return left;
}

int main(){
	int A[4] = {5, 7};
	cout << searchInsert(A, 2, 1);
}
