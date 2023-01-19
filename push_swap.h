/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtunderm <dtunderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:45:53 by dtunderm          #+#    #+#             */
/*   Updated: 2023/01/19 15:25:35 by dtunderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct  s_list
{
    int					content;
    int					index;
    struct s_list		*next;
}						t_list;

int			push_swap(int argc, char **argv);
int			lstsize(t_list *last);
int			ft_largest(t_list **list);
int			ft_largest_index(t_list **list_a);
int			error_check_int(int argc, char **argv);
int			error_check_double(t_list **list_a);
int	        ft_is_sorted(t_list **list_a);

t_list		*ft_lstnew(int content);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew_plus(t_list **list);

void		give_index(t_list **list_a);
void		passing_list(t_list **list, int argc, char **argv);
void		ft_lstadd_back(t_list **alst, t_list *new);
void		sorting_algo(t_list **list_a, t_list **list_b);
void		sa(t_list **list_a);
void		sb(t_list **list_b);
void		ss(t_list **list_a, t_list **list_b);
void		pa(t_list **list_a, t_list **list_b);
void		pb(t_list **list_a, t_list **list_b);
void		ra(t_list **list_a);
void		rb(t_list **list_b);
void		rra(t_list **list_a);
void		rrb(t_list **list_b);
void		rrr(t_list **list_a, t_list **list_b);
void		ft_smallsort(t_list **list_a, t_list **list_b);
void		ft_sort_two(t_list **list_a);
void		ft_major_sort(t_list **list_a, t_list **list_b);
void		ft_sort_three(t_list **list_a);
void		ft_sort_four(t_list **list_a, t_list **list_b);
void		ft_sort_five(t_list **list_a, t_list **list_b);
void		give_index(t_list **list_a);

#endif