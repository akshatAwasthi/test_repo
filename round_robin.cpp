#include <iostream>
#include <vector>

using namespace std;

int main() {
	int wait, turnaround;
	int s_wait = 0;
	int s_turnaround = 0;
	int n, q;
	cout<<"enter number of processes : ";
	cin>>n;
	cout<<"enter time quantum : ";
	cin>>q;
	int *a = new int[n];
	int *b = new int[n];
	int *x = new int[n];
	for( int i=0; i<n; ++i ) {
		cout<<"p["<<i+1<<"] : at bt..\n";
		cin>>a[i]>>b[i];
		x[i] = b[i];
	}
	for( int i=0; i<n; ++i ) {
		cout<<a[i]<<" "<<b[i]<<" "<<x[i]<<"\n";
	}
	int remaining = n;
	int flag = 0;
	for( int i=0, t=0; remaining != 0; (i+1)%n ) {
		cout<<"entered loop..";
		if( a[i] <= t) {
			if( x[i] <= q && x[i] > 0) {
				x[i] = 0;
				cout<<"x["<<i+1<<"] = "<<x[i];
				flag = 1;
			} else if( x[i] > 0 ) {
				x[i] = x[i] - q;
				cout<<"x["<<i+1<<"] = "<<x[i];
			} 
			if( x[i] == 0 && flag == 1) {
				remaining--;
				cout<<remaining<<" remaining";
				wait = t - a[i] - b[i];
				turnaround = wait + b[i];
				cout<<"p["<<i+1<<"finished with waiting time "<<wait<<" and turnround time "<<turnaround;
				s_turnaround += turnaround;
				s_wait += wait; 
				flag = 0;
				cout<<"in here!";
			}
		} else {
			cout<<"processing skipped!";
			t++;
		}
		cout<<"exiting loop..";
	} 
	cout<<"average waiting time = "<<s_wait*1.0/n;
	cout<<"average turnaround time = "<<s_turnaround*1.0/n;
	return 0;
}