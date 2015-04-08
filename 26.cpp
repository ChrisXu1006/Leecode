#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int removeDuplicates(int A[], int n) {
	if(n <= 0)
    	return 0;
       
    int realindex = 1;
    for ( int i = 1; i < n; i++ ){
       if(A[i] != A[i-1]){
           A[realindex] = A[i];
           realindex++;
       }
   }    
   return realindex;
}