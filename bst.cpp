#include <iostream>
#include <stdlib.h>

using namespace std;

struct node {
	int data;
	node *left;
	node *right;
};

void insert(node **root, int data) {
	if( *root ) {
		if( data > (*root)->data ) {
			insert(&(*root)->right, data);
		} else if( data < (*root)->data ) {
			insert(&(*root)->left, data);
		} else {
			cout<<"duplicate!"<<"\n";
		}
	} else {
		node *p = (node *)malloc(sizeof(node));
		p->data = data;
		p->left = NULL;
		p->right = NULL;
		*root = p;
	}
}

int delete(node **root, int key) {
	int temp;
	if( *root ) {
		if( (*root)->data == key ) {
			if( (*root)->left && (*root)->right ) {
				int x = find_min((*root)->right);
				temp = (*root)->data;
				(*root)->data = x;
				delete(&(*root)->right, x);
				return temp;
			} else if( (*root)->left == NULL ) {

			}
		}
	}
}

int delete(node **root, int key) {
	node *p;
	node *q;
	p = *root;
}

void print_bst(node *root) {
	if( root ) {
		print_bst(root->left);
		cout<<root->data<<"\t";
		print_bst(root->right);
	}
}

int main() {
	node *tree = NULL;
	node **root = &tree;
	insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    print_bst(tree);
    cout<<"\n";
}
