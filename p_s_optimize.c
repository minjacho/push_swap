/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_optimize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:12:50 by minjacho          #+#    #+#             */
/*   Updated: 2023/12/18 20:23:05 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_paral(t_info *info, t_greedy *best)
{
	while (best->a_rotate > 0 && best->b_rotate > 0)
	{
		ft_printf("rr\n");
		sub_rotate(0, info->a);
		sub_rotate(0, info->b);
		best->a_rotate--;
		best->b_rotate--;
	}
	while (best->a_rotate < 0 && best->b_rotate < 0)
	{
		ft_printf("rrr\n");
		sub_rotate(1, info->a);
		sub_rotate(1, info->b);
		best->a_rotate++;
		best->b_rotate++;
	}
}
