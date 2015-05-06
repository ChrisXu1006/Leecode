#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

unordered_map<int, bool> table; 
   
int countPrimes(int n) {
       if (n<=2) return 0;
        vector<bool> passed(n, false);
        int sum = 1;
        int upper = sqrt(n);
        for (int i=3; i<n; i+=2) {
            if (!passed[i]) {
                sum++;
                //avoid overflow
                if (i>upper) continue;
                for (int j=i*i; j<n; j+=i) {
                    passed[j] = true;
                }
            }
        }
        return sum;
    }
	
int main(){
	return 0;
}