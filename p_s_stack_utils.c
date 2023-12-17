/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_stack_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 12:15:46 by minjacho          #+#    #+#             */
/*   Updated: 2023/12/17 17:41:29 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(char which, t_info *info)
{
	t_stack	*stack;
	int		tmp;

	if (which == 'a')
	{
		ft_printf("sa\n");
		stack = info->a;
	}
	else if (which == 'b')
	{
		ft_printf("sb\n");
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
		ft_printf("pa\n");
		dst = info->a;
		src = info->b;
	}
	else
	{
		ft_printf("pb\n");
		dst = info->b;
		src = info->a;
	}
	if (src->top < 0)
		return ;
	dst->top++;
	dst->arr[dst->top] = src->arr[src->top--];
}

static void	sub_rotate(int reverse, t_stack *stack)
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
	t_stack	*stack;

	if (which == 'a')
	{
		if (reverse)
			ft_printf("r");
		ft_printf("ra\n");
		stack = info->a;
	}
	else if (which == 'b')
	{
		if (reverse)
			ft_printf("r");
		ft_printf("rb\n");
		stack = info->b;
	}
	else
	{
		stack = NULL;
		rotate(reverse, 'a', info);
		rotate(reverse, 'b', info);
	}
	if (stack->top < 1)
		return ;
	sub_rotate(reverse, stack);
}
