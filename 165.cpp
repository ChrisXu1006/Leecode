#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;

int compareVersion(string version1, string version2) {
	vector<int> buf1;
    vector<int> buf2;
        
    string digits = "";
   	for ( int i = 0; i < version1.length(); i++ ){
    	if ( version1[i] != '.' )
        	digits += version1[i];
        else{
            buf1.push_back(stoi(digits));
            digits = "";
        }
    }
    if ( digits != "" )
        buf1.push_back(stoi(digits));
        
    digits = "";
    for ( int i = 0; i < version2.length(); i++ ){
        if ( version2[i] != '.' )
            digits += version2[i];
        else{
            buf2.push_back(stoi(digits));
            digits = "";
        }
    }
    if ( digits != "" )
        buf2.push_back(stoi(digits));
        
    int cur = 0;
    while ( cur < buf1.size() && cur < buf2.size() ){
        if ( buf1[cur] > buf2[cur] )
            return 1;
        else if ( buf1[cur] < buf2[cur] )
            return -1;
        else
            cur++;
    }
        
    if ( cur < buf1.size() ){
        while ( cur < buf1.size() ){
            if ( buf1[cur] == 0 )
                cur++;
            else
                return 1;
        }
    }
    if ( cur < buf2.size() ){
        while ( cur < buf2.size() ){
            if ( buf2[cur] == 0 )
                cur++;
            else
                return -1;
        }
    }
    return 0;
}

int main(){
	string v1 = "2.1";
	string v2 = "1.2";
	cout << compareVersions(v1, v2) << endl;
	return 0;
}
