#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

vector<vector<int> > threeSum(vector<int> &num){
	
	vector<vector<int> > res;
	
	if ( num.size() < 3)
		return res;
	
	sort(num.begin(), num.end());
	vector<int> buf;
	
	for ( int i = 0; i < num.size() - 2; i++ ){
		
		if ( i > 0 && num[i] == num[i-1])
			continue;
			
		int a = num[i];
		int start = i+1;
		int end = num.size() - 1;
		
		while ( start < end ){
			
			int b = num[start];
			int c = num[end];
			
			if ( start - 1 > i && num[start] == num[start-1] ){
				start++;
				continue;
			}
			
			if ( end + 1 < num.size() && num[end] == num[end+1] ){
				end--;
				continue;
			}
			
			if ( a + b + c == 0 ){
				buf.push_back(a);
				buf.push_back(b);
				buf.push_back(c);
				res.push_back(buf);
				buf.clear();
				start++;
				end--;
			}
			
			else if ( a + b + c > 0 )
				end--;
			
			else
				start++;	
		}
	}
	
	return res;
}

int main(){
	int a[] = {1, 2, -2, -1};
	vector<int> num;
	for (int i = 0; i < 4; i++)
		num.push_back(a[i]);
	vector<vector<int> >  res = threeSum(num);
	for ( int i = 0; i < res.size(); i++ ){
		for ( int j = 0; j < 3; j++ )
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}
