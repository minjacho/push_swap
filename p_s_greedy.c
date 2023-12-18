/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_greedy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:08:31 by minjacho          #+#    #+#             */
/*   Updated: 2023/12/18 20:24:19 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_ra_cnt(t_info *info, t_greedy *cur, int num)
{
	int	idx;
	int	prev_num;
	int	ra;
	int	rra;

	idx = info->a->top;
	while (idx >= 0)
	{
		if (idx == info->a->top)
			prev_num = info->a->arr[0];
		if ((num < info->a->arr[idx] && num > prev_num) || \
				(prev_num > info->a->arr[idx] && \
					(num > prev_num || num < info->a->arr[idx])))
			break ;
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

void	do_op(t_info *info, t_greedy *best)
{
	rotate_paral(info, best);
	while (best->a_rotate > 0)
	{
		rotate(0, 'a', info);
		best->a_rotate--;
	}
	while (best->a_rotate < 0)
	{
		rotate(1, 'a', info);
		best->a_rotate++;
	}
	while (best->b_rotate > 0)
	{
		rotate(0, 'b', info);
		best->b_rotate--;
	}
	while (best->b_rotate < 0)
	{
		rotate(1, 'b', info);
		best->b_rotate++;
	}
}

void	greedy(t_info *info)
{
	int			idx;
	t_greedy	best;
	t_greedy	cur;

	idx = info->b->top;
	while (idx >= 0)
	{
		if (info->b->top - idx > idx + 1)
			cur.b_rotate = - (idx + 1);
		else
			cur.b_rotate = info->b->top - idx;
		get_ra_cnt(info, &cur, info->b->arr[idx]);
		compare_op_cnt(&best, &cur, info->b->top - idx);
		idx--;
	}
	do_op(info, &best);
	push('a', info);
}
