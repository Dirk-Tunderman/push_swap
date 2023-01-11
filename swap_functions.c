#include "pushlib.h"

void    sa(t_list **list_a) // swap eerste 2 van stack a werkt.
{
    int temp;

    temp = 0;
    temp = (*list_a)->content;
    (*list_a)->content = (*list_a)->next->content;
    (*list_a)->next->content = temp;
    ft_print("sa\n");
}

void    sb(t_list **list_b) // swap eerste 2 van stack b wrkt.
{
    int temp;

    temp = 0;
    temp = (*list_b)->content;
    (*list_b)->content = (*list_b)->next->content;
    (*list_b)->next->content = temp;
    ft_print("sb\n");

}

void    ss(t_list **list_a, t_list **list_b) // swap eerste 2 a en  b tegelijk. werkt.
{
    int temp;

    temp = (*list_a)->content;
    (*list_a)->content = (*list_a)->next->content;
    (*list_a)->next->content = temp;


    temp = (*list_b)->content;
    (*list_b)->content = (*list_b)->next->content;
    (*list_b)->next->content = temp;
    ft_print("ss\n");
}

void    pa(t_list **list_a, t_list **list_b) // neem de eerste van b en stop het in de top van a
{
    t_list *head_a;
    t_list *head_b;
    t_list *temp;

    head_a = *list_a;
    head_b = *list_b;
    temp = *list_b;
    *list_b = head_b->next;
    if (!(*list_a))
    {
        head_a = temp;
        head_a->next = NULL;
        *list_a = head_a;
    }
    else
    {
        temp->next = head_a;
        (*list_a) = temp;
    }
    ft_print("pa\n");
}

void    pb(t_list **list_a, t_list **list_b) // neem de eerste van a en stop het in de top van b
{
    t_list *head_a;
    t_list *head_b;
    t_list *temp;

    head_a = *list_a;
    head_b = *list_b;
    temp = *list_a;
    *list_a = head_a->next;
    if (!(*list_b))
    {
        head_b = temp;
        head_b->next = NULL;
        *list_b = head_b;
    }
    else
    {
        temp->next = head_b;
        (*list_b) = temp;
    }
    ft_print("pb\n");
}

void    ra(t_list **list_a) //schuif alle van a een naar boven, werkt.
{
    t_list  *last;
    t_list  *head_a;

    head_a = (*list_a)->next;
    last = ft_lstlast(*list_a);
    last->next = *list_a;
    (*list_a)->next = NULL;
    (*list_a) = head_a;

    ft_print("ra\n");
}

void    rb(t_list **list_b) //schuif alle van a een naar boven, werkt.
{
    t_list  *last;
    t_list  *head_b;

    head_b = (*list_b)->next;
    last = ft_lstlast(*list_b);
    last->next = *list_b;
    (*list_b)->next = NULL;
    (*list_b) = head_b;
    ft_print("rb\n");
}

void    rr(t_list **list_b, t_list **list_a) //schuif alle van a een naar boven, werkt.
{
    t_list  *last;
    t_list  *head;

    head = (*list_a)->next;
    last = ft_lstlast(*list_a);
    last->next = *list_a;
    (*list_a)->next = NULL;
    (*list_a) = head;

    head = (*list_b)->next;
    last = ft_lstlast(*list_b);
    last->next = *list_b;
    (*list_b)->next = NULL;
    (*list_b) = head;
    ft_print("rr\n");
}

void    rra(t_list **list_a)
{
    t_list *last;
    t_list *head_a;

    head_a = *list_a;
    last = ft_lstlast(head_a);
    while (head_a)
    {
        if (head_a->next->next == NULL)
            head_a->next = NULL;
        head_a = head_a->next;
    }
    last->next = (*list_a);
    (*list_a) = last;
    ft_print("rra\n");
}

void    rrb(t_list **list_b)
{
    t_list *last;
    t_list *head_b;

    head_b = *list_b;
    last = ft_lstlast(head_b);
    while (head_b)
    {
        if (head_b->next->next == NULL)
            head_b->next = NULL;
        head_b = head_b->next;
    }
    last->next = (*list_b);
    (*list_b) = last;
    ft_print("rrb\n");
}

void    rrr(t_list **list_a, t_list **list_b)
{
    t_list *last;
    t_list *head;

    head = *list_a;
    last = ft_lstlast(head);
    while (head)
    {
        if (head->next->next == NULL)
            head->next = NULL;
        head = head->next;
    }
    last->next = (*list_a);
    (*list_a) = last;

    head = *list_b;
    last = ft_lstlast(head);
    while (head)
    {
        if (head->next->next == NULL)
            head->next = NULL;
        head = head->next;
    }
    last->next = (*list_b);
    (*list_b) = last;
    ft_print("rrr\n");
}