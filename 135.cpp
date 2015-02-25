#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

void adjust(vector<int>& candy, int tail, int counter){
	candy[tail-1] = 1;
	for ( int i = 1; i < counter; i++ )
		candy[tail-i-1] = candy[tail-i] + 1;
	if ( candy[tail-counter] >= candy[tail-counter-1] )
		candy[tail-counter-1] = candy[tail-counter] + 1;
	return;
}

int candy(vector<int> &ratings){
	
	int size = ratings.size();
	if ( size == 0 )
		return 0;
	
	vector<int> candy(size);
	candy[0] = 1;
	int counter = 0;
	for ( int i = 1; i < size; i++ ){
		if ( ratings[i] > ratings[i-1] ){
			if ( counter != 0 ){
				if ( candy[i-1] != 1 )
					adjust(candy, i, counter);
				counter = 0;
			}
			candy[i] = candy[i-1] + 1;
		}
		
		else if ( ratings[i] == ratings[i-1] ){
			if ( counter != 0 ){
				if ( candy[i-1] != 1 )
					adjust(candy, i, counter);
				counter = 0;
			}
			candy[i] = 1;
		}
		
		else if ( ratings[i] < ratings[i-1] ){
			candy[i] = candy[i-1] - 1;
			counter++;
		}
	}
	
	if ( counter != 0 )
		adjust(candy, size, counter);
	
	int result = 0;
	for ( int i = 0; i < size; i++ ){
		cout << candy[i] << endl;
		result += candy[i];
	}
	return result;
}

int main(){
	int A[] = {1, 2, 3, 4, 5, 4, 3};
	vector<int> rates;
	for ( int i = 0; i < 7; i++ )
		rates.push_back(A[i]);
	cout << candy(rates);
}
