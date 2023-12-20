/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_stack_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 12:15:46 by minjacho          #+#    #+#             */
/*   Updated: 2023/12/20 17:20:04 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(char which, t_info *info)
{
	t_stack	*stack;
	int		tmp;

	if (which == 'a')
	{
		write(1, "sa\n", 3);
		stack = info->a;
	}
	else if (which == 'b')
	{
		write(1, "sb\n", 3);
		stack = info->b;
	}
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
		write(1, "pa\n", 3);
		dst = info->a;
		src = info->b;
	}
	else
	{
		write(1, "pb\n", 3);
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

static void	rev_rotate(int reverse, char which, t_info *info)
{
	if (which == 'a')
	{
		write(1, "rra\n", 4);
		if (info->a->top > -1)
			sub_rotate(reverse, info->a);
	}
	else if (which == 'b')
	{
		write(1, "rrb\n", 4);
		if (info->b->top > -1)
			sub_rotate(reverse, info->b);
	}
	else
	{
		write(1, "rrr\n", 4);
		if (info->a->top > -1)
			sub_rotate(reverse, info->a);
		if (info->b->top > -1)
			sub_rotate(reverse, info->b);
	}
}

void	rotate(int reverse, char which, t_info *info)
{
	if (reverse)
	{
		rev_rotate(reverse, which, info);
		return ;
	}
	if (which == 'a')
	{
		write(1, "ra\n", 3);
		if (info->a->top > -1)
			sub_rotate(reverse, info->a);
	}
	else if (which == 'b')
	{
		write(1, "rb\n", 3);
		if (info->b->top > -1)
			sub_rotate(reverse, info->b);
	}
	else
	{
		write(1, "rr\n", 3);
		if (info->a->top > -1)
			sub_rotate(reverse, info->a);
		if (info->b->top > -1)
			sub_rotate(reverse, info->b);
	}
}
