#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int maxProduct(int A[], int n){
	
	int result = A[0];
	
	int cur_max = A[0];
	int cur_min = A[0];
	
	for ( int i = 1; i < n; i++ ){
		
		cout << cur_max << " " << cur_min << endl;
		
		int maxtmp = cur_max;
		int mintmp = cur_min;
		
		cur_max = max(max(maxtmp*A[i], mintmp*A[i]),A[i]);
		cur_min = min(min(maxtmp*A[i], mintmp*A[i]),A[i]);
			
		result = max(cur_max, result);
		
	}
	
	return result;
    /*int res = A[0];
           int maxp = A[0];
           int minp = A[0];
           for (int i=1;i<n;i++){
               int tmpmax = maxp;
               int tmpmin = minp;
               maxp = max(max(tmpmax*A[i],tmpmin*A[i]),A[i]);
               minp = min(min(tmpmax*A[i],tmpmin*A[i]),A[i]);
               res = max(maxp,res);
           }
           return res;*/
}

int main(){
	int a[] = {-1, -3, -9, 0, 4};
	cout << maxProduct(a, 5);
	return 0;
}
