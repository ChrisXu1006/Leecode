#include <iostream>
#include <cstring>
#include <string>
#include <stack>
#include <vector>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> merge(vector<Interval> &intervals, Interval newInterval){
	
    vector<Interval> result;
	
 	int size = intervals.size();
	
 	int i;
	
 	for ( i = 0; i < size; i++ ){
 		if ( intervals[i].end < newInterval.start ){
 			result.push_back(intervals[i]);
 			continue;
 		}
		
 		if ( intervals[i].start > newInterval.end )
 			break;
		
 		newInterval.start = min(newInterval.start, intervals[i].start);
 		newInterval.end   = max(newInterval.end, intervals[i].end);
 	}
	
 	result.push_back(newInterval);
	
 	while ( i < size ){
 	    result.push_back(intervals[i]);
 	    i++;
 	}
	
 	return result;
}

int main(){
	int A[] = {};
	cout <<  ;
	
	return 0;
}
