#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void threeSum(vector<int> &num, vector<vector<int> > &combs, int start, int end, int target, int cur){
       
       for ( int i = start; i < end - 1; i++ ){
           if ( i > start && num[i] == num[i-1] )
               continue;
           int left = i + 1;
           int right = end;
           while (left < right){
               int temp = num[left] + num[right] + num[i];
               if ( temp < target ){
                   left++;
                   while (num[left] == num[left-1] && left < right )
                       left++;
               }
               else if ( temp > target ){
                   right--;
                   while (num[right] == num[right+1] && left < right)
                       right--;
               }
               else{
                   vector<int> comb;
                   comb.push_back(cur);
                   comb.push_back(num[i]);
                   comb.push_back(num[left]);
                   comb.push_back(num[right]);
                   combs.push_back(comb);
                   left++;
                    while (num[left] == num[left-1] && left < right )
                       left++;
               }
           }
       }
       return;
   }
   
   vector<vector<int> > fourSum(vector<int> &num, int target) {
       
       sort(num.begin(), num.end());
   
       vector<vector<int> > combs;
       int size = num.size();
       
       for ( int i = 0; i < size - 3; i++ ){
           if ( i > 0 && num[i] == num[i-1] )
               continue;
           
           threeSum(num, combs, i+1, size-1, target-num[i], num[i]);
       }
       return combs;
   }

int main(){
	int a[] = {-2, 0, 1, 1, 1};
	vector<int> num;
	for (int i = 0; i < 5; i++)
		num.push_back(a[i]);
	vector<vector<int> >  res = threeSum(num);
	for ( int i = 0; i < res.size(); i++ ){
		for ( int j = 0; j < 3; j++ )
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}
