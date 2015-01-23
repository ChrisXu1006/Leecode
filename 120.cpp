#include <iostream>
#include <vector>

using namespace std;
	
int minimumTotal(vector<vector<int> > &triangle){
    int n = triangle.size();
       vector<int> minlen(triangle.back());
       for (int layer = n-2; layer >= 0; layer--) // For each layer
       {
           for (int i = 0; i <= layer; i++) // Check its every 'node'
           {
               // Find the lesser of its two children, and sum the current value in the triangle with it.
               minlen[i] = min(minlen[i], minlen[i+1]) + triangle[layer][i]; 
           }
       }
	   sort(minlen.begin(), minlen.end());
       return minlen[0];
}

int main(){
	int a[] = { {2}, {3,4}, {6,5,7},{4,1,8,3} };
	vector<vector<int> > res;
	for (int i = 0; i < 4 ; i++){
		vector<int> ele;
		for ( int j = 0; j < 1 ; j++)
			ele.push_back(a[i][j]);
		res.push_back(ele);
		ele.clear();
	}
	cout << minimumTotal(res);
	return 0;
}