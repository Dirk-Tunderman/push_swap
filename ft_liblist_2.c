/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_liblist_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtunderm <dtunderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:42:44 by dtunderm          #+#    #+#             */
/*   Updated: 2023/01/23 18:06:20 by dtunderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ftprintf/ft_printf.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->index = -1;
	new->content = content;
	return (new);
}

t_list	*ft_lstnew_plus(t_list **list)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->index = (*list)->index;
	new->content = (*list)->content;
	return (new);
}

int	ft_lstadd_back(t_list **list, t_list *new)
{
	t_list	*temp;

	if (new == NULL)
		return (-1);	
	else if (*list)
	{
		temp = ft_lstlast(*list);
		temp->next = new;
	}
	else
		*list = new;
	return (0);
}

t_list	*ft_lstlast(t_list *list)
{
	if (list == NULL)
		return (0);
	while (list)
	{
		if (list->next == NULL)
			return (list);
		list = list->next;
	}
	return (list);
}

int	ft_lstsize(t_list *list)
{
	int	i;

	i = 0;
	while (list != NULL)
	{
		list = list->next;
		i++;
	}
	return (i);
}
