#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

long long int buf[10];

string mpl(string num, char n){  //compute num*n
       string res="";
       int carry=0;    
       if (n=='0'){return "0";}
       for (int i=num.size()-1;i>=0;i--){
           int m=(num[i]-'0')*(n-'0')+carry;
           carry = m/10;
           m=m%10;
           res = char(m+'0')+res;
       }
       if (carry!=0){res = char(carry+'0')+res;}
       return res;
   }

   void add(string &res, string m,int idx){
       if (res==""){ res = m;}
       else{
           m = m+string(idx,'0'); // this is important (you can also change value i instead)
           int carry=0;
           int i=res.size()-1;
           int j=m.size()-1;
           while (i>=0){
               int k =(res[i]-'0')+(m[j]-'0')+carry;
               carry=k/10;
               k=k%10;
               res[i]=char(k+'0');
               i--; j--;
           }
           while (j>=0){ // deal with the rest of string
               if (carry>0){
                   int kk = (m[j]-'0')+carry;
                   carry = kk/10;
                   kk=kk%10;
                   res= char(kk+'0')+res;
               }else{
                   res = m[j]+res;
               }
               j--;
           }
            
           if (carry>0){ // be careful with highest digit
               res = char(carry+'0')+res;
           }
       }
   }

   string multiply(string num1, string num2) {
       // Start typing your C/C++ solution below
       // DO NOT write int main() function                
       if (num1.size()==0 || num2.size()==0){return "";}
       //handle negative case
       bool pos=true; 
       if (num1[0]=='-'){num1=num1.substr(1);pos = !pos;}
       if (num2[0]=='-'){num2=num2.substr(1);pos = !pos;}

       //main part
       string res="0";        
       for (int i=num2.size()-1;i>=0;i--){ //for each element in num2        
           string m=mpl(num1,num2[i]); // num1 multiply by num2[i]           
           if (m!="0"){
               add(res,m,num2.size()-1-i); // add m to the result
           }
       }
                
       if (!pos){res="-"+res;}
       return res;
   }			else{
				result = (char)(carry + digit + '0') + result;
				carry = 0;
			}
		}
		
		else{
			if ( carry + digit + (result[len - cur] - '0') >= 10 ){
				result[len - cur] = carry + digit + (result[len-cur]) - 10;
				carry = 1;
			}
			else{
				result[len - cur] = carry + digit + (result[len - cur]);
				carry = 0;
			}
		}
		tmp = tmp/10;
		cur++;
	}
	if ( carry == 1 )
		result = '1' + result;
	mul(num, num2, bit+1, result);
	return;
}

long long int trans(string num1){
    long long int result = 0;
    for ( int i = 0; i < num1.length(); i++ )
        result = result*10 + (num1[i] - '0');
    return result;
}

string multiply(string num1, string num2){
	
	memset(buf, -1, sizeof(buf));
	string result = "";
	
	if ( num1.length() >= num2.length() ){
		long long int num = trans(num1);
		if ( num == 0 )
			return "0";
		mul(num, num2, 0, result);
	}
	else{
		long long int num = trans(num2);
		if ( num == 0 )
			return "0";
		mul(num, num1, 0, result);
	}
	return result;
	
}

int main(){
	string num1 = "123456789";
	string num2 = "987654321";
	cout << multiply(num1, num2) << endl;
}
