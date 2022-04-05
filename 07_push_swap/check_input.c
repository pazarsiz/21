/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbungo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:59:50 by wbungo            #+#    #+#             */
/*   Updated: 2022/03/01 16:49:18 by wbungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

void	check_dup_digit(int size, long int *arr)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (j == i)
				j++;
			else if (arr[i] == arr[j])
			{
				free(arr);
				ft_exit_failure(2);
			}
			else
				j++;
		}
		i++;
	}
}

void	check_isdigit(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) && !ft_issign(av[i][j + 1]))
			{
				if (ft_issign(av[i][j]))
				{
					if (!ft_isdigit(av[i][j + 1]))
						ft_exit_failure(2);
				}
				j++;
			}
			else
				ft_exit_failure(2);
		}
		i++;
	}
}

void	check_overflow(long int integer)
{
	if (integer < INT_MIN || integer > INT_MAX)
		ft_exit_failure(2);
}

long int	*check_input(int size, char **av)
{
	int			i;
	long int	*arr;

	i = 0;
	check_isdigit(av);
	arr = malloc(sizeof(arr) * (size));
	while (i < size)
	{
		arr[i] = ft_atoi(av[i + 1]);
		check_overflow(arr[i]);
		i++;
	}
	check_dup_digit(size, arr);
	return (arr);
}
