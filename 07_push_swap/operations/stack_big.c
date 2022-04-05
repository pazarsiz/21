/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_big.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbungo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:04:56 by wbungo            #+#    #+#             */
/*   Updated: 2022/03/04 13:08:09 by wbungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

int	is_sorted_big(t_stack *x)
{
	int	i;

	i = x->count - 1;
	if (x->size < 2)
	{
		exit(EXIT_SUCCESS);
	}
	while (i > 0)
	{
		if (x->arr[i] > x->arr[i - 1])
		{
			return (0);
		}
		i--;
	}
	return (1);
}

/*
void	show_stack(t_stack *x)
{
		int	i;

		i = x->count - 1;
		while ( i >= 0)
		{
				printf("show_x->arr[%d]=%ld\n", i, x->arr[i]);
				i--;
		}
}
*/
