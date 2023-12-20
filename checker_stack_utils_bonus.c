/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_stack_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 12:15:46 by minjacho          #+#    #+#             */
/*   Updated: 2023/12/20 15:15:14 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate_swap(int reverse, char which, t_info *info)
{
	rotate(reverse, which, info);
	swap(which, info);
}

void	swap(char which, t_info *info)
{
	t_stack	*stack;
	int		tmp;

	if (which == 'a')
		stack = info->a;
	else if (which == 'b')
		stack = info->b;
	else
	{
		stack = NULL;
		swap('a', info);
		swap('b', info);
		return ;
	}
	if (stack->top < 1)
		return ;
	tmp = stack->arr[stack->top];
	stack->arr[stack->top] = stack->arr[stack->top - 1];
	stack->arr[stack->top - 1] = tmp;
}

void	push(char which, t_info *info)
{
	t_stack	*dst;
	t_stack	*src;

	if (which == 'a')
	{
		dst = info->a;
		src = info->b;
	}
	else
	{
		dst = info->b;
		src = info->a;
	}
	if (src->top < 0)
		return ;
	dst->top++;
	dst->arr[dst->top] = src->arr[src->top--];
}

void	sub_rotate(int reverse, t_stack *stack)
{
	int	tmp;
	int	idx;

	if (!reverse)
	{
		tmp = stack->arr[stack->top];
		idx = stack->top;
		while (idx > 0)
		{
			stack->arr[idx] = stack->arr[idx - 1];
			idx--;
		}
		stack->arr[0] = tmp;
	}
	else
	{
		tmp = stack->arr[0];
		idx = 0;
		while (idx < stack->top)
		{
			stack->arr[idx] = stack->arr[idx + 1];
			idx++;
		}
		stack->arr[idx] = tmp;
	}
}

void	rotate(int reverse, char which, t_info *info)
{
	if (which == 'a')
	{
		if (info->a->top > -1)
			sub_rotate(reverse, info->a);
	}
	else if (which == 'b')
	{
		if (info->b->top > -1)
			sub_rotate(reverse, info->b);
	}
	else
	{
		if (info->a->top > -1)
			sub_rotate(reverse, info->a);
		if (info->b->top > -1)
			sub_rotate(reverse, info->b);
	}
}
