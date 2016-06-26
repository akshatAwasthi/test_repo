#include <iostream>
#include <string>
#include <algorithm>
#define D 26
using namespace std;

struct trie_node {
	int val;
	trie_node *children[D];
};

struct trie_adt {
	int count;
	trie_node *root;
};

trie_node *make_node() {
	trie_node *p = (trie_node *)malloc(sizeof(trie_node));
	p->val = 0;
	for( int i = 0; i < D; ++i ) {
		p->children[i] = NULL;
	}
}

trie_adt *make_trie() {
	trie_adt *p = (trie_adt *)malloc(sizeof(trie_adt));
	p->root = make_node();
	p->count = 0;
}

void insert(trie_adt *trie, string key) {
	if( trie ) {
		if( trie->root ) {
			trie_node *p = trie->root;
			int n = key.size();
			for( int i = 0; i < n; ++i ) {
				int x = (int)key[i] - (int)'a';
				if( !p->children[x] ) {
					p->children[x] = make_node();
				}
				p = p->children[x];
			}
			p->val = n;
			trie->count++;
			cout<<"success! in inserting "<<key<<"\n";
		}
	}	
}

bool search(trie_adt *trie, string key) {
	if( trie ) {
		if( trie->root ) {
			trie_node *p = trie->root;
			int n = key.size();
			for( int i = 0; i < n; ++i ) {
				int x = (int)key[i] - (int)'a';
				if( !p->children[x] ) {
					cout<<"could not find "<<key[i]<<"\n";
					return false;
				} else {
					p = p->children[x];
				}
			}
			return ( p && (p->val != 0) ); 
		} else {
			cout<<"root is null\n";
			return false;
		}
	} else {
		cout<<"trie does not exist\n";
		return false;
	}
}


bool is_leaf(trie_node *p) {
	if( p->val ) {
		return true;
	} else {
		return false;
	}
}

bool has_child(trie_node *p) {
	for( int i = 0; i < D; ++i ) {
		if( p->children[i] ) {
			return true;
		}
	}
	return false;
}

bool util(trie_node *p, string key, int i, int n) {
	if( p ) {
		// i == n => last character of key
		if( i == n ) {			
			if( p->val != 0 ) {
				//val != 0 => node p marks end of a word in the trie
				//making it 0 ensures search(key) would give false 
				p->val = 0;
				if( !has_child(p) ) {
					//to recursively delete node p (bottom up) if it has no children
					return true;													
				} else {
					//p has child => is part of another word in trie, as deletion is bottom up
					//any children of p that were a part of key would have already been deleted
					return false;
				}
			}
		} else {	//non last character node
			int x = (int)key[i] - (int)'a';
			if( util(p->children[x], key, i+1, n) ) {
				free(p->children[x]);
				p->children[x] = NULL;
				// below return expression avoids deleting internal(to string key, not internal to trie) nodes that..
				// are common to other words in trie
				// is_leaf(p)) ensures that any words that are a prefix of key are saved from deletion
				// has_child(p) ensures nodes common to other words are saved.
				// return true => fit to be deleted
				// return false => node common to another word
				cout<<"freed "<<key[i]<<"\n";
				return ( !( is_leaf(p) || has_child(p) ) );
			}
		}
	} else {
		return false;
	}
}

void del( trie_adt *trie, string key) {
	int n = key.size();
	if( n != 0 ) {
		if ( util(trie->root, key, 0, n) ) {
			cout<<key<<" deleted\n";
		} else {
			cout<<"could not delete "<<key<<"\n";
		}
	}
}

int main() {
	trie_adt *trie = make_trie();
	string word;
	/*
	insert(trie, "akshat");
	insert(trie, "awasthi");
	insert(trie, "abcd");
	insert(trie, "efg");
	insert(trie, "hijkl");
	*/
	insert(trie, "that");
	insert(trie, "this");
	cout<<"enter word to find : ";
	cin>>word;
	if( search(trie, word) ) {
		cout<<"found\n";		
	} else {
		cout<<"not found\n";
	}
	cout<<"enter word to delete : ";
	cin>>word;
	del(trie, word);
	cout<<"enter word to find : ";
	cin>>word;
	if( search(trie, word) ) {
		cout<<"found\n";		
	} else {
		cout<<"not found\n";
	}
	return 0;
}