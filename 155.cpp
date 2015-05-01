#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class MinStack {
public:
    void push(int x) {
        s1.push(x);
        if ( s2.empty() || x <= s2.top() )
            s2.push(x);
        return;
    }

    void pop() {
        int tmp = s1.top();
        s1.pop();
        if ( tmp == s2.top() )
            s2.pop();
        return;
    }

    int top() {
        return s1.top();
    }

    int getMin() {
        return s2.top();
    }
    stack<int> s1;
    stack<int> s2;
};


int main(){
	string s = "a";
	reverseWords(s);
	cout << s;
	return 0;
}
