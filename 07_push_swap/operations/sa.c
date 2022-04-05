/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbungo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:01:23 by wbungo            #+#    #+#             */
/*   Updated: 2022/03/04 13:02:30 by wbungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

int	sa(t_stack *x, int flag)
{
	int			i;
	long int	tmp;

	i = x->count - 1;
	tmp = x->arr[i];
	x->arr[i] = x->arr[i - 1];
	x->arr[i - 1] = tmp;
	if (flag)
		ft_putstr_fd("sa\n", 1);
	return (0);
}
