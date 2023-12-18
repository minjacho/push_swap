/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:16:50 by minjacho          #+#    #+#             */
/*   Updated: 2023/12/18 19:41:04 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_leak(void)
{
	system("leaks push_swap");
}

int	*sort_naive(int **arr, int size, int *sorted)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	while (i++ < size - 1)
	{
		j = 0;
		while (j < size - 1)
		{
			if((*arr)[j] < (*arr)[j + 1])
			{
				*sorted = 0;
				tmp = (*arr)[j];
				(*arr)[j] = (*arr)[j + 1];
				(*arr)[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (*arr);
}

int	set_pivot(t_info *info)
{
	int	*sorted_arr;
	int	i;
	int	sorted;

	sorted = 1;
	sorted_arr = (int *)malloc(sizeof(int) * info->size);
	if (!sorted_arr)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < info->size)
	{
		sorted_arr[i] = info->origin[i];
		i++;
	}
	sorted_arr = sort_naive(&sorted_arr, info->size, &sorted);
	info->pivot2 = sorted_arr[info->size / 3];
	info->pivot1 = sorted_arr[info->size * 2 / 3];
	info->max = sorted_arr[0];
	info->min = sorted_arr[info->size - 1];
	free(sorted_arr);
	return (sorted);
}

void	rotate_sorted(t_info *info)
{
	int	idx;
	int	r_i;

	idx = 0;
	r_i = 0;
	while (info->a->arr[idx] != info->min)
		idx++;
	ft_printf("%d\n", idx);
	if (idx + 1 > info->a->top - idx)
	{
		while (r_i < info->a->top - idx)
		{
			rotate(0, 'a', info);
			r_i++;
		}
	}
	else
	{
		while (r_i < idx + 1)
		{
			rotate(1, 'a', info);
			r_i++;
		}
	}

}

int main(int argc, char *argv[])
{
	t_info	info;

	// atexit(check_leak);
	init_origin(argc, argv, &info);
	init_stack(&info);
	info.op_list = NULL;
	// print_stack(&info);
	if (set_pivot(&info))
		exit(EXIT_SUCCESS);
	divide_pivot(&info);
	// // print_stack(&info);
	while (info.b->top > -1)
		greedy(&info);
	rotate_sorted(&info);
	// print_stack(&info);
	// exit(EXIT_SUCCESS);
}
