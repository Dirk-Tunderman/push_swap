#include "pushlib.h"
#include <limits.h>

t_list    *create_list(t_list **list_a)
{
    *list_a = malloc(sizeof(t_list));
    if (!list_a)
        return (NULL);
    return (*list_a);
}

int lstsize(t_list *last)
{
    int     i;
    t_list *temp;

    temp = last;
    i = 0;
    if (temp != NULL)
    {
        i++;
        temp = temp->next;
    }
    while (temp != last)
    {
        i++;
        temp = temp->next;
    }

    return (i);
}

void  *create_fill_list(t_list **list_a, char *num, t_list **last)
{
    *list_a = malloc(sizeof(t_list));
    if (!list_a || !num)
        return (NULL);

    if (*last == NULL)
    {
        (*list_a)->content = atoi(num);
        (*list_a)->next = *list_a;
        *last = *list_a; 
    }
    else
    {
        (*list_a)->content = atoi(num);
        (*list_a)->next = (*last)->next;
        (*last)->next = *list_a;
    }
    return (*list_a);
}

t_list  *passing_list(t_list **list_a, int argc, char **argv)
{
    int     i;
    t_list  *last;

    last = NULL;
    i = 1;
    while (i < argc)
    {
        create_fill_list(list_a, argv[i], &last);
        i++;
    }
    return (*list_a);
}
