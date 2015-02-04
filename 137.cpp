#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int singleNumber(int A[], int n){
	
    int t1 = 0;
          int t2 = 0;
          int t3 = 0;
         
          for (int i = 0; i < n; i++){
              t1 = t1 ^ A[i];
              t2 = t2 | ((t1^A[i]) & A[i]);
              t3 = ~(t1 & t2);
              t1 = t1 & t3;
              t2 = t2 & t3;
          }
         
          return t1;
}

int main(){
	int A[] = { 5, 5, 2, 2, 2, 5, 1};
	cout << singleNumber(A, 7);
}
