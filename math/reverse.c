#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
	int 	value;
	struct s_list *next;
} t_list;

t_list	*reverse_list(t_list* lst){
	t_list* original = NULL;
	t_list* current = lst;
	if (lst == NULL)
		return lst;
	t_list* new = NULL;
	while (current != NULL){
		new = current->next;
		current->next = original;
		original = current;
		current = new;
		if (new != NULL)
	}
	return original;
}

int main(){
	t_list* d = (t_list *)malloc(256);
	d->value = 1;
	d->next = NULL;
	t_list* c = (t_list *)malloc(256);
	c->value = 2;
	c->next = d;
	t_list* b = (t_list *)malloc(256);
	b->value = 3;
	b->next = c;
	t_list* a = (t_list *)malloc(256);
	a->value = 4;
	a->next = b;

	t_list* e = reverse_list(a);
	while(e != NULL){
		printf("Value  %d - ", e->value);
		e = e->next;
	}
	return 0;
}

