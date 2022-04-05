/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbungo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:00:15 by wbungo            #+#    #+#             */
/*   Updated: 2022/03/04 13:00:49 by wbungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

int	rra(t_stack *x, int flag)
{
	int			i;
	long int	tmp;

	i = 0;
	tmp = x->arr[i];
	while (i < x->count - 1)
	{
		x->arr[i] = x->arr[i + 1];
		i++;
	}
	x->arr[i] = tmp;
	if (flag)
		ft_putstr_fd("rra\n", 1);
	return (0);
}
