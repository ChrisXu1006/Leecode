#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;
int gcd ( int a, int b )
{
  int c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}
void rotate1(int nums[], int n, int k){
	int dup[n];
	for ( int i = 0; i < n; i++ )
		dup[(i+k)%n] = nums[i];
	for ( int i = 0; i < n; i++ )
		nums[i] = dup[i];
	return;
}

void rotate2(int nums[], int n, int k){
	for ( int i = 0; i < k; i++ ){
		int tmp = nums[n-1];
		for ( int j = n-1 ; j >= 1; j-- )
			nums[j] = nums[j-1];
		nums[0] = tmp;
	}
	return;
}

void rotate3(int nums[], int n, int k){
       int gcd_nk; // greatest common devisor of n and k
       int i,j;
       int temp;

       k = k % n;
       gcd_nk = gcd(k,n);

       for(i=0;i<gcd_nk;i++)
       {
           j=i;
           temp = nums[i];
           do{
               nums[i] = nums[(j+k) % n];
               nums[(j+k) % n] = temp;
               temp = nums[i];
               j = (j+k) % n;
           }while(j!=i);
       }
   }

void rotate4(int nums[], int n, int k) {
       reverse(nums,nums+n);
       reverse(nums,nums+k%n);
       reverse(nums+k%n,nums+n);
}
int main(){
	int nums[] = {1, 2, 3, 4, 5, 6, 7};
	//cout << gcd(3, 2) << endl;
	rotate3(nums, 7, 3);
	for ( int i = 0; i < 7; i++ )
		cout << nums[i] << " ";
	return 0;
}
