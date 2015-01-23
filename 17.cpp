#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void dfs(vector<string> &str, string save, string dig, int now, int size, int *convert){
	if (now == size){
    	str.push_back(save);
    	return;
	}
	
	int tmp = dig[now] - '0' - 2;//change '2' to 0, '3' to 1...
	for(int i = convert[tmp]; i < convert[tmp+1]; i++){
    	save.push_back('a' + i);//ex: a,b,c | d,e,f
   	 	dfs(str, save, dig, now + 1, size, convert);
    	save.pop_back();
	}
}

vector<string> letterCombinations(string digits) {
	vector<string> str;//str for final resut
    string save;//save for temporary answer
    int convert[10] = {0, 3, 6, 9, 12, 15, 19, 22, 26};
    dfs(str, save, digits, 0, digits.size(), convert);
    return str;
}

int main(){
	string digits = "";
	vector<string> res = letterCombinations(digits);
	for ( int i = 0; i < res.size(); i++ )
		cout << res[i] << ",";
	return 0;
}
