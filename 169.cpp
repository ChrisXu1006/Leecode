#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;

int majorityElement(vector<int>& nums) {
        int size = nums.size();
        int thre = ceil(size/2);
        unordered_map<int, int> table;
        
        for ( int i = 0; i < size; i++ ){
            if ( table.find(nums[i]) == table.end() )
                table[nums[i]] = 1;
            else
                table[nums[i]]++;
            
            if ( table[nums[i]] > thre )
                return nums[i];
        }
    }
};

int main(){
	int a[] = { 1, 1, 2};
	vector<int> nums;
	for ( int i = 0; i < 3; i++ )
		nums.push_back(a[i]);
	cout << majorityElement(nums) << endl;
	return 0;
}
