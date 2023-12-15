/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:08:44 by minjacho          #+#    #+#             */
/*   Updated: 2023/12/15 15:38:04 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

 # include <stdlib.h>
 # include "libft.h"
typedef struct	s_stack
{
	int	*arr;
	int	size;
	int	top;
}	t_stack;

typedef struct	s_info
{
	t_stack	*a;
	t_stack	*b;
	int		*origin;
}	t_info;

#endif
