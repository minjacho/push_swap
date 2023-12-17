/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 12:44:04 by minjacho          #+#    #+#             */
/*   Updated: 2023/12/17 13:07:51 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_info *info)
{
	int	idx;

	idx = info->size - 1;
	while (idx >= 0)
	{
		if (idx > info->a->top)
			ft_printf("\t\t\t");
		else
			ft_printf("%d\t\t\t", info->a->arr[idx]);
		if (idx > info->b->top)
			ft_printf("\t\t\t");
		else
			ft_printf("%d\t\t\t", info->b->arr[idx]);
		ft_printf("\n");
		idx--;
	}
	ft_printf("___\t\t\t___\n");
	ft_printf(" a \t\t\t b \n\n");
}
