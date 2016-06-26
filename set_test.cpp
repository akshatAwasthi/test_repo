#include <iostream>
#include <set>

using namespace std;

struct node {
	int key;

	bool operator<( const node& other ) const {
   		return this->key < other.key;   
 	}
};

/*
practise..

bool operator<( const node& other ) const {
	bool x = this.key < other.key;
	return x;
}


*/

set<node> visited;

int main()
{
	node a, b, c;
	a.key = 1;
	b.key = 2;
	c.key = 3;

	visited.insert(a);
	visited.insert(b);
	visited.insert(c);

	
	set<node>::iterator i = visited.begin();
	for( ; i != visited.end(); i++ ) {
		cout<<(*i).key<<"\t";
	}

	cout<<"\nsize of set visited = "<<visited.size()<<"\n";
	cout<<"capacity (max_size) of set visited = "<<visited.max_size()<<"\n";
	//set<node>::iterator x = visited.find(2);
	cout<<"found.. "<<(*(visited.find(b))).key<<"\n";

	visited.erase(b);
	for( i = visited.begin(); i != visited.end(); i++ ) {
		cout<<(*i).key<<"\t";
	}
	/*while( !visited.empty() ) {
		visited.erase();
		--i;
	}*/
	cout<<"\n";

	return 0;
}