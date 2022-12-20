#include "pushlib.h"
#include <stdio.h>

t_list	*ft_lstnew(int content)
{
	t_list *rtn;

	rtn = (t_list *)malloc(sizeof(t_list));
	if (!rtn)
		return (rtn = NULL);
	rtn->next = NULL;
	rtn->index = 0;
	rtn->content = content;
	return (rtn);
} 

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *t;

	if (*alst)
	{
		t = ft_lstlast(*alst);
		t->next = new;
	}
	else
		*alst = new;
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

	largest = 0;
	while (*list)
	{
		if ((*list)->content > largest)
			largest = (*list)->content;
		(*list) = (*list)->next;
	}
	return (largest);
}