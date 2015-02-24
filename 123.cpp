#include <iostream>
#include <vector>

using namespace std;
	
int maxProfit(vector<int> &prices){
	int profit = 0, n = prices.size();
	if ( n == 0 )
		return 0;
	
	int left[n], right[n];
	memset(left, 0, sizeof(left) );
	memset(right,0, sizeof(right));
	int min = prices[0];
	
	for ( int i = 1; i < n; i++ ){
		left[i] = prices[i] - min > left[i-1] ? prices[i] - min : left[i-1];
		min = prices[i] < min ? prices[i] : min;
	}
	
	int max = prices[n-1];
	for ( int i = n - 2; i >= 0; i-- ){
		right[i] = max - prices[i] > right[i+1] ? max - prices[i] : right[i+1];
		max = prices[i] > max ? prices[i] : max;
	}
	for ( int i = 0; i < n; i++ )
		profit = left[i] + right[i] > profit ? left[i] + right[i] : profit;
	
	return profit;
}

int main(){
	int a[] = {6, 7, 1, 3, 5};
	vector<int> res;
	for (int i = 0; i < 5; i++)
		res.push_back(a[i]);
	cout << maxProfit(res);
	return 0;
}