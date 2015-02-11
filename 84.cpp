#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <ctype.h>

using namespace std;

map<string, int> table;

vector<string> fullJustify(vector<string> &words, int L){
	
    int size = words.size();
	vector<string> text;
	string row = "";
	int full = 0;
	int start = 0;
	
	for ( int i = 0; i < size; ){
		
		int len = words[i].length();

		if ( full + len == L || full + len + 1 == L ){
			//int num = i - start + 1;
			int nspace = L - ( full - i + start + len );
			int sspace ;
			int dspace ;
			
			if ( i - start == 0 ){
				sspace = 0;
				dspace = L - len;
			}
			else{
				sspace = nspace/(i - start);
				dspace = nspace%(i - start);
			}
			
			for ( int j = start; j <= i; j++ ){
				row = row + words[j];
				for ( int k = 0; j < i && k < sspace; k++ ){
					row = row + ' ';
				}
				if ( dspace > 0 ){
						row = row + ' ';
						dspace--;
				}	
			}
			start = i + 1;
			full = 0;
			if ( row.length() < L ){
				while ( row.length() < L )
					row += ' ';
			}
			text.push_back(row);
			row = "";
			i++;
		}
		
		else if ( full + len + 1 < L ){
			if ( i == size - 1 ){
				for (int j = start; j <= i; j++ )
					row = row + words[j] + ' ';
		       if ( row.length() < L ){
				while ( row.length() < L )
					row += ' ';
			    }
				text.push_back(row);
				break;
			}
			
			full += ( len + 1 );
			i++;
		}
		
		else{
			int num = i - start;
			if ( num == 0 )
				break;
			int nspace = L - ( full - i + start );
			int sspace;
			int dspace;
			
			if ( i - start - 1  == 0 ){
				sspace = 0;
				dspace = L - words[start].length();
			}
			else{
					sspace = nspace/(i - start - 1);
					dspace = nspace%(i - start - 1);
			}
			
			for ( int j = start; j < i; j++ ){
				row = row + words[j];
				for ( int k = 0; j < i - 1 && k < sspace; k++ ){
					row = row + ' ';
				}
				if ( dspace > 0 ){
					row = row + ' ';
					dspace--;
				}	
			}
			start = i;
			full = 0;
			if ( row.length() < L ){
				while ( row.length() < L )
					row += ' ';
			}
			text.push_back(row);
			row = "";
		}
	}
	return text;
}

int main(){
	//string s[7] = {"This", "is", "an", "example", "of", "text", "justification."};
	string s[7] = {"Listen","to","many,","speak","to","a","few."};
	vector<string> words;
	for ( int i = 0; i < 7; i++ )
		words.push_back(s[i]);
	vector<string> text = fullJustify(words, 6);
	for ( int i = 0; i < text.size(); i++ )
		cout << text[i] << endl;
	return 0;
}
