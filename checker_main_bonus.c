/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:16:50 by minjacho          #+#    #+#             */
/*   Updated: 2023/12/20 13:34:41 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_sorted(t_info *info)
{
	int	i;
	int	prev;

	i = info->a->top;
	if (info->b->top != -1)
		return (1);
	while (i >= 0)
	{
		if (i != info->a->top && prev >= info->a->arr[i])
			return (1);
		prev = info->a->arr[i];
		i--;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_info	info;
	int		idx;

	idx = 1;
	while (idx < argc)
	{
		if (!is_correct_input(argv[idx]))
			exit_failure();
		idx++;
	}
	init_origin(argc, argv, &info);
	if (check_dup(&info))
		exit_failure();
	init_stack(&info);
	do_op_by_input(&info);
	if (check_sorted(&info))
	{
		write(1, "KO\n", 3);
		exit(EXIT_SUCCESS);
	}
	write(1, "OK\n", 3);
	exit(EXIT_SUCCESS);
}
