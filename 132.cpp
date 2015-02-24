#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int minCut(string s){
 int len = s.size();  
            int D[len+1];  
            bool P[len][len];  
            //the worst case is cutting by each char  
            for(int i = 0; i <= len; i++)   
            D[i] = len-i;  
            for(int i = 0; i < len; i++)  
            for(int j = 0; j < len; j++)  
            P[i][j] = false;  
            for(int i = len-1; i >= 0; i--){  
                 for(int j = i; j < len; j++){  
                      if(s[i] == s[j] && (j-i<2 || P[i+1][j-1])){  
                           P[i][j] = true;  
                           D[i] = min(D[i],D[j+1]+1);  
                      }  
                 }  
            }  
            return D[0]-1;
}

int main(){
	string s = "aab";
	cout << minCut(s);
}
