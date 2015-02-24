#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;

int longestConsecutive(vector<int> &num) {
	unordered_map<int,bool> map;
	for ( int i = 0; i < num.size(); i++ )
		map[num[i]] = true;
	
	int res = 0;
	for ( int i = 0; i < num.size(); i++ ){
		int max = 1;
		int fd = num[i];
		
		map.erase(num[i]);
		while (map.find(fd+1) != map.end()){
			max++;
			map.erase(fd+1);
			fd++;
		}
		
		fd = num[i];
		while (map.find(fd-1)!= map.end()){
			max++;
			map.erase(fd-1);
			fd--;
		}
		
		if ( max >res )
			res = max;
	}
	return res;
}
   
int main(){
	int A[] = {100, 4, 200, 1, 3, 2};
	vector<int> num;
	for ( int i = 0; i < 6; i++ )
		num.push_back(A[i]);
	cout << longestConsecutive(num);
}