#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string a,b;
	cin>>a>>b;
	int n = a.size();
	int m = b.size();
	n++;
	m++;
	int **table = new int*[n];
	for( int i=0; i<n; ++i ) {
		table[i] = new int[m];
	}
	
	int i;
	int j;
	//int table[80][80];
	for( i=0; i<n; ++i ) {
		for( j=0; j<m; ++j ) {
			if( a[i] == b[j] ) {
				if( i == 0 && j == 0 ) {
					table[i][j] = 0;
				} else if( i == 0 ) {
					table[i][j] = table[i][j-1];
				} else if ( j == 0 ) {
					table[i][j] = table[i-1][j];
				} else {
					table[i][j] = table[i-1][j-1];
				}
			} else {
				if( i == 0 && j == 0 ) {
					table[i][j] = 1;
				} else if( i == 0 ) {
					table[i][j] = j;
				} else if( j == 0 ) {
					table[i][j] = i;
				} else {
					int temp = min( 1+table[i-1][j], 1+table[i-1][j-1] );
					table[i][j] = min( temp, 1+table[i][j-1] );
				}
			}
		}
	}
	while( i<n ) {
		for( int x=0; x<m; ++x ) {
			cout<<"updating "<<i<<","<<x<<" ";
			table[i][x] = table[i-1][x] + 1;
		}
		i++;
	} cout<<"\n";
	while( j<m ) {
		for( int x=0; x<n; ++x ) {
			table[x][j] = table[x][j-1] + 1;
		} 
		j++;
	}
	cout<<"edit distance between given strings "<<a<<" and "<<b<<" is "<<table[n-1][m-1]<<"\n";
	cout<<"and the table matrix is..\n";
	for( int x=0; x<n; ++x ) {
		for( int y=0; y<m; ++y ) {
			cout<<table[x][y]<<" ";
		} cout<<"\n";
	}
	return 0;
}