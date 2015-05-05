#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int rob(vector<int>& nums) {
        int size = nums.size();
        vector<int> money(size, 0);
        if ( size == 0 )
            return 0;
        money[0] = nums[0];
        if ( size == 1 )
            return nums[0];
        money[1] = max(nums[0], nums[1]);
        
        for ( int i = 2; i < size; i++ )
            money[i] = max(money[i-1], money[i-2] + nums[i]);
        
        return money[size-1];
    }

int main(){
	int a[] = {1, 2, 3, 4};
	vector<int> nums;
	for ( int i = 0; i < 4; i++ )
		nums.push_back(a[i]);
	cout << rob(nums) << endl;
	return 0;
}