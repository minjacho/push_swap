/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:40:43 by minjacho          #+#    #+#             */
/*   Updated: 2023/12/17 12:05:18 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
