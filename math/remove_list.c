#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
    struct s_list   *next;
    void             *value;
} t_list;

void remove(t_list **head, void *match, int (*cmp)())
{
    if (! head || !*head)
        return;
    
    t_list  *current = *head;
    t_list  *tmp;

    while (current)
    {
        if (cmp(current->value, match) == 0)
        {
            head = current->next;
            tmp = current;
            current = current->next;
            free(tmp);
        }
        else if (current->next && cmp(current->next->value, match) == 0)
        {
            tmp = current->next;
            current->next = current->next->next;
            free (tmp);
        }
        else
            current = current->next;
    }
}
