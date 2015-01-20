//
//  main.cpp
//  test
//
//  Created by 国境之南Rui on 15-1-19.
//  Copyright (c) 2015年 国境之南Rui. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <climits>
#include <ctype.h>

using namespace std;

bool compare(string a, string b){
    if ( a + b > b + a )
        return 1;
    else
        return 0;
}

string largestNumber(vector<int> &num) {
    vector<string> strnum;
    for ( int i = 0; i < num.size(); i++ )
        strnum.push_back(to_string(num[i]));
    
    sort(strnum.begin(), strnum.end(), compare);
    
    string ret;
    
    for ( int i = 0; i < strnum.size(); i++ )
        ret = ret + strnum[i];
    
    /* That's in case some cheeky person decides to give us zeroes only. */
    if ((ret[0] == '0') && (ret[ret.length() - 1] == '0')) {
        return "0";
    }
    
    return ret;
}

int main(int argc, const char * argv[])
{

    // insert code here...
    int a[] = {5, 23, 45, 9, 8};
	vector<int> num;
	for (int i = 0; i < 5; i++ )
		num.push_back(a[i]);
    cout << largestNumber(num) << endl;
    return 0;
}


