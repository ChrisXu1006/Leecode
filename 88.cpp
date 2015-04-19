#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <stack> 
#include <ctype.h>

using namespace std;

map<string, int> table;

void merge(int A[], int m, int B[], int n) {
        int cur1 = m-1;
        int cur2 = n-1;
        
        for ( int i = m+n-1; i >= 0; i-- ){
            if ( cur1 == -1 || (B[cur2] >= A[cur1] && cur2 != -1) ){
                A[i] = B[cur2];
                cur2--;
            }
            else{
				cout << cur1 << endl;
                A[i] = A[cur1];
                cur1--;
            }
        }
        return;
}

int main(){
	int A[] = {-1,0,0,3,3,3,0,0,0};
	int B[] = {1,2,3};
	merge(A, 6, B, 3);
	for ( int i = 0 ; i < 9; i++ )
		cout << A[i] << " ";
	
	return 0;
}
