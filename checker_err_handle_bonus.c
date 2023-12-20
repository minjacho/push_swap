/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_err_handle_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:40:43 by minjacho          #+#    #+#             */
/*   Updated: 2023/12/20 17:17:58 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_double_ptr(char **lists)
{
	int	idx;

	idx = 0;
	while (lists[idx])
	{
		free(lists[idx]);
		idx++;
	}
	free(lists);
}

void	free_triple_ptr(char ***ptr, int size)
{
	int	idx;

	idx = 0;
	while (idx < size)
	{
		free_double_ptr(ptr[idx]);
		idx++;
	}
	free(ptr);
}

int	is_correct_input(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			if (!(str[i] == ' ' || str[i] == '-'))
				return (0);
		i++;
	}
	return (1);
}

int	check_dup(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->size)
	{
		j = i + 1;
		while (j < info->size)
		{
			if (info->origin[i] == info->origin[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	exit_failure(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
