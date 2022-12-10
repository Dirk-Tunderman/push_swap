#include "pushlib.h"
#include <limits.h>

t_list    *create_list(t_list **list_a)
{
    *list_a = malloc(sizeof(t_list));
    if (!list_a)
        return (NULL);
    return (*list_a);
}

// void  *add_begin_lst(t_list tail)
// {



// }

int lstsize(t_list **lst)
{
    int i;

    i = 0;
    while (lst)
    {
        (*lst) = (*lst)->next;
        i++;
    }
    return (i);
}

void  *fill_list(t_list **list_a, char *num)
{

    if (!num || !list_a)
        return (NULL);
    (*list_a)->content = atoi(num);
    (*list_a)->next = *list_a;

    return (*list_a);
}

int push_swap(int argc, char **argv)
{
    int     i;
    int     j;
    char    num[10];
    t_list *list_a;

    list_a = create_list(&list_a);

    i = 1;
    j = 0;
    while (i < argc)
    {
        while (argv[i][j] != '\0')
        {
            num[j] = argv[i][j];
            j++;
        }
        num[j] = '\0';
        list_a = fill_list(&list_a, num);
        //printf("%d", list_a->content);
        j = 0;
        i++;
    }
    printf("%d", lstsize(list_a));

    return (0);
}


int main(int argc, char **argv)
{
    push_swap(argc, argv);


}