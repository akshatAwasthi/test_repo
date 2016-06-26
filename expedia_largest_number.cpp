#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct comp {
	bool operator()(const int &a, const int &b) const {
		return a > b;
	}	
}c;

char *func(int *a, int n) {
	vector<int> v;
	for( int i=0; i<n; ++i ) {
		int temp = a[i];
		while( temp > 0 ) {
			v.push_back(temp%10);
			temp = temp/10;
		}
	}
	sort(v.begin(), v.end(), c);
	int size = v.size();
	char *c = new char[size+1];
	for( int i=0; i<size; ++i ) {
		c[i] = '0' + v[i];
	}
	c[size] = '\0';
	return c;
}

int main() {
	int n;
	cin>>n;
	int *a = new int[n];
	for( int i=0; i<n; i++ ) {
		cin>>a[i];
	}
	char *c = func(a, n);
	cout<<c;
	return 0;
}
