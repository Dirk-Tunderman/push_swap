/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtunderm <dtunderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:25:41 by dtunderm          #+#    #+#             */
/*   Updated: 2023/01/23 19:13:24 by dtunderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ftprintf/ft_printf.h"

void	free_list(t_list **list_a)
{
	t_list	*temp;

	while (*list_a)
	{
		temp = *list_a;
		(*list_a) = (*list_a)->next;
		free(temp);
	}
}

int	push_swap(int argc, char **argv, t_list **list_a, t_list **list_b)
{
	int		err;
	int		sorted;
	int		fail;

	err = error_check_int(argc, argv);
	if (err == -1)
		return (-1);
	if (argc > 2)
		fail = passing_list(list_a, argc, argv);
	else if (argc == 2)
		fail = passing_list_2(list_a, argv);
	else
		return (-1);
	if (fail == -1)
		return (0);
	err = error_check_double(list_a);
	if (err == -1)
		return (-1);
	give_index(list_a);
	sorted = ft_is_sorted(list_a);
	if (sorted == 0)
		return (0);
	sorting_algo(list_a, list_b);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;
	int		error;

	list_a = NULL;
	list_b = NULL;
	error = push_swap(argc, argv, &list_a, &list_b);
	free_list(&list_a);
	if (error == -1)
		printf("Error\n");
	return (0);
}
