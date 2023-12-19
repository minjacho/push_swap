/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operate_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 12:18:34 by minjacho          #+#    #+#             */
/*   Updated: 2023/12/19 18:24:44 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	do_op_by_input(t_info *info)
{
	char	*input;

	input = get_next_line(STDIN_FILENO);
	while (input)
	{
		ft_printf("%s", input);
		if (ft_strncmp(input, "sa", 2) == 0 && ft_strlen(input) == 3)
			swap('a', info);
		else if (ft_strncmp(input, "sb", 2) == 0 && ft_strlen(input) == 3)
			swap('b', info);
		else if (ft_strncmp(input, "ss", 2) == 0 && ft_strlen(input) == 3)
			swap('c', info);
		else if (ft_strncmp(input, "pa", 2) == 0 && ft_strlen(input) == 3)
			push('a', info);
		else if (ft_strncmp(input, "pb", 2) == 0 && ft_strlen(input) == 3)
			push('b', info);
		else if (ft_strncmp(input, "ra", 2) == 0 && ft_strlen(input) == 3)
			rotate(0, 'a', info);
		else if (ft_strncmp(input, "rb", 2) == 0 && ft_strlen(input) == 3)
			rotate(0, 'b', info);
		else if (ft_strncmp(input, "rr", 2) == 0 && ft_strlen(input) == 3)
			rotate(0, 'c', info);
		else if (ft_strncmp(input, "rra", 3) == 0 && ft_strlen(input) == 4)
			rotate(1, 'a', info);
		else if (ft_strncmp(input, "rrb", 3) == 0 && ft_strlen(input) == 4)
			rotate(1, 'b', info);
		else if (ft_strncmp(input, "rrr", 4) == 0 && ft_strlen(input) == 4)
			rotate(1, 'c', info);
		else
			exit_failure();
		free(input);
		input = get_next_line(STDIN_FILENO);
		ft_printf("%s", input);
	}
}
