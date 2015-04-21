#include <iostream>
#include <vector>

using namespace std;
	
vector<vector<int> > generate(int numRows) {
      vector<vector<int> > tri;
      if ( numRows <= 0 )
          return tri;
       
      vector<int> firstrow(1, 1);
      tri.push_back(firstrow);
      for ( int i = 2; i <= numRows; i++ ){
          vector<int> row(i, 0);
          row[0] = 1;
          row[i-1] = 1;
          for ( int j = 1; j < i-1; j++ )
              row[j] = tri[i-2][j-1] + tri[i-2][j];
          tri.push_back(row);
      }
      return tri;
}

int main(){
	vector<vector<int> > res = generate(5);
	return 0;
}