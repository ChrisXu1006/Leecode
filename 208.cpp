#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class TrieNode {
public:
    TrieNode* chars[26];
    bool isword;
    // Initialize your data structure here.
    TrieNode() {
        for ( int i = 0; i < 26; i++ )
            chars[i] = NULL;
        isword = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode* cur = root;
        int len = s.length();
        for ( int i = 0; i < len; ++i ){
            if ( cur->chars[s[i] - 'a'] == NULL )
                cur->chars[s[i] - 'a'] = new TrieNode();
            cur = cur->chars[s[i] - 'a'];
        }
        cur->isword = true;
        return;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
		TrieNode* cur = root;
		int len = key.length();
		for ( int i = 0; i < len && cur != NULL; i++ ){
		    cur = cur->chars[key[i] - 'a'];
		}
		if ( cur == NULL )
		    return false;
		else
		    return cur->isword;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        int index = 0;
        while ( index < prefix.length() ){
            if ( cur->chars[prefix[index]-'a'] == NULL )
                return false;
            cur = cur->chars[prefix[index]-'a'];
            index++;
        }
        return true;
    }

private:
    TrieNode* root;
};

int main(){
	Trie A;
	A.insert("a");
	cout << A.search("a") << endl;
	cout << A.startsWith("a") << endl;
	return 0;
}