#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;

int helper(vector<int> &prices){
	int profit = 0;
	for ( int i = 0; i < prices.size() - 1; i++ )
		profit = max(profit, profit + prices[i+1] - prices[i]);
	return profit;
}

int maxProfit(int k, vector<int> &prices){
	int size = prices.size();
	if ( size == 0 )
		return 0;
	if ( k >= size )
		return helper(prices);
	
	vector<int> local(k+1, 0);
	vector<int> global(k+1, 0);
	for ( int i = 0; i < size - 1; i++ ){
		int diff = prices[i+1] - prices[i];
		for ( int j = k; j >= 1; j-- ){
			local[j] = max(global[j-1]+(diff>0?diff:0), local[j]+diff);
			global[j] = max(local[j], global[j]);
		}
	}
	return global[k];
}

int main(){
	
	return 0;
}
