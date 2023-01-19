/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtunderm <dtunderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:25:22 by dtunderm          #+#    #+#             */
/*   Updated: 2023/01/13 15:47:27 by dtunderm         ###   ########.fr       */
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

void	sorting_algo(t_list **list_a, t_list **list_b)
{
	if ((lstsize(*list_a)) < 6)
		ft_smallsort(list_a, list_b);
	else
		ft_major_sort(list_a, list_b);
}

void	ft_smallsort(t_list **list_a, t_list **list_b)
{
	if ((lstsize(*list_a) == 2))
		ft_sort_two(list_a);
	else if ((lstsize(*list_a) == 3))
		ft_sort_three(list_a);
	else if ((lstsize(*list_a) == 4))
		ft_sort_four(list_a, list_b);
	else if ((lstsize(*list_a) == 5))
		ft_sort_five(list_a, list_b);
}

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

	size = lstsize(*list_a);
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

void	ft_major_sort(t_list **list_a, t_list **list_b)
{
	t_list	*head;
	int		max_bits;
	int		i;
	int		j;
	int		size;

	head = *list_a;
	size = lstsize(head);
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
		while (lstsize(*list_b) > 0)
			pa(list_a, list_b);
		i++;
	}
}
