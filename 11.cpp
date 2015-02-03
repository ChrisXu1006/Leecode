#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int maxArea(vector<int> &height){
	
	if ( height.size() == 1 )
		return -1;
	
	int left = 0;
	int right = height.size() - 1;
	int area = 0;
	
	while ( left < right ){
		int tmp = min(height[left], height[right])*(right-left);
		if ( tmp > area )
			area = tmp;
		
		if ( height[left] < height[right] )
			left++;
		else
			right--;
	}
	return area;

}

int main(){
	int a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	vector<int> height;
	for ( int i = 0; i < 10; i++ )
		height.push_back(a[i]);
	cout << maxArea(height);
}
