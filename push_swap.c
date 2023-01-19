/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtunderm <dtunderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:25:41 by dtunderm          #+#    #+#             */
/*   Updated: 2023/01/19 15:36:50 by dtunderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ftprintf/ft_printf.h"

void	passing_list(t_list **list, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ft_lstadd_back(list, ft_lstnew(atoi(argv[i])));
		i++;
	}
}

void	passing_list_2(t_list **list, char **argv)
{
	int		i;
	int		num;
	char	c;

	i = 0;
	num = 0;
	while (argv[1][i] != '\0')
	{
		num = 0;
		while (argv[1][i] != ' ' && argv[1][i] != '\0')
		{
			c = argv[1][i];
			num = (num * 10) + atoi(&c);
			i++;
		}
		ft_lstadd_back(list, ft_lstnew(num));
		if (argv[1][i] == '\0')
			break ;
		i++;
	}
}

int	get_min(t_list **list_a)
{
	t_list	*head;
	int		min;

	head = *list_a;
	min = ft_largest(list_a);
	*list_a = head;
	while (head)
	{
		if (min > head->content && head->index == -1)
			min = head->content;
		head = head->next;
	}
	return (min);
}

void	implant_index(t_list **list_a, int min, int index)
{
	while (*list_a)
	{
		if ((*list_a)->content == min)
			(*list_a)->index = index;
		(*list_a) = (*list_a)->next;
	}
}

void	give_index(t_list **list_a)
{
	t_list	*temp;
	t_list	*head;
	int		index;
	int		min;

	min = 0;
	index = 1;
	temp = *list_a;
	head = *list_a;
	while (*list_a)
	{
		min = get_min(&head);
		head = temp;
		implant_index(&head, min, index);
		head = temp;
		index++;
		(*list_a) = (*list_a)->next;
	}
	*list_a = head;
}

int	push_swap(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;
	int		err;
	int		sorted;

	list_a = NULL;
	list_b = NULL;
	err = error_check_int(argc, argv);
	if (err == -1)
		return (-1);
	if (argc > 2)
		passing_list(&list_a, argc, argv);
	else if (argc == 2)
		passing_list_2(&list_a, argv);
	else
		return (-1);
	err = error_check_double(&list_a);
	if (err == -1)
		return (-1);
	give_index(&list_a);
	sorted = ft_is_sorted(&list_a);
	if (sorted == 0)
		return (0);
	sorting_algo(&list_a, &list_b);
	return (0);
}

int	main(int argc, char **argv)
{
	int	error;

	error = push_swap(argc, argv);
	if (error == -1)
		printf("Error\n");
	return (0);
}
