#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

bool isValid(string s) {
      stack<char> S;
      for ( int i = 0; i < s.length(); i++ ){
          if ( s[i] == '(' || s[i] == '{' || s[i] == '[' )
              S.push(s[i]);
          
          else if ( s[i] == ')' ){
              if (S.empty() || S.top() != '(')
                  return false;
              else
                  S.pop();
          }
          
          else if ( s[i] == '}' ){
              if (S.empty() || S.top() != '{')
                  return false;
              else
                  S.pop();
          }
          
          else {
              if (S.empty() || S.top() != '[')
                  return false;
              else
                  S.pop();
          }
      }
      
      if (S.empty())
          return true;
      else
          return false;
  }