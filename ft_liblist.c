#include "pushlib.h"
#include <stdio.h>

t_list	*ft_lstnew(int content)
{
	t_list *rtn;

	rtn = (t_list *)malloc(sizeof(t_list));
	if (!rtn)
		return (rtn = NULL);
	rtn->next = NULL;
	rtn->index = -1;
	rtn->content = content;
	return (rtn);
} 

t_list	*ft_lstnew_plus(t_list **list)
{
	t_list *rtn;

	rtn = (t_list *)malloc(sizeof(t_list));
	if (!rtn)
		return (rtn = NULL);
	rtn->next = NULL;
	rtn->index = (*list)->index;
	rtn->content = (*list)->content;
	return (rtn);
} 

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *temp;

	if (*lst)
	{
		temp = ft_lstlast(*lst);
		temp->next = new;
	}
	else
		*lst = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (0);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

int lstsize(t_list *lst)
{
    int i;

    i = 0;
    while (lst != NULL)
    {
        lst = lst->next;
        i++;
    }
    return (i);
}

int	ft_largest(t_list **list)
{
	int largest;
	t_list *head;

	head = *list;
	largest = 0;
	while (*list)
	{
		if ((*list)->content > largest)
			largest = (*list)->content;
		(*list) = (*list)->next;
	}
	*list = head;
	return (largest);
}

int ft_largest_index(t_list **list_a)
{
	int max;
	int index;

	index = 0;
	max = ft_largest(list_a);
	while ((*list_a)->content != max)
		(*list_a) = (*list_a)->next;
	index = (*list_a)->index;
	return (index);
}
