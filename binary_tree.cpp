#include <iostream>
#include <queue>
#include <stdlib.h>

using namespace std;

struct node {
	int data;
	node *left;
	node *right;
};

/*node* add_node(int x, node *root) {
	node *p = (node *)malloc(sizeof(node));
	//node *p = new node;
	//cout<<"sizeof(*p)"<<sizeof(*p)<<"\n";
	p->data = x;
	p->right = NULL;
	p->left = NULL;

	if( root == NULL ){
		root = p;
		cout<<"root was null for "<<x<<"\n";
		cout<<"root now has data "<<root->data<<"\n";
		return root;
	} else {
		queue<node*> q;
		q.push(root);
		node *temp = NULL;
		cout<<"now traversing tree for "<<x<<"\n";
		while( !q.empty() ) {
			temp = q.front(); q.pop();
			cout<<temp->data<<"\t";
			if( temp->left != NULL )
				q.push(temp->left);
			if( temp->right != NULL )
		 		q.push(temp->right);
		} 
		//cout<<x<<" was added as a child of "<<temp->data;
		cout<<"\n";
		if( temp->left == NULL )
			temp->left = p;
		if( temp->right == NULL ) 
			temp->right = p;
	}
	free(p);
	return root;
}
*/

node* add_edge(int x) {
	node *p;
	p = (node *)malloc(sizeof(node));
	p->data = x;
	p->left = NULL;
	p->right = NULL;
	return p; 
		
}
void inorder_print(node *root) {
	if( root == NULL ) {
		return;
	} else {
		inorder_print(root->left);
		cout<<root->data<<"\t";
		inorder_print(root->right);
	}
}

int main() {
	node *t;
	/*t = add_node(1, t);
	//cout<<"t now has data "<<t.data<<"\n";
	add_node(2, t);
	add_node(3, t);
	add_node(4, t);
	add_node(5, t);*/
	t->data = 1;
	t->left = add_edge(2);
	t->right = add_edge(3);
	t->left->left = add_edge(4);
	t->left->right = add_edge(5); 
	inorder_print(t);
	return 0;
}
