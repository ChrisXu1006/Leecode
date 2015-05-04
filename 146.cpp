#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

class LRUCache{
public:
    LRUCache(int capacity) {
        realcapacity = capacity;
    }
    
    int get(int key) {
        if ( table.find(key) == table.end() )
            return -1;
        else{
            refresh(key);
            return table[key]->second;
        }
    }
    
    void set(int key, int value) {
        if ( table.find(key) == table.end() ){
            pair<int,int> node(key, value);
            if ( cache.size() >= realcapacity ){
                int tmp = cache.back().first;
                table.erase(tmp);
                cache.pop_back();
            }
            cache.push_front(node);
            table[key] = cache.begin();
        }
        else{
            table[key]->second = value;
            refresh(key);
        }
        return;
    }

private:
    int realcapacity;
    list<pair<int,int> > cache;
    unordered_map<int, list<pair<int,int>>::iterator > table;
    
    void refresh(int key){
        pair<int, int> node(table[key]->first, table[key]->second);
        cache.erase(table[key]);
        cache.push_front(node);
        table[key] = cache.begin();
    }

int main(){
		string s = "catsanddog";
	    string A[] = {"cat", "cats", "and", "sand", "dog"};
	    unordered_set<string> dict;
	    for ( int i = 0; i < 5; i++ )
	        dict.insert(A[i]);
	    vector<string> sols = wordBreak(s, dict);
	    for ( int i = 0; i < sols.size(); i++ )
	        cout << sols[i] << endl;
	    return 0;
	}

