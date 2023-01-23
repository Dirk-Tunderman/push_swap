/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_liblist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtunderm <dtunderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:25:32 by dtunderm          #+#    #+#             */
/*   Updated: 2023/01/23 17:31:32 by dtunderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ftprintf/ft_printf.h"

int	ft_largest(t_list **list)
{
	int		largest;
	t_list	*head;

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

int	ft_largest_index(t_list **list_a)
{
	int	max;
	int	index;

	index = 0;
	max = ft_largest(list_a);
	while ((*list_a)->content != max)
		(*list_a) = (*list_a)->next;
	index = (*list_a)->index;
	return (index);
}
