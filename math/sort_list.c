#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
    struct s_list   *next;
    void             *value;
} t_list;

t_list	*sort_list(t_list* head, int (*cmp)(int, int))
{
    if (!head)
        return NULL;
    
    t_list *current = head;

    while (current->next)
    {
        if (!cmp(*(int *)current->value, *(int *)current->next->value))
        {
            int tmp = *(int *)current->value;
            *(int *)current->value = *(int *)current->next->value;
            *(int *)current->next->value = tmp;
        }
        current = current->next;
    }
    return (head);
}
