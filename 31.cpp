#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void nextPermutation(vector<int> &num){
	
	int size = num.size();
	
	if ( size == 1 )
		return;
	
	int pre = size - 2;
	int cur = size - 1;
	
	while ( num[pre] >= num[cur] ){
		pre--;
		cur--;
		if ( pre == -1 )
			break;
	}
	
	if ( pre == -1 ){
		sort(num.begin(), num.end());
	} 
	else{
		cur = size - 1;
		while ( num[pre] >= num[cur] )
			cur--;
		int tmp = num[cur];
		num[cur]= num[pre];
		num[pre] = tmp;
		sort(num.begin()+pre+1, num.end());
	}
	return;
}

int main(){
	int a[] = {2, 3, 1};
	vector<int> num;
	for ( int i = 0; i < 3; i++ )
		num.push_back(a[i]);
	nextPermutation(num);
	for ( int i = 0; i < num.size(); i++ )
		cout << num[i] << " ";
}
