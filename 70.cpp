#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int climbRecur(vector<int> &steps, int n){
       if ( steps[n-1] != -1 )
           return steps[n-1];
       
       else{
           steps[n-1] = climbRecur(steps, n-1) + climbRecur(steps, n-2);
           return steps[n-1];
       }
   }
   
   int climbStairs(int n) {
       vector<int> steps(n, -1);
       steps[0] = 1;
       steps[1] = 2;
       return climbRecur(steps, n);
   }
int main(){
	cout << climbStairs(44) << endl;
	//cout << sqrt1(0);
}
