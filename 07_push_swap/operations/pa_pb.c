/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbungo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:49:46 by wbungo            #+#    #+#             */
/*   Updated: 2022/03/04 12:56:13 by wbungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

int	push(long int n, t_stack *x, int flag)
{
	if (x->count <= x->size - 1)
	{
		x->arr[x->count] = n;
		x->count++;
	}
	else
	{
		if (flag)
			ft_putstr_fd("Error: x->count out of x->size\n", 2);
		return (2);
	}
	return (0);
}

int	pop(t_stack *x, int flag)
{
	if (x->count == 0)
	{
		if (flag)
			ft_putstr_fd("Error: pop_x->count = 0\n", 2);
		return (-1);
	}
	x->count--;
	return (0);
}

int	top(t_stack *x, int flag)
{
	if (x->count == 0)
	{
		if (flag)
			ft_putstr_fd("Error: top_x.count = 0\n", 2);
		return (-1);
	}
	return (x->arr[x->count - 1]);
}

int	pb(t_stack *a, t_stack *b, int flag)
{
	long int	tmp;

	tmp = top(a, flag);
	push(tmp, b, flag);
	pop(a, flag);
	if (flag)
		ft_putstr_fd("pb\n", 1);
	return (0);
}

int	pa(t_stack *a, t_stack *b, int flag)
{
	long int	tmp;

	tmp = top(b, flag);
	push(tmp, a, flag);
	pop(b, flag);
	if (flag)
		ft_putstr_fd("pa\n", 1);
	return (0);
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
