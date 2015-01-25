#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int find(vector<int> &num, int start, int end){
	
	if( start == end )
		return num[start];
	
	if ( end - start == 1 ){
		if ( num[start] < num[end] )
			return num[start];
		else
			return num[end];
	}
	
	int mid = (start + end)/2;
	
	if ( num[mid] > num[end] )
		return find(num, mid+1, end);
	else
		return find(num, start, mid);
}

int findMin(vector<int> &num){
	if ( num.size() == 0 )
		return 0;
	
	int result = find(num, 0, num.size()-1);
	return result;
	
}

int main(){
	int a[] = {4, 5, 6, 17, 20, 1, 2};
	vector<int> num;
	for ( int i = 0; i < 7; i++ )
		num.push_back(a[i]);
	cout << findMin(num);
	return 0;
}
