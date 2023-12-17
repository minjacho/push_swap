/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:16:50 by minjacho          #+#    #+#             */
/*   Updated: 2023/12/17 20:43:44 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_leak(void)
{
	system("leaks push_swap");
}

int	*sort_naive(int **arr, int size)
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
			if((*arr)[j] > (*arr)[j + 1])
			{
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

void	set_pivot(t_info *info)
{
	int	*sorted;
	int	i;

	sorted = (int *)malloc(sizeof(int) * info->size);
	if (!sorted)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < info->size)
	{
		sorted[i] = info->origin[i];
		i++;
	}
	sorted = sort_naive(&sorted, info->size);
	info->pivot1 = sorted[info->size / 3];
	info->pivot2 = sorted[info->size * 2 / 3];
	free(sorted);
}

int main(int argc, char *argv[])
{
	t_info	info;

	// atexit(check_leak);
	init_origin(argc, argv, &info);
	init_stack(&info);
	info.op_list = NULL;
	// print_stack(&info);
	set_pivot(&info);
	ft_printf("%d\t%d\n", info.pivot1, info.pivot2);
	divide_pivot(&info);
	// print_stack(&info);
	greedy(&info);
	exit(EXIT_SUCCESS);
}
