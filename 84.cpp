#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <stack> 
#include <ctype.h>

using namespace std;

map<string, int> table;

int largestRectangleArea(vector<int>& height) {
       height.push_back(0);
       int maxArea = 0;
       stack<int> S;
       int cur = 0;
       
       while ( cur < height.size() ){
		  
           if ( S.empty() || height[cur] > height[S.top()] ){
			   cout << cur << S.size() << endl;
               S.push(cur);
               cur++;
           }
           else{
			   //cout << S.top() << height[cur] << endl;
               int tmp = S.top();
			   S.pop();
			   //cout << tmp << endl;
               maxArea = max(maxArea, height[tmp] * ( S.empty() ? cur : cur - S.top()-1));
			   
           }
       }
       return maxArea;
   }

int main(){
	int A[] = {1, 1};
	vector<int> height;
	for ( int i = 0; i < 2; i++ )
		height.push_back(A[i]);
	cout << largestRectangleArea(height) << endl;
	return 0;
}
