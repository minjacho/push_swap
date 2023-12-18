/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:08:44 by minjacho          #+#    #+#             */
/*   Updated: 2023/12/18 19:08:23 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"

typedef struct	s_op
{
	char		*str;
	struct s_op	*next;
}	t_op;

typedef struct	s_stack
{
	int	*arr;
	int	size;
	int	top;
}	t_stack;

typedef struct	s_info
{
	t_stack	*a;
	t_stack	*b;
	int		*origin;
	int		pivot1;
	int		pivot2;
	int		min;
	int		max;
	int		size;
	t_list	*op_list;
}	t_info;

typedef struct s_greedy
{
	int	a_rotate;
	int b_rotate;
	int	sum;
}	t_greedy;

void	free_triple_ptr(char ***ptr, int size);
void	free_double_ptr(char **lists);

void	init_origin(int argc, char *argv[], t_info *info);
void	init_stack(t_info *info);

void	swap(char which, t_info *info);
void	push(char which, t_info *info);
void	rotate(int reverse, char which, t_info *info);
void	rotate_swap(int reverse, char which, t_info *info);

void	print_stack(t_info *info);

void	divide_pivot(t_info *info);
void	greedy(t_info *info);
#endif
