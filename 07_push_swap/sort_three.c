/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbungo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 12:11:54 by wbungo            #+#    #+#             */
/*   Updated: 2022/03/04 10:45:40 by wbungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

int	sort_three(t_stack *x)
{
	if (!is_sorted_big(x))
	{
		sort_three_123_132_231(x);
		if (is_sorted_big(x))
			return (0);
		else
			sort_three_321_213_312(x);
	}
	return (0);
}

int	sort_three_123_132_231(t_stack *x)
{
	int	i;

	i = x->count - 1;
	if (x->arr[i] < x->arr[i - 1])
	{
		if (x->arr[i - 1] < x->arr[i - 2])
			return (0);
		else if (x->arr[i] < x->arr[i - 2])
		{
			sa(x, 1);
			ra(x, 1);
		}
		else
			rra(x, 1);
		return (0);
	}
	return (0);
}

int	sort_three_321_213_312(t_stack *x)
{
	int	i;

	i = x->count - 1;
	if (x->arr[i] > x->arr[i - 1])
	{
		if (x->arr[i - 1] > x->arr[i - 2])
		{
			ra(x, 1);
			sa(x, 1);
		}
		else if (x->arr[i] < x->arr[i - 2])
			sa(x, 1);
		else
			ra(x, 1);
	}
	return (0);
}
