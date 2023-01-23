/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_little.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtunderm <dtunderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:40:20 by dtunderm          #+#    #+#             */
/*   Updated: 2023/01/23 16:36:58 by dtunderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ftprintf/ft_printf.h"

void	ft_sort_two(t_list **list_a)
{
	if ((*list_a)->content > (*list_a)->next->content)
		sa(list_a);
	else
		return ;
}

void	ft_sort_three(t_list **list_a)
{
	if ((*list_a)->content > (*list_a)->next->content)
	{
		if ((*list_a)->next->content > (*list_a)->next->next->content)
		{
			ra(list_a);
			sa(list_a);
		}
		else if ((*list_a)->content < (*list_a)->next->next->content)
			sa(list_a);
		else
			ra(list_a);
	}
	else if ((*list_a)->content < (*list_a)->next->content)
	{
		if ((*list_a)->next->content < (*list_a)->next->next->content)
			return ;
		else if ((*list_a)->content > (*list_a)->next->next->content)
			rra(list_a);
		else
		{
			rra(list_a);
			sa(list_a);
		}
	}
}

int	find_first(t_list **list_a)
{
	t_list	*head;
	int		i;

	head = *list_a;
	i = 0;
	while (*list_a)
	{
		if ((*list_a)->index == 1)
			break ;
		*list_a = (*list_a)->next;
		i++;
	}
	*list_a = head;
	return (i);
}

void	ft_sort_four(t_list **list_a, t_list **list_b)
{
	int	i;

	i = find_first(list_a);
	if (i == 1)
		ra(list_a);
	else if (i == 2)
	{
		rra(list_a);
		rra(list_a);
	}
	else if (i == 3)
		rra(list_a);
	pb(list_a, list_b);
	ft_sort_three(list_a);
	pa(list_a, list_b);
}

void	ft_sort_five(t_list **list_a, t_list **list_b)
{
	int	i;
	int	size;

	size = ft_lstsize(*list_a);
	i = 0;
	while (i < size)
	{
		if ((*list_a)->index == 1 || (*list_a)->index == 2)
			pb(list_a, list_b);
		else
			ra(list_a);
		i++;
	}
	if ((*list_b)->index < (*list_b)->next->index)
		rb(list_b);
	ft_sort_three(list_a);
	while (*list_b)
		pa(list_a, list_b);
}
