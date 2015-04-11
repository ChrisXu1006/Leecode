#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

map<char,int> table;
   
   bool isValid(vector<vector<char> > &board, int i, int j){
       if ( board[i][j] == '.' )
           return true;
       
       if (table.find(board[i][j]) != table.end())
           return false;
       else{
           table[board[i][j]] = 0;
           return true;
       }
   }
   
   bool isValidSudoku(vector<vector<char> > &board) {
       
       int len = board.size();
       if ( len == 0 )
           return true;
       int wid = board[0].size();
       
       for ( int i = 0; i < len; i++ ){
           table.clear();
           for ( int j = 0; j < wid; j++ ){
               if ( !isValid(board, i, j) )
                   return false;
           }
           
           table.clear();
           for ( int j = 0; j < wid; j++ ){
               if ( !isValid(board, j, i) )
                   return false;
           }
       }
       
       for ( int i = 0; i < len - 2; i += 3 ){
           for ( int j = 0; j < wid - 2; j += 3){
               table.clear();
               for ( int a = 0; a < 3; a++ ){
                   for ( int b = 0; b < 3; b++ ){
                       if ( !isValid(board, (i+a), (j+b) ) )
                           return false;
                   }
               }
           }
       }
       
       return true;
   }

int main(){
	int A[4] = {5, 7};
	cout << searchInsert(A, 2, 1);
}
