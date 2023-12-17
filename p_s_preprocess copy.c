/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_preprocess.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 12:18:34 by minjacho          #+#    #+#             */
/*   Updated: 2023/12/17 21:03:13 by minjacho         ###   ########.fr       */
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

void	get_index_of_a(t_stack *a, int num, int *op_list)
{
	int	idx;

	idx = a->top + 1;
	while (--idx >= 0)
		if (a->arr[idx] > num)
			break;
	if (a->top - idx <= idx + 1)
	{
		op_list[0] = a->top - idx;
		op_list[1] = -1;
		op_list[2] = -1;
		op_list[3] = a->top - idx;
	}
	else
	{
		op_list[0] = -1;
		op_list[1] = idx + 1;
		op_list[2] = idx + 1;
		op_list[3] = -1;
		if (idx + 1 == 0)
			op_list[2] = 1;
	}
}

void	backup_int_arr(int **dst, int **src, int size)
{
	int	idx;

	idx = 0;
	while (idx < size)
	{
		(*dst)[idx] = (*src)[idx];
		idx++;
	}
}

void	filter_op_list(int **op_list)
{
	int	sum;
	int	rb_cnt;
	int	rrb_cnt;

	sum = 0;
	rb_cnt = (*op_list)[0];
	rrb_cnt = (*op_list)[1];
	if ((*op_list)[2] < 0)
	{
		sum = (*op_list)[3];
		rb_cnt += (*op_list)[3];
		if (rrb_cnt < (*op_list)[3])
			rrb_cnt = (*op_list)[3];
	}
	else
	{
		sum = (*op_list)[2];
		rrb_cnt += (*op_list)[2];
		if (rb_cnt < (*op_list)[2])
			rb_cnt = (*op_list)[2];
	}
	if (rb_cnt > rrb_cnt)
		(*op_list)[0] = -1;
	else
		(*op_list)[1] = -1;
}

void	compare_op_list(int **before, int **current)
{
	int	before_cnt;
	int	cur_cnt;
	int	idx;

	before_cnt = 0;
	cur_cnt = 0;
	filter_op_list(current);
	if ((*before)[0] < 0 && (*before)[1] < 0)
		backup_int_arr(before, current, 6);
	idx = 0;
	while (idx < 6)
	{
		if ((*before)[idx] > 0)
			before_cnt += (*before)[idx];
		if ((*current)[idx] > 0)
			cur_cnt += (*current)[idx];
		idx++;
	}
	if (cur_cnt < before_cnt)
		backup_int_arr(before, current, 6);
}

void	greedy(t_info *info)
{
	int	idx;
	int	*before_op_list = (int *)malloc(sizeof(int) * 6);
	int	*op_list = (int *)malloc(sizeof(int) * 6); //rb, rrb, ra, rra, |pa| rra, ra

	while (info->b->top > -1)
	{
		idx = info->b->top;
		while(idx > -1)
		{
			op_list[0] = idx - info->b->top;
			op_list[1] = idx + 1;
			get_index_of_a(info->a, info->b->arr[idx], &op_list[2]);
			ft_printf("%d\n", op_list[0]);
			ft_printf("%d\n", op_list[1]);
			ft_printf("%d\n", op_list[2]);
			ft_printf("%d\n", op_list[3]);
			ft_printf("%d\n", op_list[4]);
			ft_printf("%d\n", op_list[5]);
			compare_op_list(before_op_list, op_list);
			idx--;
		}
	}
	idx = 0;
	if (before_op_list[0] > 0)
	{
		idx = 0;
		while (idx < before_op_list[0])
		{
			rotate(0, 'a', info);
			idx++;
		}
	}
	if (before_op_list[1] > 0)
	{
		idx = 0;
		while (idx < before_op_list[1])
		{
			rotate(1, 'a', info);
			idx++;
		}
	}
	if (before_op_list[2] > 0)
	{
		idx = 0;
		while (idx < before_op_list[2])
		{
			rotate(0, 'b', info);
			idx++;
		}
	}
	if (before_op_list[3] > 0)
	{
		idx = 0;
		while (idx < before_op_list[3])
		{
			rotate(1, 'b', info);
			idx++;
		}
	}
	push('a', info);
	if (before_op_list[4] > 0)
	{
		idx = 0;
		while (idx < before_op_list[4])
		{
			rotate(0, 'a', info);
			idx++;
		}
	}
	if (before_op_list[5] > 0)
	{
		idx = 0;
		while (idx < before_op_list[5])
		{
			rotate(1, 'a', info);
			idx++;
		}
	}
}
