/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtunderm <dtunderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:25:12 by dtunderm          #+#    #+#             */
/*   Updated: 2023/01/23 15:44:46 by dtunderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ftprintf/ft_printf.h"

int	error_check_int(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if ((argv[i][j] > 47 && argv[i][j] < 58) || argv[i][j] == 32)
				j++;
			else
				return (-1);
		}
		i++;
	}
	return (1);
}

int	error_check_double(t_list **list_a)
{
	t_list	*head;
	t_list	*temp;
	int		count;

	head = *list_a;
	temp = *list_a;
	count = 0;
	while (*list_a)
	{
		temp = head;
		count = 0;
		while (temp)
		{
			if (temp->content == (*list_a)->content)
			{
				count++;
				if (count > 1)
					return (-1);
			}
			temp = temp->next;
		}
		*list_a = (*list_a)->next;
	}
	*list_a = head;
	return (1);
}

int	ft_is_sorted(t_list **list_a)
{
	t_list	*head;
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
