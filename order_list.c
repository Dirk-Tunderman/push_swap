#include "pushlib.h"

t_list  *sort_three(t_list **list_a, t_list **leadnode)
{
    t_list *temp;
    int i = 0;
    int j = 0;
    temp = (*list_a)->next;
    (*list_a) = (*list_a)->next;
    printf("list_a: %d\n", (*list_a)->content);
    printf("list_a: %d\n", (*list_a)->next->content);
    printf("lead: %d\n", (*leadnode)->content);
    printf("temp: %d\n", temp->content);

    while (i < 3)
    {
        printf("list_a before loop: %d\n", (*list_a)->content);
        (*list_a) = (*list_a)->next;
        i++;
    }

    while ((*list_a)->next != (*leadnode))
    {
        printf("testloop");
        if ((*list_a)->content > ((*list_a)->next->content))
        {
            j = (*list_a)->content;
            (*list_a)->content = (*list_a)->next->content;
            (*list_a)->next->content = (*list_a)->next->next->content;
            (*list_a)->next->next->content = j;
        }
        (*list_a) = (*list_a)->next;
    }
    (*list_a) = (*list_a)->next;
    (*list_a) = (*list_a)->next;
    i = 0;
    while (i < 3)
    {
        printf("list_a after loop: %d\n", (*list_a)->content);
        (*list_a) = (*list_a)->next;
        i++;
    }
    printf("list_a after loop: %d\n", (*list_a)->content);



    return (0);
}




t_list  *order_list(t_list **list_a, t_list **list_b)
{
    t_list  *leadnode;
    *list_b = NULL;

    leadnode = malloc(sizeof(t_list));
    leadnode = *list_a;
    printf("content of NN: %d\n", leadnode->content); // is last applied node
    printf("content of list_a: %d\n", (*list_a)->content); // is last applied node
    if (lstsize(leadnode) < 4)
        sort_three(list_a, &leadnode);
     return (*list_a);
}