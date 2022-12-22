#include "pushlib.h"

int  find_len_num(t_list **list_a)
{
    int i;
    int big_num;
    int len_num;

    i = 0;
    while (i < lstsize(*list_a))
    {
        if ((*list_a)->content > big_num)
            big_num = (*list_a)->content;
        *list_a = (*list_a)->next;
    }
    len_num = 0;
    while (big_num > 0)
    {
        big_num = big_num / 10;
        len_num++;
    }
    return (len_num);
}

void        sorting_algo(t_list **list_a, t_list **list_b)
{
    if ((lstsize(*list_a)) < 6)
        ft_smallsort(list_a, list_b);
    else
        ft_major_sort(list_a, list_b);
}

void    ft_smallsort(t_list **list_a, t_list **list_b)
{
    if ((lstsize(*list_a) == 2))
        ft_sort_two(list_a);
    else if((lstsize(*list_a) == 3))
        ft_sort_three(list_a);
    else if((lstsize(*list_a) == 4))
        ft_sort_four(list_a, list_b);
    else if ((lstsize(*list_a) == 5))
        ft_sort_five(list_a, list_b);
}

void    ft_sort_two(t_list **list_a)
{
    if ((*list_a)->content > (*list_a)->next->content)
        sa(list_a);
    else
        return ;
}

void    ft_sort_three(t_list **list_a)
{
    if ((*list_a)->content > (*list_a)->next->content) 
    {
        if ((*list_a)->next->content > (*list_a)->next->next->content) // 3 2 1
        {
            ra(list_a);
            sa(list_a);
        }
        else if ((*list_a)->content < (*list_a)->next->next->content) // 2 1 3
            sa(list_a);
        else                                                          // 3 1 2
            ra(list_a);
    }
    else if ((*list_a)->content < (*list_a)->next->content)
    {
        if ((*list_a)->next->content < (*list_a)->next->next->content) // 1 2 3
            return ;
        else if ((*list_a)->content > (*list_a)->next->next->content) // 2 3 1
            rra(list_a);
        else                                                         // 1 3 2
        {
            rra(list_a);
            sa(list_a);
        }
    }
}

void    ft_sort_five(t_list **list_a, t_list **list_b)
{
    printf("goed into 5 major:%p%p\n\n\n", *list_a, *list_b);
}

void    ft_sort_four(t_list **list_a, t_list **list_b)
{
    printf("%p%p\n\n\n\n\n", *list_a, *list_b);
}


int get_max_bits(t_list **list_a)
{
    int max_index;
    int i;

    max_index = ft_largest_index(list_a);
    //printf("max is: %d\n", max_index);
    i = 0;
    while (max_index > 0)
    {
        max_index = max_index / 2;
        i++;
    }

    return (i);
}

void    ft_major_sort(t_list **list_a, t_list **list_b)
{
    
    int max_bits;
    int i;
    int j;
    t_list *head;
    int size;

    head = *list_a;
    size = lstsize(head);
    j = 0;
    i = 0;
    max_bits = get_max_bits(&head);
   // printf("list_a pointer at: %d\n", (*list_a)->index);
    head = *list_a;
    while (i < max_bits)
    {
        //*list_a = head;
        j = 0;
        while (j < size)
        {
            //printf("komt to hier\n");
            //*list_a = head;
            if ((((*list_a)->index >> i) & 1) == 1)
            {
                //printf("list_a: %d\n", (*list_a)->index);
                ra(list_a);
                //printf("list_b: %d\n", (*list_b)->index);  
            }
            else
            {
                //printf("list_a to b: %d\n", (*list_a)->index);
                pb(list_a, list_b);
            }
            j++;
        }
        while (lstsize(*list_b) > 0)
        {
            pa(list_a, list_b);
            //printf("list_a in second loop: %d\n", (*list_a)->index);
        }
       // printf("list_a at the eeeend: %d\n", (*list_a)->index);
        i++;
    }
   // *list_a = head;

    while (*list_a)
    {
        printf("list_a end: %d\n", (*list_a)->index);
        (*list_a) = (*list_a)->next;
    }
    while (*list_b)
    {
        printf("list_b end: %d\n", (*list_b)->index);
        (*list_b) = (*list_b)->next;
    }
}
