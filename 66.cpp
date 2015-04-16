#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
       int size = digits.size();
       if ( size == 0 ){
           digits.push_back(1);
           return digits;
       }
       
       int carry = 1;
       for ( int i = size-1; i >= 0; i-- ){
           int tmp = digits[i] + carry;
           if(tmp == 10){
               digits[i] = 0;
               carry = 1;
           }
           else{
               digits[i] = tmp;
               return digits;
           }
       }
       digits.insert(digits.begin(),1);
       return digits;
   }

int main(){

}
