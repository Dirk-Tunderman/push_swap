/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtunderm <dtunderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:25:15 by dtunderm          #+#    #+#             */
/*   Updated: 2023/01/23 16:39:19 by dtunderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ftprintf/ft_printf.h"

void	sa(t_list **list_a)
{
	int	temp;

	temp = 0;
	temp = (*list_a)->content;
	(*list_a)->content = (*list_a)->next->content;
	(*list_a)->next->content = temp;
	ft_printf("sa\n");
}

void	sb(t_list **list_b)
{
	int	temp;

	temp = 0;
	temp = (*list_b)->content;
	(*list_b)->content = (*list_b)->next->content;
	(*list_b)->next->content = temp;
	ft_printf("sb\n");
}

void	ss(t_list **list_a, t_list **list_b)
{
	int	temp;

	temp = (*list_a)->content;
	(*list_a)->content = (*list_a)->next->content;
	(*list_a)->next->content = temp;
	temp = (*list_b)->content;
	(*list_b)->content = (*list_b)->next->content;
	(*list_b)->next->content = temp;
	ft_printf("ss\n");
}

void	pa(t_list **list_a, t_list **list_b)
{
	t_list	*head_a;
	t_list	*head_b;
	t_list	*temp;

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
	ft_printf("pa\n");
}

void	pb(t_list **list_a, t_list **list_b)
{
	t_list	*head_a;
	t_list	*head_b;
	t_list	*temp;

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
	ft_printf("pb\n");
}
