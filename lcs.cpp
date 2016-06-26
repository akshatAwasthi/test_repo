#include <iostream>
#include <string>
using namespace std;

int main() {
	string a,b;
	cin>>a>>b;
	int n = a.size();
	int m = b.size();
	int **t = new int*[n+1];
	for( int i=0; i<n+1; ++i ) {
		t[i] = new int[m+1];
	}
	for( int i=0; i<n+1; ++i ) {
		for( int j=0; j<m+1; ++j ) {
			if( i == 0 || j == 0 ) {
				t[i][j] = 0;
			} else if( a[i] == b[j] ) {
				t[i][j] = t[i-1][j-1] + 1;
			} else {
				t[i][j] = max(t[i-1][j], t[i][j-1]);
			}
		}	
	} 
	cout<<t[n][m]<<"\n";
	return 0;
}