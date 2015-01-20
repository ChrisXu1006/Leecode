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

void sortstr(vector<string> &strnum, vector<int> &num){
    if ( strnum.empty() ){
        strnum.push_back(to_string(num.back()));
        num.pop_back();
    }
    
    for (int j = num.size() - 1; j >= 0; j--){
        int i = strnum.size() - 1;
        for ( ;i >= 0; i-- ){
            if ( compare(strnum[i],to_string(num[j])) ){
                if ( i == strnum.size() - 1 )
                    strnum.push_back(to_string(num[j]));
                else
                    strnum.insert(strnum.begin()+i+1, to_string(num[j]));
                break;
            }
        }
        if ( i == -1 ){
            //if ( num.back() != 0 || strnum[0] != "0")
                strnum.insert(strnum.begin(),to_string(num[j]));
        }
    }
    return;
}

string largestNumber(vector<int> &num){
    vector<string> strnum;
    sortstr(strnum, num);
    string res = "";
    for ( int i = 0; i < strnum.size(); i++ )
        res = res + strnum[i];
    if ( res.length() > 1 && res[0] == '0' )
        res = "0";
    return res;
}

int main(int argc, const char * argv[])
{

    // insert code here...
    int a[] = {34, 45, 9, 23};
	vector<int> num;
	for (int i = 0; i < 4; i++ )
		num.push_back(a[i]);
    cout << largestNumber(num) << endl;
    return 0;
}

