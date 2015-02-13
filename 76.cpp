#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <ctype.h>

using namespace std;

string minWindow(string S, string T){

	map<char, int> Ttable;
	map<char, int> Stable;
	
	int Tlen = T.length();
	int Slen = S.length();
	
	for ( int i = 0; i < Tlen; i++ ){
		if ( Ttable.find(T[i]) == Ttable.end() ){
			Ttable[T[i]] = 1;
			Stable[T[i]] = 0;
		}
		else
			Ttable[T[i]]++;
	}
	
	int begin = 0;
	int end = 0;
	int counter = 0;
	int start = -1;
	int epi = -1;
	
	while ( begin != Slen ){
		
		cout << begin << end << counter << endl;
		if ( counter < Tlen && end < Slen ){

			if ( Stable.find(S[end]) != Stable.end() ){
				if ( Stable[S[end]] < Ttable[S[end]] )
					counter++;
				Stable[S[end]]++;
			}
				end++;
		}
		
		else{
			
			if ( counter == Tlen ){
				if ( start == - 1 ){
					epi = end-1;
					start = begin;
				}
			
				else if ( end - begin - 1 < epi - start ){
					epi = end-1;
					start = begin;
				}
			}
			
			if ( Stable.find(S[begin]) != Stable.end() ){
				if ( Stable[S[begin]] == Ttable[S[begin]] )
					counter--;
				Stable[S[begin]]--;
			}
			begin++;
		}
		
	}
	
	if ( start == -1 )
		return "";
	else
		return S.substr(start, epi - start+1);
}	

int main(){
	string S = "ab";
	string T = "a";
	cout << minWindow(S, T);
}
