/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtunderm <dtunderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:37:48 by dtunderm          #+#    #+#             */
/*   Updated: 2023/01/23 15:50:31 by dtunderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ftprintf/ft_printf.h"

void	ra(t_list **list_a)
{
	t_list	*last;
	t_list	*head_a;

	head_a = (*list_a)->next;
	last = ft_lstlast(*list_a);
	last->next = *list_a;
	(*list_a)->next = NULL;
	(*list_a) = head_a;
	ft_printf("ra\n");
}

void	rb(t_list **list_b)
{
	t_list	*last;
	t_list	*head_b;

	head_b = (*list_b)->next;
	last = ft_lstlast(*list_b);
	last->next = *list_b;
	(*list_b)->next = NULL;
	(*list_b) = head_b;
	ft_printf("rb\n");
}

void	rr(t_list **list_b, t_list **list_a)
{
	t_list	*last;
	t_list	*head;

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
	ft_printf("rr\n");
}

void	rra(t_list **list_a)
{
	t_list	*last;
	t_list	*head_a;

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
	ft_printf("rra\n");
}

void	rrb(t_list **list_b)
{
	t_list	*last;
	t_list	*head_b;

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
	ft_printf("rrb\n");
}
