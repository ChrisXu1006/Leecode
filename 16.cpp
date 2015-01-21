#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

bool threeSum(vector<int> &num, int target){
	
	for ( int i = 0; i < num.size() - 2; i++ ){
		
		if ( i > 0 && num[i] == num[i-1])
			continue;
			
		int a = num[i];
		int start = i+1;
		int end = num.size() - 1;
		
		while ( start < end ){
			
			int b = num[start];
			int c = num[end];
			
			/*if ( start - 1 > i && num[start] == num[start-1] ){
				start++;
				continue;
			}
			
			if ( end + 1 < num.size() && num[end] == num[end+1] ){
				end--;
				continue;
			}*/
			
			if ( a + b + c == target ){
				return true;
			}
			
			else if ( a + b + c > target )
				end--;
			
			else
				start++;	
		}
	}
	
	return false;
}

int threeSumClosest(vector<int> &num, int target){
	
	if ( num.size() < 3 )
		return INT_MAX;
	
	sort(num.begin(), num.end());
	
	if ( threeSum(num, target) )
		return target;
	
	int larger = target + 1;
	int smaller= target - 1;
	while(1){
		
		if ( threeSum(num, larger) )
			return larger;
		
		if ( threeSum(num, smaller) )
			return smaller;
		
		larger++;
		smaller--;
	}
}

int main(){
	int a[] = { -1, 2, 1, -4};
	vector<int> num;
	for (int i = 0; i < 4; i++)
		num.push_back(a[i]);
	cout << threeSumClosest(num, 1);
	return 0;
}
