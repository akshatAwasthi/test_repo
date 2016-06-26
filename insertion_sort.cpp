#include <iostream>
using namespace std;

void i_sort(int *a, int n) {
	for( int i=1; i<n; ++i ) {
		int x = a[i];
		int j = i;
		while( j>0 && a[j-1]>x ) {
			a[j] = a[j-1];
			j--;
		}
		a[j] = x;
	}
}

void merge(int *a, int l, int m, int r) {
	int i = l;
	int j = m+1;
	int k = l;
	int *left = new int[m-l + 1];
	int *right = new int[r-(m+1) + 1];
	for( ; i<=m; ++i ) {
		left[i] = a[i];
	}
	k=0;
	for( ; j<=r; ++j ) {
		right[j] = a[j]
	}
	while( i<=m && j<=r && k<=r ) {
		if(  )
	}
}

void merge_sort(int *a, int l, int r) {
	int m = (l+r)/2;
	merge_sort(a, l, m);
	merge_sort(a, m+1, r);
	/*
	int i = l;
	int j = m+1;
	int k = l;
	while( i<=m && j<=r && k<=r ) {
		if( left[i] < right[j] ) {
			a[k++] = left[i++];
		} else {
			a[k++] = right[j++];
		}
	}
	while( i<=m && k<=r ) {
		a[k++] = left[i++];
	} 
	while( j<=r && k<=r ) {
		a[k++] = right[j++];
	}
	return a;
	*/
	merge(a, l, m, r);
}

int main() {
	int a[5] = {1,0,1,2,7};
	merge_sort(a, 0, 4);
	for( int i=0; i<5; ++i ) {
		cout<<a[i]<<" ";
	}
	return 0;
}