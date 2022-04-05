/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbungo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:57:03 by wbungo            #+#    #+#             */
/*   Updated: 2022/03/04 10:43:18 by wbungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

long int	get_smallest(t_stack *x)
{
	int			i;
	long int	smallest;

	i = 0;
	smallest = x->arr[0];
	while (i < x->count)
	{
		if (x->arr[i] < smallest)
		{
			smallest = x->arr[i];
		}
		i++;
	}
	return (smallest);
}

int	get_border(t_stack *x)
{
	int	min_to_bottom;
	int	border_index;

	min_to_bottom = (x->count / 2);
	border_index = min_to_bottom;
	return (border_index);
}

int	rotate_to_top(t_stack *x, long int smallest, int border)
{
	int	i;

	i = x->count - 1;
	while (i >= 0)
	{
		if (x->arr[i] == smallest)
		{
			if (i == x->count - 1 && x->arr[i] == smallest)
				return (0);
			else if (i >= border)
			{
				ra(x, 1);
				i += 2;
			}
			else
				rra(x, 1);
		}
		i--;
	}
	return (0);
}

int	push_smallest_to_b(t_stack *a, t_stack *b)
{
	int			border;
	long int	smallest;

	smallest = get_smallest(a);
	border = get_border(a);
	rotate_to_top(a, smallest, border);
	pb(a, b, 1);
	return (a->count);
}

int	sort_five(t_stack *a, t_stack *b)
{
	while (a->count > 3)
		push_smallest_to_b(a, b);
	sort_three(a);
	while (b->count > 0)
		pa(a, b, 1);
	return (0);
}
