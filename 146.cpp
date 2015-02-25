#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

void breakrecur(vector<string> &sols, vector<string> &buffer, vector<bool> &possible, int start, unordered_set<string> &dict, string s){
	if ( start == s.length() ){
		string comb = "";
		for ( int i = 0; i < buffer.size(); i++ )
			comb = comb + buffer[i] + ' ';
		sols.push_back(comb.substr(0, comb.size()-1));
		return;
	}
	
	for ( int i = start; i < s.length(); i++ ){
		string temp = s.substr(start, i-start+1);
		if (possible[i+1] == 1 && (dict.find(temp) != dict.end()) ){
			buffer.push_back(temp);
			breakrecur(sols, buffer, possible, i+1, dict, s);
			buffer.pop_back();
		}
	}
}

    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        string s2 = '#' + s;
	int len = s2.size();
	vector<bool> possible(len, 0);
	
	possible[0] = true;
	for ( int i = 0; i < len; i++ ){
		for ( int j = 0; j < i; j++ ){
			possible[i] = possible[j] && dict.find(s2.substr(j+1,i-j)) != dict.end();
			if (possible[i]) break;
		}
	}
	
	vector<string> sols;
	vector<string> buffer;
	if ( possible[len-1] )
	    breakrecur(sols, buffer, possible, 0, dict, s);
	return sols;

    }

int main(){
		string s = "catsanddog";
	    string A[] = {"cat", "cats", "and", "sand", "dog"};
	    unordered_set<string> dict;
	    for ( int i = 0; i < 5; i++ )
	        dict.insert(A[i]);
	    vector<string> sols = wordBreak(s, dict);
	    for ( int i = 0; i < sols.size(); i++ )
	        cout << sols[i] << endl;
	    return 0;
	}

