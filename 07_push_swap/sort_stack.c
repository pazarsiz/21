/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbungo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 12:07:26 by wbungo            #+#    #+#             */
/*   Updated: 2022/03/04 10:39:30 by wbungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

int	sort_stacks(int size, long int *arr)
{
	t_stack		a;
	t_stack		b;
	long int	*prime;

	prime = simplify_array(size, arr);
	a.arr = prime;
	a.size = size;
	a.count = a.size;
	if (is_sorted_big(&a))
		exit(EXIT_SUCCESS);
	b.arr = malloc(sizeof(*arr) * size);
	b.size = size;
	b.count = 0;
	if (!is_sorted_big(&a))
		sort_start(&a, &b);
	free(b.arr);
	free(a.arr);
	return (0);
}

int	sort_start(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort_two(a);
	if (a->size == 3)
		sort_three(a);
	if (a->size <= 60 && a->size > 3)
		sort_five(a, b);
	if (a->size >= 61)
		sort_big(a, b);
	return (0);
}

int	sort_two(t_stack *x)
{
	int	i;

	i = x->count - 1;
	if (x->arr[i] > x->arr[i - 1])
		sa(x, 1);
	return (0);
}
