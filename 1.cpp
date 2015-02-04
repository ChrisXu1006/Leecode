#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> twoSum(vector<int> &numbers, int target){
	
	map<int,int> table;
	
	int size = numbers.size();
	for ( int i = 0; i < size; i++ ){
		pair<int,int> node(numbers[i], i);
		table.insert(node);
	}
	
	vector<int> result;
	map<int,int>::iterator it;
    
	for ( int i = 0; i < numbers.size(); i++ ){
		if ( table.find(target - numbers[i]) != table.end() ){
            if ( i < table[target-numbers[i]]){
                result.push_back(i+1);
                result.push_back(table[target-numbers[i]]+1);
                return result;
            }
            if ( i > table[target-numbers[i]]){
                result.push_back(table[target-numbers[i]]+1);
                 result.push_back(i+1);
                return result;
            }
		}
	}
    return result;
}

int main(){
	int A[] = {0, 4, 3, 0};
	vector<int> num;
	for ( int i = 0; i < 4; i++ )
		num.push_back(A[i]);
	vector<int> result = twoSum(num, 0);
	for ( int i = 0; i < result.size(); i++ )
		cout << result[i] << " ";
    cout << endl;
    
}
