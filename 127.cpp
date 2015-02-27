#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>

using namespace std;

int ladderrecur(string start, string end, unordered_set<string> &visited, unordered_set<string> &dict, int step){
	if ( start == end )
		return step+1;
}

int ladderLength(string start, string end, unordered_set<string> &dict){
	unorder_set<string> visited;
	return ladderrecur(start, end, visited, dict, 0);
}

int main(){
	string start = "hit";
	string end = "hit";
	unordered_set<string> dict;
	string array[] = { "hot", "dot", "dog", "lot", "log"};
	for ( int i = 0; i < 5; i++ )
		dict.insert(array[i]);
	cout << ladderLength(start, end, dict);
}
