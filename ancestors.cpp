#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stack>

typedef struct node node;

struct node {
	int data;
	node *left;
	node *right;
};

node *newnode(int data) {
	node *p = (node*)malloc(sizeof(node));
	p->data = data;
	p->right = NULL;
	p->left = NULL;
	return p;
}

void print_inorder(node *root) {
	if( root ) {
		print_inorder(root->left);
		printf("%d\t", root->data);
		print_inorder(root->right);
	} else {
		return;
	}
}

bool path_sum(node *root, int sum, int *path, int i) {
	//preorder traversal
	if( root ) {
		//processing...
		sum = sum - root->data;
		path[i++] = root->data;
		//followed by recurssive call to left and right respectively.
		return ( path_sum(root->left, sum, path, i) || path_sum(root->right, sum, path, i) );

	} else {
		return ( sum == 0 );
	}
}

int main() {
	int sum = 17;
	int path[100];
 
/* 
  	Constructed binary tree is
            10
          /   \
        8      2
      /  \    /
    3     5  2
*/
    node *root = newnode(10);
  	root->left        = newnode(8);
  	root->right       = newnode(2);
  	root->left->left  = newnode(3);
  	root->left->right = newnode(5);
  	root->right->left = newnode(2);

 	if( path_sum(root, sum, path, 0) ) {
 		printf("path exists!\n");
 	} else {
 		printf("no sum path.\n");
 	}
	return 0;
}