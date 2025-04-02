#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct		s_btree
{
	int				value;
	struct s_btree	*left;
	struct s_btree	*right;
}					t_btree;

t_btree* insert_binary_tree(t_btree *root, int value){
    t_btree* node = root;
    t_btree* new = (t_btree *) malloc(sizeof(t_btree));
    new->value = value;
    if (root == NULL)
        return new;
    if (new->value > root->value){
        insert_binary_tree(root->right, value);
        if (root->right == NULL)
            root->right = new;
    }
    if (new->value < root->value){
        insert_binary_tree(root->left, value);
        if (root->left == NULL)
            root->left = new;
    }
    return node;
}

int main(){
    t_btree* a = (t_btree *) malloc(sizeof(t_btree));
    a->value = 7;
    a = insert_binary_tree(a, 5);
    a = insert_binary_tree(a, 1);
    a = insert_binary_tree(a, 3);
    a = insert_binary_tree(a, 4);
    while (a != NULL){
        printf("CHECK %d ", a->value);
        a = a->left;

    }
     return 0;
}
