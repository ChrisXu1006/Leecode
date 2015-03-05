#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

string intToRoman(int num){
	
	string s = "";
	int a[7];
	memset(a, 0, sizeof(a));
	
	a[6] = num / 1000;
	for ( int i = 0; i < a[6]; i++)
		s = s + 'M';
	num = num % 1000;
	
	if ( num / 900 ){
		s = s + "CM";
		num = num % 900;
	}
	
	a[5] = num / 500;
	for ( int i = 0; i < a[5]; i++)
		s = s + 'D';
	num = num % 500;
	
	if ( num / 400 ){
		s = s + "CD";
		num = num % 400;
	}
	
	a[4] = num / 100;
		for ( int i = 0; i < a[4]; i++ )
			s = s + 'C';
	num = num % 100;
	
	if ( num / 90 ){
		s = s + "XC";
		num = num % 90;
	}
	
	a[3] = num / 50;
	for ( int i = 0; i < a[3]; i++)
		s = s + 'L';
	num = num % 50;
	
	if ( num / 40 ){
		s = s + "XL";
		num = num % 40;
	}
	
	a[2] = num / 10;
	for ( int i = 0; i < a[2]; i++ )
		s = s + 'X';
	num = num % 10;
	
	if ( num / 9 ){
		s = s + "IX";
		num = num % 9;
	}
	
	a[1] = num / 5;
	for ( int i = 0; i < a[1]; i++)
		s = s + 'V';
	num = num % 5;
	
	if ( num / 4 ){
		s = s + "IV";
		num = num % 4;
	}
	
	a[0] = num / 1;
	for ( int i = 0; i < a[0]; i++ )
			s = s + 'I';
	
	return s;
	
}

string intToRoman2(int num) {
       int A[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
       string B[13] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
       string s = "";
       for ( int i = 12; i >= 0; i-- ){
           int count = num/A[i];
           int tmp = count;
           while (tmp){
               s = s + B[i];
               tmp--;
           }
           num = num - A[i] * count;
       }
       return s;
   }
   
int main(){
	cout << intToRoman(1800);
}
