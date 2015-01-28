#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

int numTrees(int n){
	
	if ( n <= 0 )
		return 0;
	
	if ( n == 1 )
		return 1;
	
	int result = 0;
	int left, right;
	for ( int i = 1; i <= n; i++ ){
		left = numTrees(i-1);
		right = numTrees(n-i);
		if ( left == 0 )
			result += right;
		else if ( right == 0 )
			result += left;
		else
			result += left*right;
	}
	return result;
}

int main(){
	cout << numTrees(4);
	return 0;
}
