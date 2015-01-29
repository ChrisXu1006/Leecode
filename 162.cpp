#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int find(const vector<int> &num, int start, int end){
	
	if ( start > end )
		return -1;
	
	if ( start == end )
		return start;
	
	if ( end - start == 1){
		if ( num[end] > num[start] && end == num.size() - 1)
			return end;
		else if ( num[start] > num[end] && start == 0)
			return start;
		else
			return -1;
	}
	
	int mid = (start+end)/2;
	
	if ( num[mid] > num[mid-1] && num[mid] > num[mid+1] ){
		return mid;
	}
	
	else{
		int left = find(num, start, mid);
		
		if ( left != -1 )
			return left;
		else{
			int right = find(num, mid, end);
			if (right != -1)
				return right;
		}
	}
	return -1;
}

int findPeakElement(const vector<int> &num){
	int end = num.size()-1;
	return find(num, 0, end);
}

int main(){
	int a[] = {2, 1};
	vector<int> result;
	for ( int i = 0; i < 2; i++ )
		result.push_back(a[i]);
	cout << findPeakElement(result);
}
