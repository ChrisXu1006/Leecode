#include <iostream>
#include <vector>

using namespace std;

struct info{
	int profit;
	int min;
};

	
int maxProfit(vector<int> &prices){
	if (prices.size() <= 1)
		return 0;
	
	info cur_info;
	cur_info.profit = prices[1] - prices[0];
	if ( cur_info.profit >= 0 )
		cur_info.min = prices[0];
	else
		cur_info.min = prices[1];
	
	for (int i = 2; i < prices.size(); i++ ){
		if ( prices[i] - cur_info.min > cur_info.profit )
			cur_info.profit = prices[i] - cur_info.min;
		
		if ( prices[i] < cur_info.min )
			cur_info.min = prices[i];
	}
	
	if ( cur_info.profit < 0)
		return 0;
	else
		return cur_info.profit;
}

int main(){
	int a[] = {6, 1, 3, 2, 4, 7};
	vector<int> res;
	for (int i = 0; i < 6; i++)
		res.push_back(a[i]);
	cout << maxProfit(res);
	return 0;
}