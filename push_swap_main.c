/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:16:50 by minjacho          #+#    #+#             */
/*   Updated: 2023/12/15 20:42:44 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int main(int argc, char *argv[])
{
	t_info	info;
	char	**str_nums;
	int		idx;

	(void)argc;

	str_nums = ft_split(argv[1], ' ');
	idx = 0;
	if (!str_nums)
		exit(EXIT_FAILURE);
	while (str_nums[idx])
		idx++;
	info.origin = (int *)malloc(idx * sizeof(int));
	if (!info.origin)
		exit(EXIT_FAILURE);
	info.a = (t_stack *)malloc(sizeof(t_stack));
	info.b = (t_stack *)malloc(sizeof(t_stack));
	info.a->arr = (int *)malloc(sizeof(int) * idx);
	info.b->arr = (int *)malloc(sizeof(int) * idx);
	info.a->top = -1;
	info.b->top = -1;
	info.a->size = idx;
	info.b->size = idx;
	idx = 0;
	ft_printf("%p %p\n", info.a->arr, info.b->arr);
	while (str_nums[idx])
	{
		info.a->arr[idx] = ft_atoi(str_nums[idx]);
		info.a->top++;
		info.b->arr[idx] = 0;
		info.origin[idx] = ft_atoi(str_nums[idx]);
		idx++;
	}
	for (idx = 0; str_nums[idx]; idx++)
	{
		ft_printf("%d	%d	%s\n", info.a->arr[idx], info.b->arr[idx], str_nums[idx]);
	}
	ft_printf("top : %d size : %d\n", info.a->top, info.a->size);
}
