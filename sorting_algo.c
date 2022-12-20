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


void    ft_major_sort(t_list **list_a, t_list **list_b)
{
    
    printf("%d ", (*list_a)->content);
    printf("%d ", (*list_b)->content);


}
