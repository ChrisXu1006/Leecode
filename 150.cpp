#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int evalRPN(vector<string> &tokens){
    int result = 0;
	
  	if ( tokens.size() == 0 )
  		return result;
	
  	stack<int> buf;
  	int oper1, oper2;
  	for ( int i = 0; i < tokens.size(); i++ ){
  		if ( tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/" )
  			buf.push(stoi(tokens[i]));
		
  		else if ( tokens[i] == "+"){
  			oper1 = buf.top();
  			buf.pop();
  			oper2 = buf.top();
  			buf.pop();
  			result = oper2 + oper1;
  			buf.push(result);
  		}
		
  		else if ( tokens[i] == "-"){
  			oper1 = buf.top();
  			buf.pop();
  			oper2 = buf.top();
  			buf.pop();
  			result = oper2 - oper1;
  			buf.push(result);
  		}
		
  		else if ( tokens[i] == "*"){
  			oper1 = buf.top();
  			buf.pop();
  			oper2 = buf.top();
  			buf.pop();
  			result = oper2 * oper1;
  			buf.push(result);
  		}
		
  		else if ( tokens[i] == "/"){
  			oper1 = buf.top();
  			buf.pop();
  			oper2 = buf.top();
  			buf.pop();
  			result = oper2 / oper1;
  			buf.push(result);
  		}
		
  		else
  			return INT_MIN;
  	}
  	return buf.top();
}


int main(){
	string a[] = {"2", "1", "+", "3", "*"};
	vector<string> &tokens;
	for (int i = 0; i < 5, i++)
		tokens.push_back(a[i]);
	cout << evalRPN(tokens);
}
