#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>

using namespace std;

int lengthOfLastWord(string s) {
        s = s + ' ';
        int len = s.length();
        int counter = 0;
        int cur = 0;
        int index = 0;
        
        while ( index < len ){
            if ( s[index] != ' ' )
                cur++;
            else{
                if ( cur != 0 ){
                    counter = cur;
                    cur = 0;
                }
            }
            index++;
        }
        return counter;
    }
int main(){
	cout << lengthOfLastWord("Hello World");
	return 0;
}
