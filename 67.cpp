#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

string addBinary(string a, string b) {
        int lena = a.length();
        int lenb = b.length();
        if ( lena < lenb )
            return addBinary(b, a);
        
        if ( lenb == 0 )
            return a;
        string s = "";
        lena--;
        lenb--;
        int carry = 0;
        while (lenb >= 0){
            int tmp = carry + b[lenb] - '0' + a[lena] -'0';
            if ( tmp > 1 ){
                s = (char)(tmp - 2 + '0') + s;
                carry = 1;
            }
            else{
                s = (char)(tmp + '0') + s;
                carry = 0;
            }
            lenb--;
            lena--;
        }
        
        while (lena >= 0){
             int tmp = carry + a[lena] -'0';
            if ( tmp > 1 ){
                s = (char)(tmp - 2 + '0') + s;
                carry = 1;
            }
            else{
                s = (char)(tmp + '0') + s;
                carry = 0;
            }
            lena--; 
        }
        
        if ( carry == 1 )
            s = '1' + s;
        return s;
    }

int main(){

}
