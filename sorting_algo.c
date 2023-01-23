/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtunderm <dtunderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:25:22 by dtunderm          #+#    #+#             */
/*   Updated: 2023/01/23 16:39:31 by dtunderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ftprintf/ft_printf.h"

int	find_len_num(t_list **list_a)
{
	int	i;
	int	big_num;
	int	len_num;

	i = 0;
	while (i < ft_lstsize(*list_a))
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

void	sorting_algo(t_list **list_a, t_list **list_b)
{
	int	size;

	size = ft_lstsize(*list_a);
	if ((ft_lstsize(*list_a)) < 6)
		ft_smallsort(list_a, list_b);
	else
		ft_major_sort(list_a, list_b, size);
}

void	ft_smallsort(t_list **list_a, t_list **list_b)
{
	if ((ft_lstsize(*list_a) == 2))
		ft_sort_two(list_a);
	else if ((ft_lstsize(*list_a) == 3))
		ft_sort_three(list_a);
	else if ((ft_lstsize(*list_a) == 4))
		ft_sort_four(list_a, list_b);
	else if ((ft_lstsize(*list_a) == 5))
		ft_sort_five(list_a, list_b);
}

int	get_max_bits(t_list **list_a)
{
	int	max_index;
	int	i;

	max_index = ft_largest_index(list_a);
	i = 0;
	while (max_index > 0)
	{
		max_index = max_index / 2;
		i++;
	}
	return (i);
}

void	ft_major_sort(t_list **list_a, t_list **list_b, int size)
{
	t_list	*head;
	int		max_bits;
	int		i;
	int		j;

	head = *list_a;
	j = 0;
	i = 0;
	max_bits = get_max_bits(&head);
	head = *list_a;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*list_a)->index >> i) & 1) == 1)
				ra(list_a);
			else
				pb(list_a, list_b);
			j++;
		}
		while (ft_lstsize(*list_b) > 0)
			pa(list_a, list_b);
		i++;
	}
}
