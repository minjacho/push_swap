/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_optimize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:12:50 by minjacho          #+#    #+#             */
/*   Updated: 2023/12/20 16:55:56 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_paral(t_info *info, t_greedy *best)
{
	while (best->a_rotate > 0 && best->b_rotate > 0)
	{
		rotate(0, 'r', info);
		best->a_rotate--;
		best->b_rotate--;
	}
	while (best->a_rotate < 0 && best->b_rotate < 0)
	{
		rotate(1, 'r', info);
		best->a_rotate++;
		best->b_rotate++;
	}
}

void	rotate_swap(int reverse, char which, t_info *info)
{
	rotate(reverse, which, info);
	swap(which, info);
}
