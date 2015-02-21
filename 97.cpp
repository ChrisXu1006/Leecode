#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <ctype.h>

using namespace std;

bool isInterleave(string s1, string s2, string s3){
	
    int n1 = s1.size();
           int n2 = s2.size();
           vector<vector<bool> > A(n1+1,vector<bool>(n2+1,false));
           if (n1+n2!=s3.size()){return false;}
           if (s1.empty()&&s2.empty()&&s3.empty()){return true;}
          
           A[0][0]=true;    
           for (int i=1;i<=n1;i++){
               if (s1[i-1]==s3[i-1] && A[i-1][0]){A[i][0]=true;}
           }
           for (int i=1;i<=n2;i++){
               if (s2[i-1]==s3[i-1] && A[0][i-1]){A[0][i]=true;}
           }
                  
           for (int i=1;i<=n1;i++){
               for (int j=1;j<=n2;j++){
                   A[i][j]= (A[i][j-1] && (s2[j-1]==s3[i+j-1])) || (A[i-1][j]&& (s1[i-1]==s3[i+j-1]));   
               }
           }
           return A[n1][n2];
}

int main(){
	string s1 = "aabcc";
	string s2 = "dbbca";
	string s3 = "aadbbcbcac";
	cout << isInterleave(s1, s2, s3);
	return 0;
}
