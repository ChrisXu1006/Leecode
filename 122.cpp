#include <iostream>
#include <vector>

using namespace std;
	
int maxProfit(vector<int> &prices){
	if ( prices.size() <= 1 )
		return 0;
	
	int buy = 1;
	//int sell = 0;
	int pre = 0;
	int profit = 0 - prices[0];
	
	for ( int i = 1; i < prices.size(); i++ ){
		if ( buy == 1 ){
			if ( prices[i] > prices[pre] ){
				profit = profit + prices[i];
				pre = i;
				buy = 0;
			}
			else {
				profit = profit + prices[pre] - prices[i];
				pre = i;
				buy = 1;
			}
		}
		
		else{
			if ( prices[i] > prices[pre] ){
				profit = profit - prices[pre] + prices[i];
				pre = i;
				buy = 0;
			}
			else{
				profit = profit - prices[i];
				pre = i;
				buy = 1;
			}
		}
		
	}
	
	if ( buy == 1 )
		profit = profit + prices[pre];
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