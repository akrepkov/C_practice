/*
Write a function that takes a list and a function pointer, and applies this
function to each element of the list.
It must be declared as follows:
void    apply_function(t_list *begin_list, void (*f)(void *));
The function pointed to by f will be used as follows:
(*f)(list_ptr->data);
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct    s_list
{
    struct s_list *next;
    int data;
}                 t_list;


void    apply_function(t_list *begin_list, int (*sum)(int *)){
	while(begin_list!= NULL){
		sum(&begin_list->data);
		begin_list = begin_list->next;
	}
}

int sum (int *a){
	*a =(*a)*10;
	return *a;
}


int main(){
	t_list *b = (t_list *)malloc(sizeof(t_list));
	b->data = 2;
	b->next = NULL;
	t_list *a = (t_list *)malloc(sizeof(t_list));
	a->data = 1;
	a->next = b;
	apply_function(a, sum);
	t_list* cur;
	cur = a;
	while (cur != 0)
	{
		printf("%d, ", cur->data);
		cur = cur->next;
	}
	return 0;
}
