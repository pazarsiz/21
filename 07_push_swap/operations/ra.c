/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbungo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:57:48 by wbungo            #+#    #+#             */
/*   Updated: 2022/03/04 12:59:11 by wbungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

int	ra(t_stack *x, int flag)
{
	int			i;
	long int	tmp;

	i = x->count - 1;
	if (x->count > 1)
	{
		tmp = x->arr[x->count - 1];
		while (i > 0)
		{
			x->arr[i] = x->arr[i - 1];
			i--;
		}
		x->arr[0] = tmp;
		if (flag)
			ft_putstr_fd("ra\n", 1);
	}
	return (0);
}
