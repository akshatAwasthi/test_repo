#include <iostream>
#include <map>

using namespace std;

struct abc {
	int data;
	bool operator<( const abc& other ) const {
   		return this->data < other.data;   
 	}
};

map <int, int> memo;
map <int, abc> dict;
map <abc, abc> x;

int main() {
	memo[1] = 1;
	memo.insert(pair<int, int>(1, 1));
	memo[2] = 2;
	abc a; a.data = 7;
	abc b; b.data = 8;
	abc c; c.data = 9;
	dict[1] = a;
	dict[2] = b;
	dict[3] = c;

	for( map<int, int>::iterator i = memo.begin(); i != memo.end(); i++) {
		cout<<(i->first)<<"->"<<(i->second)<<"\t";
	}
	memo[1] = 3;
	cout<<"\nagain..\n";
	for( map<int, int>::iterator i = memo.begin(); i != memo.end(); i++) {
		cout<<(i->first)<<"->"<<(i->second)<<"\t";	
	}
	
	cout<<"\nnow for map<int, abc>dict..\n";
	for( map<int, abc>::iterator i = dict.begin(); i != dict.end(); i++) {
		cout<<((i->second).data)<<"\t";
	}
	x[a] = a;
	x[b] = b;
	x[c] = c;

	cout<<"\nnow map<abc, abc>x..\n";
	for( map<abc, abc>::iterator i = x.begin(); i != x.end(); i++) {
		cout<<((i->second).data)<<"\t";
	}
	return 0;
}