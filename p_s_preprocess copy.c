/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_preprocess copy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 12:18:34 by minjacho          #+#    #+#             */
/*   Updated: 2023/12/18 19:14:41 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide_pivot(t_info *info)
{
	int	idx;
	int	peek;

	idx = 0;
	while (idx < info->size)
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
	while (info->a->top > -1)
		push('b', info);
}

void	get_ra_cnt(t_info *info, t_greedy *cur, int num)
{
	int	idx;

	idx = info->a->top;
	// ft_printf("%d top\n", idx);
	while (idx >= 0)
	{
		if (info->a->arr[idx] > num)
			break;
		idx--;
	}
	cur->ra1 = info->a->top - idx;
	cur->rra1 = idx + 1;
	cur->ra2 = cur->rra1 + 1;
	cur->rra2 = cur->ra1;
}

void	filter_op_cnt(t_greedy *ops, int idx)
{
	if (idx == 0)
	{
		ops->rra1 = -1;
		ops->rrb1 = -1;
		ops->ra2 = -1;
	}
	if (idx == 1)
	{
		ops->rra1 = -1;
		ops->rb1 = -1;
		ops->ra2 = -1;
	}
	if (idx == 2)
	{
		ops->ra1 = -1;
		ops->rrb1 = -1;
		ops->rra2 = -1;
	}
	if (idx == 3)
	{
		ops->ra1 = -1;
		ops->rb1 = -1;
		ops->rra2 = -1;
	}
}

int	calc_op_cnt(t_greedy *ops)
{
	int	op[2][2];
	int	idx;
	int	min[2];

	op[0][1] = ops->ra1 + ops->rrb1 + ops->rra2;
	op[1][0] = ops->rra1 + ops->rb1 + ops->ra2;
	if (ops->ra1 > ops->rb1)
		op[0][0] = ops->ra1 + ops->rra2;
	else
		op[0][0] = ops->rb1 +ops->rra2;
	if (ops->rra1 > ops->rrb1)
		op[1][1] = ops->rra1 + ops->ra2;
	else
		op[1][1] = ops->rrb1 + ops->ra2;
	idx = -1;
	while (++idx < 4)
	{
		if (idx == 0 || min[0] > op[idx / 2][idx % 2])
		{
			min[0] = op[idx / 2][idx % 2];
			min[1] = idx;
		}
	}
	filter_op_cnt(ops, min[1]);
	return (min[0]);
}

int	calc_best_op_cnt(t_greedy best)
{
	int	best_cnt;

	best_cnt = 0;
	if (best.ra1 > 0)
		best_cnt += best.ra1;
	else
		best_cnt += best.rra1;
	if (best.rb1 > 0)
		best_cnt += best.rb1;
	else
		best_cnt += best.rrb1;
	if (best.ra2 > 0)
		best_cnt += best.ra2;
	else
		best_cnt += best.rra2;
	return (best_cnt);
}

void	compare_op_cnt(t_greedy *best, t_greedy *cur, int is_not_fst)
{
	int	cur_cnt;

	cur_cnt = calc_op_cnt(cur);
	if (!is_not_fst || calc_best_op_cnt(*best) > cur_cnt)
	{
		best->ra1 = cur->ra1;
		best->rra1 = cur->rra1;
		best->rb1 = cur->rb1;
		best->rrb1 = cur->rrb1;
		best->ra2 = cur->ra2;
		best->rra2 = cur->rra2;
		return ;
	}
}

void	do_op(t_info *info, t_greedy best)
{
	int	idx;

	if (best.ra1 > 0)
	{
		idx = -1;
		while (++idx < best.ra1)
			rotate(0, 'a', info);
	}
	else if(best.rra1 > 0)
	{
		idx = -1;
		while (++idx < best.rra1)
			rotate(1, 'a', info);
	}
	if (best.rb1 > 0)
	{
		idx = -1;
		while (++idx < best.rb1)
			rotate(0, 'b', info);
	}
	else if(best.rrb1 > 0)
	{
		idx = -1;
		while (++idx < best.rrb1)
			rotate(1, 'b', info);
	}
	push('a', info);
}

void	greedy(t_info *info)
{
	int			idx;
	t_greedy	best;
	t_greedy	cur;

	idx = info->b->top;
	while (info->b->top > -1)
	{
		while (idx >= 0)
		{
			// ft_printf("%d\n", idx);
			cur.rb1 = info->b->top - idx;
			cur.rrb1 = idx + 1;
			get_ra_cnt(info, &cur, info->b->arr[idx]);
			compare_op_cnt(&best, &cur, info->b->top - idx);
			idx--;
		}
	}
	do_op(info, best);
}
