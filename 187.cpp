#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;

string translate(int key){
	string s = "";
	for ( int i = 0; i < 10; i++ ){
		int tmp = key & 3;
		if ( tmp == 0 )
			s = 'A' + s;
		else if ( tmp == 1)
			s = 'C' + s;
		else if ( tmp == 2)
			s = 'G' + s;
		else
			s = 'T' + s;
		key = key >> 2;
	}
	return s;
}

vector<string> findRepeatedDnaSequences(string s){
	int len = s.length();
	vector<string> seq;
	if ( len < 10 )
		return seq;
	
	map<int, int> table;
	for(int i = 0; i < len - 9; i++){
		int key = 0;
		for ( int k = 0; k < 10; k++ ){
			if ( s[i+k] == 'A' )
				key = key | 0;
			
			else if ( s[i+k] == 'C' )
				key = key | 1;
			
			else if ( s[i+k] == 'G' )
				key = key | 2;
			
			else
				key = key | 3;
			
			key = key << 2;
		}
		key = key >> 2;
		if ( table.find(key) != table.end() )
			table[key]++;
		else
			table[key] = 1;
	}
	
	for ( map<int, int>::iterator it = table.begin(); it != table.end(); it++ ){
		if ( it->second != 1 ){
			seq.push_back(translate(it->first));
		}
	}
	return seq;
}

int main(){
	string s = "GAGAGAGAGAGA";
	vector<string> seq = findRepeatedDnaSequences(s);
	for ( int i = 0; i < seq.size(); i++ )
		cout << seq[i] << endl;
	return 0;
}
