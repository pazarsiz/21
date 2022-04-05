/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplify_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbungo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:23:08 by wbungo            #+#    #+#             */
/*   Updated: 2022/03/02 11:37:05 by wbungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

long int	*reverse_prime(long int *prime, int size)
{
	int			i;
	long int	tmp;

	i = 0;
	while (i <= (size - 1) / 2)
	{
		tmp = prime[i];
		prime[i] = prime[size - 1 - i];
		prime[size - 1 - i] = tmp;
		i++;
	}
	return (prime);
}

long int	*simplify_array(int size, long int *arr)
{
	int			i;
	long int	temp;
	long int	*tmp;

	i = -1;
	temp = 0;
	tmp = malloc(sizeof(*tmp) * (size));
	while (i++ < size)
		tmp[i] = arr[i];
	i = 0;
	while (i < size - 1)
	{
		if (tmp[i] < tmp[i + 1])
			i++;
		else
		{
			temp = tmp[i];
			tmp[i] = tmp[i + 1];
			tmp[i + 1] = temp;
			i = 0;
		}
	}
	return (turn_to_primes(size, arr, tmp));
}

long int	*turn_to_primes(int size, long int *arr, long int *tmp)
{
	int			i;
	int			j;
	long int	*prime;

	i = 0;
	j = 0;
	prime = malloc(sizeof(*prime) * (size));
	while (i < size)
	{
		while (j < size)
		{
			if (arr[i] == tmp[j])
			{
				prime[i] = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
	free(tmp);
	return (reverse_prime(prime, size));
}
