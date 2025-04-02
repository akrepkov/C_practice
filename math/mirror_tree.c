#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct treenode {
	int data;
	struct treenode *left;
	struct treenode *right;
} node;


void printnode(node *temp){
	if (temp == NULL)
		return ;
	printnode(temp->left);
	printf ("%d ", temp->data);
	printnode(temp->right);
}

// node* insert_data(int data){
// 	node *h = (node *)malloc(100);
// 	h->data = data;
// 	h->left = NULL;
// 	h->right = NULL;
// 	return h;
// }

// void ft_insert_node_if (node **tree, int data){
// 	node *new = *tree;
// 	if (data < new->data) ft_insert_node_if(&new->left, data);
// 	else ft_insert_node_if(&new->right, data);
// }

void mirrorNode(node *temp){
	if (temp == NULL)
		return ;
	node *new = temp->left;
	temp->left = temp->right;
	temp->right = new;
	mirrorNode(temp->left);
	mirrorNode(temp->right);
}

//      1
//   2     3
// 4  5   6  7


int main() {
	node *h = (node *)malloc(100);
	h->data = 10;
	h->left = NULL;
	h->right = NULL;
	node *g = (node *)malloc(100);
	g->data = 9;
	g->left = NULL;
	g->right = NULL;
	node *f = (node *)malloc(100);
	f->data = 8;
	f->left = NULL;
	f->right = NULL;
	node *e = (node *)malloc(100);
	e->data = 7;
	e->left = NULL;
	e->right = NULL;
	node *d = (node *)malloc(100);
	d->data = 6;
	d->left = h;
	d->right = NULL;
	node *c = (node *)malloc(100);
	c->data = 5;
	c->left = f;
	c->right = g;
	node *b = (node *)malloc(100);
	b->data = 4;
	b->left = d;
	b->right = e;
	node *a = (node *)malloc(100);
	a->data = 3;
	a->left = b;
	a->right = c;

	node *temp = a;
	printnode(temp);
	printf("\n");
	mirrorNode(temp);
	printnode(temp);
	printf("\n");
}

