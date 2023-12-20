/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 12:03:49 by minjacho          #+#    #+#             */
/*   Updated: 2023/12/20 17:16:07 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	***split_argv(int argc, char *argv[], t_info *info)
{
	char	***str_num_list;
	int		idx;
	int		sub_idx;

	str_num_list = (char ***)malloc(sizeof(char **) * argc - 1);
	if (!str_num_list)
		exit_failure();
	idx = 0;
	info->size = 0;
	while (idx < argc - 1)
	{
		str_num_list[idx] = ft_split(argv[idx + 1], ' ');
		if (!str_num_list[idx])
			exit_failure();
		sub_idx = 0;
		while (str_num_list[idx][sub_idx])
			sub_idx++;
		info->size += sub_idx;
		idx++;
	}
	return (str_num_list);
}

void	init_origin(int argc, char *argv[], t_info *info)
{
	char	***str_num_list;
	int		idx;
	int		sub_idx;
	int		origin_idx;

	str_num_list = split_argv(argc, argv, info);
	info->origin = (int *)malloc(sizeof(int) * info->size);
	if (!info->origin)
		exit_failure();
	origin_idx = info->size - 1;
	idx = 0;
	sub_idx = 0;
	while (origin_idx >= 0)
	{
		if (!str_num_list[idx][sub_idx])
		{
			idx++;
			sub_idx = 0;
		}
		info->origin[origin_idx] = \
			check_overflow(ft_atol(str_num_list[idx][sub_idx]));
		sub_idx++;
		origin_idx--;
	}
	free_triple_ptr(str_num_list, argc - 1);
}

void	init_stack(t_info *info)
{
	int	idx;

	info->a = (t_stack *)malloc(sizeof(t_stack));
	if (!info->a)
		exit_failure();
	info->b = (t_stack *)malloc(sizeof(t_stack));
	if (!info->b)
		exit_failure();
	info->a->arr = (int *)malloc(sizeof(int) * info->size);
	if (!info->a->arr)
		exit_failure();
	info->b->arr = (int *)malloc(sizeof(int) * info->size);
	if (!info->b->arr)
		exit_failure();
	info->a->top = -1;
	info->b->top = -1;
	info->a->size = info->size;
	info->b->size = info->size;
	idx = 0;
	while (idx < info->size)
	{
		info->a->arr[idx] = info->origin[idx];
		info->a->top++;
		idx++;
	}
}
