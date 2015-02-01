#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void search(int A[], vector<int> &res, int left, int right, int n, int target){
	
	if ( left > right )
		return;
	
	int mid = (left + right)/2;
	
	if ( A[mid] == target ){
		int cur = mid-1;
		while ( A[cur] == target && cur >= 0 )
			cur--;
		res.push_back(cur+1);
		
		cur = mid+1;
		while ( A[cur] == target && cur < n )
			cur++;
		res.push_back(cur-1);
		return;
	}
	
	else if ( A[mid] > target )
		search(A, res, left, mid-1, n, target);
	
	else
		search(A, res, mid+1, right, n, target);
	
	return;
	
}

vector<int> searchRange(int A[], int n, int target){
	
	int left = 0;
	int right = n - 1;
	
	vector<int> res;
	search(A, res, left, right, n, target);
	
	if ( res.empty() ){
		res.push_back(-1);
		res.push_back(-1);
	}
	return res;
}

int main(){
	int A[6] = {5, 7, 7, 8, 8, 10};
	vector<int> res = searchRange(A, 6, 10);
	cout << res[0] << " " << res[1] << endl;
}
