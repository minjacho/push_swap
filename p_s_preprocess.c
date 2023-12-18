/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_preprocess.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 12:18:34 by minjacho          #+#    #+#             */
/*   Updated: 2023/12/18 20:09:00 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_info *info, t_stack *stack, char which)
{
	if (stack->arr[1] > stack->arr[2])
	{
		if (stack->arr[1] > stack->arr[0])
		{
			if (stack->arr[2] < stack->arr[0])
				rotate_swap(1, which, info);
			else
				rotate(1, which, info);
		}
	}
	else
	{
		if (stack->arr[2] < stack->arr[0])
			swap(which, info);
		else
		{
			if (stack->arr[1] > stack->arr[0])
				rotate_swap(0, which, info);
			else
				rotate(0, which, info);
		}
	}
}

void	divide_pivot(t_info *info)
{
	int	idx;
	int	peek;

	idx = 0;
	while (idx < info->size && info->a->top > 2)
	{
		peek = info->a->arr[info->a->top];
		if (peek > info->pivot2)
			rotate(0, 'a', info);
		else if (peek > info->pivot1)
			push('b', info);
		else
		{
			push('b', info);
			rotate(0, 'b', info);
		}
		idx++;
	}
	while (info->a->top > 2)
		push('b', info);
	sort_three(info, info->a, 'a');
}
