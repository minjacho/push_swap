/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 12:03:49 by minjacho          #+#    #+#             */
/*   Updated: 2023/12/17 17:01:04 by minjacho         ###   ########.fr       */
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
		exit(EXIT_FAILURE);
	idx = 0;
	info->size = 0;
	while (idx < argc - 1)
	{
		str_num_list[idx] = ft_split(argv[idx + 1], ' ');
		if (!str_num_list[idx])
			exit(EXIT_FAILURE);
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
		exit(EXIT_FAILURE);
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
		info->origin[origin_idx] = ft_atoi(str_num_list[idx][sub_idx]);
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
		exit(EXIT_FAILURE);
	info->b = (t_stack *)malloc(sizeof(t_stack));
	if (!info->b)
		exit(EXIT_FAILURE);
	info->a->arr = (int *)malloc(sizeof(int) * info->size);
	if (!info->a->arr)
		exit(EXIT_FAILURE);
	info->b->arr = (int *)malloc(sizeof(int) * info->size);
	if (!info->b->arr)
		exit(EXIT_FAILURE);
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
