#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

vector<vector<int> > res;
     
void dfs(vector<int> &cand, int st, int ed, vector<int> &lr){
	if (lr.size()==ed){
    	res.push_back(lr);
        return;
    }
    for (int i = st; i< cand.size();i++){
        lr.push_back(cand[i]);
        dfs(cand,i+1,ed,lr);
        lr.pop_back();
	}        
}

vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        res.clear();
         
        if ((k<1)||(n<1)||(k>n)){return res;}
        vector <int> cand;
        for (int i = 1; i<=n;i++){
            cand.push_back(i);
        }
        vector<int> lr;
        dfs(cand,0,k,lr);
        return res;
}


int main(){
	vector<vector<int> > comb = combine(4, 3);
	for ( int i = 0; i < comb.size(); i++ ){
		for ( int j = 0; j < comb[i].size(); j++ )
			cout << comb[i][j] << " ";
		cout << endl;
	}
	return 0;
}
