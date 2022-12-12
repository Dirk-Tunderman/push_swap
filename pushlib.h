/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushlib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtunderm <dtunderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:38:49 by dtunderm          #+#    #+#             */
/*   Updated: 2022/12/12 16:06:15 by dtunderm         ###   ########.fr       */
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
    int             content;
    struct s_list   *next;
}               t_list;


int push_swap(int argc, char **argv);
int lstsize(t_list *last);

t_list  *passing_list(t_list **list_a, int argc, char **argv);
t_list  *order_list(t_list **list_a, t_list **list_b);



#endif