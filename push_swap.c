#include "pushlib.h"
#include <limits.h>


void    passing_list(t_list **list, int argc, char **argv)
{
    int     i;
    i = 1;
    while (i < argc)
    {
        ft_lstadd_back(list, ft_lstnew(atoi(argv[i])));
        i++;
    }
}

int get_min(t_list **list_a)
{
    t_list *head;
    int min;
    head = *list_a;

    min = ft_largest(list_a);
    *list_a = head;
    while (head)
    {
       // printf("head is: %d\n", head->content);
        if (min > head->content && head->index == -1)
            min = head->content;
        head = head->next;
    }
    return (min);
}

void    implant_index(t_list **list_a, int min, int index)
{
    t_list *head;

    head = *list_a;
    while (*list_a)
    {
        if ((*list_a)->content == min)
            (*list_a)->index = index;
        (*list_a) = (*list_a)->next;
    }
}

void    give_index(t_list **list_a)
{
    t_list *head;
    int index;
    int min;
    t_list *temp;

    min = 0;
    index = 0;
    temp = *list_a;
    head = *list_a;
    while (*list_a)
    {

        min = get_min(&head);

        head = temp;
        implant_index(&head, min, index);
        head = temp;
        index++;
        (*list_a) = (*list_a)->next;       
    }
    *list_a = head;
}



int push_swap(int argc, char **argv)
{
    t_list *list_a;
    t_list *list_b;
    t_list *head;

    list_a = NULL;
    list_b = NULL;


    passing_list(&list_a, argc, argv);
    give_index(&list_a);
    head = list_a;
    // while (head)
    // {
    //     printf("content: %d  ", head->content);
    //     printf("index: %d\n", head->index);
    //     head = head->next;
    // }
    list_a = head;
    sorting_algo(&list_a, &list_b);
    return (0);
}


int main(int argc, char **argv)
{
    push_swap(argc, argv);
    
}