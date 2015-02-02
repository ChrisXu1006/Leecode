#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

string simplifyPath(string path){
	
	string s = "";
	
	int dot = 0;
	int back = 0;
	int charac = 0;
	int valid = 1;
	int len = path.length();
	
	for ( int i = len - 1; i >= 0; i-- ){
		
		if ( path[i] == '/' ){
			if ( valid ){
				if ( charac > 0 && dot > 0){
					if ( back > 0 )
						back--;
					else
						s = path.substr(i, charac+dot+1) + s;
					charac = 0;
					dot = 0;
				}
				
				else if ( charac > 0 ){
					if ( back > 0 )
						back--;
					else
						s = path.substr(i, charac+1) + s;
					charac = 0;
				}
				
				else if ( dot == 1 )
					dot = 0;
				
				else if ( dot == 2 ){
					back++;
					dot = 0;
				}
				
				else if ( dot > 2 ){
					s = path.substr(i, dot+1) + s;
					dot = 0;
				}
				
			}
			else
				continue;
		}
		
		else if ( path[i] == '.'){
			dot++;
			if ( !valid )
				valid = 1;
		}
		
		else{
			charac++;
			if ( !valid )
				valid = 1;
		}
	}
	
	int lens = s.length();
	if ( s[lens-1] == '/' && lens > 1)
		return s.substr(0,lens-1);
	else if ( lens == 0 )
		return "/";
	else
		return s;
}

int main(){
	string path = "/home/foo/.ssh/../.ssh2/authorized_keys/";
	string simplify = simplifyPath(path);
	cout << simplify;
	return 0;
}
