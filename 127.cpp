#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>

using namespace std;

int ladderLength(string start, string end, unordered_set<string> &dict){
	map<string, int> distance;
		queue<string> S;
		S.push(start);
		distance[start] = 1;
		int size = S.size();
		int found = 0;
    
	    if ( start == end )
	        return 1;
	
		while (size){
			for ( int i = 0; i < size; i++ ){
				int len = S.front().length();
				for ( int j = 0; j < len; j++ ){
					for ( char c = 'a'; c <= 'z'; c++ ){
						if ( c == S.front()[j] )
							continue;
						string ns = S.front();
						ns[j] = c;
	                    if ( ns == end ){
	                        distance[end] = distance[S.front()]+1;
	                        found = 1;
	                        break;
	                    }
						if ( dict.find(ns) != dict.end() ){
							S.push(ns);
							dict.erase(ns);
							distance[ns] = distance[S.front()]+1;
						}
						else
							continue;
					}
	                if (found)
	                    break;
				}
	            if(found)
	                break;
				S.pop();
			}
			size = S.size();
			if ( found == 1 )
				break;
		}
		return distance[end];
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
