/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_preprocess.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 12:18:34 by minjacho          #+#    #+#             */
/*   Updated: 2023/12/18 19:29:51 by minjacho         ###   ########.fr       */
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

void	get_ra_cnt(t_info *info, t_greedy *cur, int num)
{
	int	idx;
	int	prev_num;
	int ra;
	int rra;

	idx = info->a->top;
	while (idx >= 0)
	{
		if (idx == info->a->top)
			prev_num = info->a->arr[0];
		if ((num < info->a->arr[idx] && num > prev_num) || \
			(prev_num > info->a->arr[idx] && (num > prev_num || num < info->a->arr[idx])))
			break;
		prev_num = info->a->arr[idx];
		idx--;
	}
	ra = info->a->top - idx;
	rra = idx + 1;
	if (ra > rra)
		cur->a_rotate = -rra;
	else
		cur->a_rotate = ra;

}

int	calc_op_cnt(t_greedy op)
{
	int	sum;

	sum = 0;
	if (op.a_rotate < 0)
		sum -= op.a_rotate;
	else
		sum += op.a_rotate;
	if (op.b_rotate < 0)
		sum -= op.b_rotate;
	else
		sum += op.b_rotate;
	return (sum);
}

void	compare_op_cnt(t_greedy *best, t_greedy *cur, int is_not_fst)
{
	int	cur_cnt;

	cur_cnt = calc_op_cnt(*cur);
	if (!is_not_fst || calc_op_cnt(*best) > cur_cnt)
	{
		best->a_rotate = cur->a_rotate;
		best->b_rotate = cur->b_rotate;
		return ;
	}
}

void	do_op(t_info *info, t_greedy best)
{
	int	ra;
	int	rb;

	ra = best.a_rotate;
	rb = best.b_rotate;
	while (ra > 0)
	{
		rotate(0, 'a', info);
		ra--;
	}
	while (ra < 0)
	{
		rotate(1, 'a', info);
		ra++;
	}
	while (rb > 0)
	{
		rotate(0, 'b', info);
		rb--;
	}
	while (rb < 0)
	{
		rotate(1, 'b', info);
		rb++;
	}
	push('a', info);
}

void	greedy(t_info *info)
{
	int			idx;
	t_greedy	best;
	t_greedy	cur;

	idx = info->b->top;
	while (idx >= 0)
	{
		// ft_printf("%d\n", idx);
		if (info->b->top - idx > idx + 1)
			cur.b_rotate = - (idx + 1);
		else
			cur.b_rotate = info->b->top - idx;
		get_ra_cnt(info, &cur, info->b->arr[idx]);
		compare_op_cnt(&best, &cur, info->b->top - idx);
		idx--;
	}
	do_op(info, best);
}
