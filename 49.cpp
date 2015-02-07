#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> anagrams(vector<string> &strs){
	map<string, int> mp;
	map<string, string> pre;
	
	vector<string> res;
	for ( int i = 0; i < strs.size(); i++ ){
		string s = strs[i];
		sort(s.begin(), s.end());
		if ( mp.find(s) == mp.end() ){
			mp[s] = 1;
			pre[s] = strs[i];
		}
		else
		{
			mp[s]++;
			if (mp[s] == 2)
				res.push_back(pre[s]);
			res.push_back(strs[i]);
		}
	}
	return res;
}

int main(){
	string s = "teen";
	vector<string> strs;
	strs.push_back("abc");
	strs.push_back("cab");
	vector<string> res = anagrams(strs);
	for ( int i = 0; i < res.size(); i++ )
		cout << res[i] << endl;
	return 0;
}
