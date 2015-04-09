#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int strStr(char *haystack, char *needle) {
        
        if ( haystack == NULL || needle == NULL )
            return -1;
        
        if ( *haystack == '\0'){
            if ( *needle == '\0')
                return 0;
            else
                return -1;
        }
        
        int loc = 0;
        while ( *haystack != '\0' ){
            char* cur1 = haystack;
            char* cur2 = needle;
            while ( *cur1 == *cur2 && *cur1 != '\0' && *cur2 != '\0' ){
                cur1++;
                cur2++;
            }
            
            if ( *cur2 == '\0' )
                return loc;
            if ( *cur1 == '\0' )
                return -1;
            
            loc++;
            haystack++;
        }
        return -1;
    }