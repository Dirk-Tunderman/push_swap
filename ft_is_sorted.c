/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtunderm <dtunderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:16:57 by dtunderm          #+#    #+#             */
/*   Updated: 2023/01/19 15:36:36 by dtunderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ftprintf/ft_printf.h"

int	ft_is_sorted(t_list **list_a)
{
	t_list *head;
	int		i;
	
	head = *list_a;
	i = -1;
	while (*list_a)
	{
		if ((*list_a)->index > i)
		{
			i = (*list_a)->index;
			(*list_a) = (*list_a)->next;
		}
		else
		{
			(*list_a) = head;
			return (1);
		}
	}
	*list_a = head;
	return (0);
}