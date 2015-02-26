#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

int maxPoints(vector<Point> &points){
	
	int size = points.size();
	if ( size <= 2 )
		return size;
	
	int max = 0;
	for ( int i = 0; i < size; i++ ){
		vector<double> slope;
		int counter1 = 1;
		int counter2 = 0;
		int maxtmp = 0;
		for ( int j = 0; j < size; j++ ){
			if ( j == i )
				continue;
			if ( points[i].x == points[j].x ){
				if ( points[i].y == points[j].y)
					counter1++;
				else
					counter2++;
				continue;
			}
			double tmp = (double)(points[i].y - points[j].y)/(double)(points[i].x - points[j].x);
			slope.push_back(tmp);
		}
		
		sort(slope.begin(), slope.end());
		int counter = 0;
		for ( int i = 0; i < slope.size(); i++ ){
			cout << slope[i] << " ";
			if ( i == 0 ){
				counter = 1;
				continue;
			}
			if ( slope[i] == slope[i-1] )
				counter++;
			else {
			    if ( counter > maxtmp)
			   	   maxtmp = counter;
				counter = 1;
			}
		}
		if ( counter > maxtmp )
			maxtmp = counter;
		if ( counter2 > maxtmp )
			maxtmp = counter2;
		if ( maxtmp + counter1 > max )
			max = maxtmp + counter1;
		cout << maxtmp << " " << counter << endl;
	}
	return (max);
}

int main(){
	int A[] = {84, 0, 1, 0, 0, 1, 21, 42, -42};
	int B[] = {250,0, 0, -70,-70, -1, 10, 90, -230};
	vector<Point> points;
	for ( int i = 0; i < 9; i++ )
		points.push_back(Point(A[i],B[i]));
	cout << maxPoints(points);
}
