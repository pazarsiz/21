/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbungo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:37:17 by wbungo            #+#    #+#             */
/*   Updated: 2022/03/04 10:44:34 by wbungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

int	sort_big(t_stack *a, t_stack *b)
{
	int			i;
	int			j;
	int			checker;

	i = 0;
	j = 0;
	while (!is_sorted_big(a))
	{
		while (j < a->size)
		{
			checker = (a->arr[a->count - 1] >> i) & 1;
			if (checker == 1)
				ra(a, 1);
			else
				pb(a, b, 1);
			j++;
		}
		while (b->count > 0)
			pa(a, b, 1);
		i++;
		j = 0;
	}
	return (0);
}
