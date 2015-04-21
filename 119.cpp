#include <iostream>
#include <vector>

using namespace std;
	
vector<int> getRow(int rowIndex) {
       vector<int> row;
       if ( rowIndex < 0 )
           return row;
       
       row.push_back(1);
       for ( int cur = 2; cur <= rowIndex+1; cur++ ){
           for ( int i = cur - 2; i >= 1; i-- )
               row[i] = row[i] + row[i-1];
           row.push_back(1);
       }
       return row;
   }

int main(){
	vector<int> row = getRow(5);
	return 0;
}