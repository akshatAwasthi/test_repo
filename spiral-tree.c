#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int path[100];

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

bool path_sum(node *root, int sum, int i) {
	//preorder traversal
	if( root ) {
		//processing...
		sum = sum - root->data;
		//path[i++] = root->data;
		//followed by recurssive call to left and right respectively.
		return ( path_sum(root->left, sum, i) || path_sum(root->right, sum, i) );

	} else {
		return ( sum == 0 );
	}
}
/*
void print_ancestors(int list[], int n) {
	int i = n-2;
	for( ; i>=0; i-- ) {
		printf("%d\t", list[i]);
	} 
}

void ancestors(node *root, int *ancestor_list, int i, int x) {
	if( root ) {
		if( root->data == x ) {
			return;
		}
		ancestor_list[i++] = root->data;
		ancestors(root->left, ancestor_list, i, x);
		ancestors(root->right, ancestor_list, i, x);
	} else {
		return;
	}
}

bool anc_beta(node *root, int *list, int i, int x) {
	if( root ) {
		list[i++] = root->data;

		if( root->data == x ) {
			return true;
		}
		return ( anc_beta(root->left, list, i, x) || anc_beta(root->right, list, i, x) );
	} else {
		return false;
	}
}

void get_ancestors(node *root, int x) {
	int list[10];
	anc_beta(root, list, 0, x);
	int i = 0;
	for( ; i<10; i++ ) {
		printf("%d\t", list[i]);
	}
}
*/

bool print_ancestors(node *root, int target)
{
  /* base cases */
  if (root == NULL)
     return false;
 
 	printf("now processing %d\n", root->data);
  if (root->data == target)
     return true;
 
  /* If target is present in either left or right subtree of this node,
     then print this node */
  if ( print_ancestors(root->left, target) ||
       print_ancestors(root->right, target) )
  {
    printf("%d part of path\n", root->data);
    return true;
  }
 
  /* Else return false */
  return false;
}
int main() {
	int sum = 23;
	
 
/* 
  	Constructed binary tree is
            10
          /   \
        8      2
      /  \    /
    3     5  2
   /
  4
*/
    node *root = newnode(10);
  	root->left        = newnode(8);
  	root->right       = newnode(2);
  	root->left->left  = newnode(3);
  	root->left->right = newnode(5);
  	root->right->left = newnode(2);
  	root->left->left->left = newnode(4);

 	/*if( path_sum(root, sum, 0) ) {
 		printf("path exists!\n");
 		int i = 0;
 		for( ; i<10; i++ ) {
 			printf("%d\t", path[i]);
 		}
 	} else {
 		printf("no sum path.\n");
 	}*/
 	print_ancestors(root, 2);
 	//print_ancestors(path, 10);
	return 0;
}