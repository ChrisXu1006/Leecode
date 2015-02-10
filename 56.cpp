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

bool myfunc(Interval a, Interval b){
	return a.start <= b.start;
}

vector<Interval> merge(vector<Interval> &intervals){
	
	vector<Interval> result;
	
	int size = intervals.size();
	if ( size == 0 )
		return result;
	
	sort(intervals.begin(), intervals.end(), myfunc)
	result.push_back(intervals[0]);
	
	for ( int i = 1; i < size; i++ ){
		int cur = 0;
		while ( cur < result.size() ){
			if ( intervals[i].start >= result[cur].start && intervals[i].start <= result[cur].end ){
				result[cur].start = min(intervals[i].start, result[cur].start);
				result[cur].end   = max(intervals[i].end, result[cur].end);
				break;
			}
			
			if ( intervals[i].end >= result[cur].start && intervals[i].end <= result[cur].end){
				result[cur].start = min(intervals[i].start, result[cur].start);
				result[cur].end   = max(intervals[i].end, result[cur].end);
				break;
			}
			
			if ( intervals[i].end >= result[cur].end && intervals[i].start <= result[cur].start){
				result[cur].start = min(intervals[i].start, result[cur].start);
				result[cur].end   = max(intervals[i].end, result[cur].end);
				break;
			}
			
			cur++;
		}
		if ( cur == size )
			result.push_back(intervals[i]);
	}
	return result;
}

int main(){
	int A[] = {};
	cout <<  ;
	
	return 0;
}
